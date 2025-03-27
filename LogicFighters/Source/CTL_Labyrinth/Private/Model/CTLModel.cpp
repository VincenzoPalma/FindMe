#include "../Public/Model/CTLModel.h"
#include "Model/CTL_ModelChecking/CTLFormula.h"

UCTLModel::UCTLModel()
    : rootNode(nullptr)
{
}

void UCTLModel::PostInitProperties()
{
    Super::PostInitProperties();

    PredicateManager = NewObject<UPredicateManager>(this);

}

void UCTLModel::AddState(const FState& state)
{
    if (!stateNodes.Contains(state.Id))
    {
        UStateNode* NewNode = NewObject<UStateNode>();
        NewNode->SetStateData(state);

        stateNodes.Add(state.Id, NewNode);

        if (!rootNode)
        {
            rootNode = NewNode;
        }
    }
}

void UCTLModel::AddTransition(FActionsArray actions, UStateNode* FromNode, UStateNode* ToNode)
{
    if (FromNode && ToNode)
    {
        FromNode->AddChild(actions, ToNode);
    }
}


void UCTLModel::AddFormula(int32 FormulaId, UCTLFormula* Formula)
{
    if (Formula && !Formulas.Contains(FormulaId))
    {
        Formulas.Add(FormulaId, Formula);
    }
}

void UCTLModel::InitializeModel(const FString& Character1Class, const FString& Character2Class)
{
    //Opens JSON file
    FString JsonFileName = Character1Class + TEXT("_") + Character2Class + TEXT("_") + TEXT("gameplay") + TEXT(".json");
    FString JsonFilePath = FPaths::ProjectContentDir() / TEXT("ModelFiles") / JsonFileName;

    FString JsonString;
    if (!FFileHelper::LoadFileToString(JsonString, *JsonFilePath))
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to load JSON file: %s"), *JsonFilePath);
        return;
    }
    UE_LOG(LogTemp, Log, TEXT("Successfully loaded JSON file: %s"), *JsonFilePath);

    TSharedPtr<FJsonObject> JsonObject;
    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonString);
    if (!FJsonSerializer::Deserialize(Reader, JsonObject) || !JsonObject.IsValid())
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to parse JSON file"));
        return;
    }

    JsonFile = JsonObject;

    //Creates formulas
    /*PropertyNames = {
            TEXT("PlayerHealthPoints"), TEXT("PlayerAbilityPoints"), TEXT("PlayerDefenseAvailable"), TEXT("PlayerCounterAvailable"), TEXT("PlayerBuffTurns"),
            TEXT("AIHealthPoints"), TEXT("AIAbilityPoints"), TEXT("AIDefenseAvailable"), TEXT("AICounterAvailable"), TEXT("AIBuffTurns")
        };*/

    /*
    similmente per ability points
    formule che considerano la disponibilità delle abilità (difesa, counterattck)
    */

    //AG(AIHealthPoints > (AIHealthPoints - x))
    UAtomicIntFormula* AIHealthAtomic = NewObject<UAtomicIntFormula>();
    AIHealthAtomic->Initialize([](const FState& State) 
        { 
            int32 AIHealthPoints = State.Properties.Find("AIHealthPoints")->IntValue;
            return AIHealthPoints > AIHealthPoints - 10; 
        });

    Formulas.Add(0, AIHealthAtomic);
    UUnaryFormula* AIHealthAG = NewObject<UUnaryFormula>();
    AIHealthAG->Initialize(ECTLOperator::AG, AIHealthAtomic);

    //AG(PlayerHealthPoints < (PlayerHealthPoints - x))
    UAtomicIntFormula* PlayerHealthAtomic = NewObject<UAtomicIntFormula>();
    PlayerHealthAtomic->Initialize([](const FState& State)
        {
            int32 PlayerHealthPoints = State.Properties.Find("PlayerHealthPoints")->IntValue;
            return PlayerHealthPoints < PlayerHealthPoints - 10;
        });

    Formulas.Add(0, PlayerHealthAtomic);
    UUnaryFormula* PlayerHealthAG = NewObject<UUnaryFormula>();
    PlayerHealthAG->Initialize(ECTLOperator::AG, PlayerHealthAtomic);

    //AG(AIAbilityPoints > (AIAbilityPoints - x))
    UAtomicIntFormula* AIAbilityAtomic = NewObject<UAtomicIntFormula>();
    AIAbilityAtomic->Initialize([](const FState& State)
        {
            int32 AIAbilityPoints = State.Properties.Find("AIAbilityPoints")->IntValue;
            return AIAbilityPoints > AIAbilityPoints - 3;
        });

    Formulas.Add(0, AIAbilityAtomic);
    UUnaryFormula* AIAbilityAG = NewObject<UUnaryFormula>();
    AIAbilityAG->Initialize(ECTLOperator::AG, AIAbilityAtomic);

    //AG(PlayerAbilityPoints > (PlayerAbilityPoints - x))
    UAtomicIntFormula* PlayerAbilityAtomic = NewObject<UAtomicIntFormula>();
    PlayerAbilityAtomic->Initialize([](const FState& State)
        {
            int32 PlayerAbilityPoints = State.Properties.Find("PlayerAbilityPoints")->IntValue;
            return PlayerAbilityPoints > PlayerAbilityPoints - 3;
        });

    Formulas.Add(0, PlayerAbilityAtomic);
    UUnaryFormula* PlayerAbilityAG = NewObject<UUnaryFormula>();
    PlayerAbilityAG->Initialize(ECTLOperator::AG, PlayerAbilityAtomic);


}

TSharedPtr<FJsonObject> UCTLModel::GetJsonFile()
{
    return JsonFile;
}

UCTLFormula* UCTLModel::GetFormula(int32 Id) const
{
    const UCTLFormula* const* FoundFormula = Formulas.Find(Id);
    if (FoundFormula)
    {
        return const_cast<UCTLFormula*>(*FoundFormula);
    }
    return nullptr;
}

TArray<UStateNode*> UCTLModel::PreImageExistential(const TArray<UStateNode*>& states, UStateNode* StartNode) const
{
    TArray<UStateNode*> PreImage;

    if (!StartNode)
    {
        UE_LOG(LogTemp, Error, TEXT("Invalid StartNode passed to PreImageExistential"));
        return PreImage;
    }

    TArray<UStateNode*> ReachableStates = GetReachableNodes(StartNode);

    for (UStateNode* StateNode : ReachableStates)
    {

        bool HasSuccessorInQ = false;
        for (UStateNode* Successor : StateNode->GetChildren())
        {
            if (states.Contains(Successor))
            {
                HasSuccessorInQ = true;
                break;
            }
        }

        if (HasSuccessorInQ)
        {
            PreImage.Add(StateNode);
        }
    }

    return PreImage;
}

TArray<UStateNode*> UCTLModel::PreImageUniversal(const TArray<UStateNode*>& states, UStateNode* StartNode) const
{
    TArray<UStateNode*> PreImage;

    if (!StartNode)
    {
        UE_LOG(LogTemp, Error, TEXT("Invalid StartNode passed to PreImageUniversal"));
        return PreImage;
    }

    TArray<UStateNode*> ReachableStates = GetReachableNodes(StartNode);

    for (UStateNode* StateNode : ReachableStates)
    {
        bool AllSuccessorsInQ = true;
        TArray<UStateNode*> Successors = StateNode->GetChildren();

        if (Successors.Num() == 0)
        {
            AllSuccessorsInQ = false;
        }
        else
        {
            for (UStateNode* Successor : Successors)
            {
                if (!states.Contains(Successor))
                {
                    AllSuccessorsInQ = false;
                    break;
                }
            }
        }

        if (AllSuccessorsInQ)
        {
            PreImage.Add(StateNode);
        }
    }

    return PreImage;
}



TArray<UStateNode*> UCTLModel::GetReachableNodes(UStateNode* StartNode) const
{
    TArray<UStateNode*> ReachableNodes;

    if (!StartNode)
    {
        UE_LOG(LogTemp, Warning, TEXT("StartNode is null."));
        return ReachableNodes;
    }

    TQueue<UStateNode*> Queue;
    Queue.Enqueue(StartNode);

    TSet<UStateNode*> Visited;

    while (!Queue.IsEmpty())
    {
        UStateNode* CurrentNode;
        Queue.Dequeue(CurrentNode);

        if (Visited.Contains(CurrentNode))
        {
            continue;
        }

        Visited.Add(CurrentNode);
        ReachableNodes.Add(CurrentNode);

        for (UStateNode* Successor : CurrentNode->GetChildren())
        {
            if (!Visited.Contains(Successor))
            {
                Queue.Enqueue(Successor);
            }
        }
    }

    return ReachableNodes;
}

void UCTLModel::DebugPrintModel() const
{
    if (GEngine)
    {
        for (const TPair<FString, UStateNode*>& NodePair : stateNodes)
        {
            UStateNode* CurrentNode = NodePair.Value;
            if (!CurrentNode)
            {
                UE_LOG(LogTemp, Warning, TEXT("Null node found in stateNodes."));
                continue;
            }

            // Print current node ID
            FString NodeMessage = FString::Printf(TEXT("Node ID: %s"), *CurrentNode->GetState().Id);
            UE_LOG(LogTemp, Log, TEXT("%s"), *NodeMessage);

            // Print properties of the current node
            /*for (const TPair<FString, FVariantValue>& PropertyPair : CurrentNode->GetStateData().Properties)
            {
                FString Key = PropertyPair.Key;
                FString ValueString = PropertyPair.Value.ToString();
                UE_LOG(LogTemp, Log, TEXT("  Property: %s = %s"), *Key, *ValueString);
            }*/

            // Print adjacent nodes
            UE_LOG(LogTemp, Log, TEXT("  Adjacent Nodes:"));
            TMap<FActionsArray, UStateNode*> Children = CurrentNode->GetChildrenMap();
            for (const TPair<FActionsArray, UStateNode*>& ChildPair : Children)
            {
                FString KeyString;
                for (const int32 Action : ChildPair.Key.Keys)
                {
                    KeyString += FString::Printf(TEXT("%d "), Action);
                }

                if (ChildPair.Value)
                {
                    UE_LOG(LogTemp, Log, TEXT("    Adjacent Node ID: %s"), *ChildPair.Value->GetState().Id);
                }
                else
                {
                    UE_LOG(LogTemp, Warning, TEXT("    Null adjacent node encountered."));
                }
                UE_LOG(LogTemp, Log, TEXT("    Actions: %s"), *KeyString);
            }
        }
    }
}


TArray<UStateNode*> UCTLModel::EvaluateFormula(UStateNode* node, UCTLFormula* formula)
{
    TArray<UStateNode*> result = AStar::ExecuteAStar(this, node, formula);
    this->rootNode = nullptr;
    this->stateNodes.Empty();
    return result;
}

void UCTLModel::UpdateModel(UStateNode* node, UCTLFormula* formula, TMap<FString, int32>& statesScores)
{
    UModelParser::UpdateModelFromState(node, this, 3);
    int subFormulasNum = formula->CountSubformulas();
    for (const UStateNode* currNode : GetReachableNodes(node))
    {
        statesScores.Add(currNode->GetState().Id, subFormulasNum);
    }
    TArray<UStateNode*> result = formula->Evaluate(this, node, statesScores);
}