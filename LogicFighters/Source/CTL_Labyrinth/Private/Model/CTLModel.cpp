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
        ToNode->AddParent(FromNode);
    }
}


void UCTLModel::AddFormula(int32 FormulaId, UCTLFormula* Formula)
{
    if (Formula && !Formulas.Contains(FormulaId))
    {
        Formulas.Add(FormulaId, Formula);
    }
}

void UCTLModel::InitializeModel(const FString& Character1Class, const FString& Character2Class, const TMap<ECharacterActions, float> ActionRates)
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

    //AG(CurrentAIHealthPoints - AIHealthPoints < x)
    UAtomicIntFormula* AIHealthAtomicLeft = NewObject<UAtomicIntFormula>();
    AIHealthAtomicLeft->Initialize([](const FState& State, const FState& CurrentState)
        { 
            int32 CurrentAIHealthPoints = State.Properties.Find("AIHealthPoints")->IntValue;
            int32 StartingAIHealthPoints = CurrentState.Properties.Find("AIHealthPoints")->IntValue;
            return StartingAIHealthPoints - CurrentAIHealthPoints >= 0;
        });

    UAtomicIntFormula* AIHealthAtomicRight = NewObject<UAtomicIntFormula>();
    AIHealthAtomicRight->Initialize([](const FState& State, const FState& CurrentState)
        {
            int32 CurrentAIHealthPoints = State.Properties.Find("AIHealthPoints")->IntValue;
            int32 StartingAIHealthPoints = CurrentState.Properties.Find("AIHealthPoints")->IntValue;
            return StartingAIHealthPoints - CurrentAIHealthPoints <= 20;
        });

    UBinaryFormula* AIHealthAND = NewObject<UBinaryFormula>();
    AIHealthAND->Initialize(ECTLOperator::AND, AIHealthAtomicLeft, AIHealthAtomicRight);
    UUnaryFormula* AIHealthAG = NewObject<UUnaryFormula>();
    AIHealthAG->Initialize(ECTLOperator::EG, AIHealthAND);
    Formulas.Add(0, AIHealthAG);

    //AG(CurrentPlayerHealthPoints - PlayerHealthPoints < x)
    UAtomicIntFormula* PlayerHealthAtomic = NewObject<UAtomicIntFormula>();
    PlayerHealthAtomic->Initialize([](const FState& State, const FState& CurrentState)
        {
            int32 PlayerHealthPoints = State.Properties.Find("PlayerHealthPoints")->IntValue;
            int32 CurrentPlayerHealthPoints = State.Properties.Find("PlayerHealthPoints")->IntValue;
            return CurrentPlayerHealthPoints - PlayerHealthPoints > 10;
        });

    UUnaryFormula* PlayerHealthAG = NewObject<UUnaryFormula>();
    PlayerHealthAG->Initialize(ECTLOperator::AG, PlayerHealthAtomic);
    Formulas.Add(1, PlayerHealthAG);

    //AG(AIAbilityPoints - CurrentAIAbilityPoints > x)
    UAtomicIntFormula* AIAbilityAtomic = NewObject<UAtomicIntFormula>();
    AIAbilityAtomic->Initialize([](const FState& State, const FState& CurrentState)
        {
            int32 AIAbilityPoints = State.Properties.Find("AIAbilityPoints")->IntValue;
            int32 CurrentAIAbilityPoints = State.Properties.Find("AIAbilityPoints")->IntValue;
            return AIAbilityPoints - CurrentAIAbilityPoints > 0;
        });

    UUnaryFormula* AIAbilityAG = NewObject<UUnaryFormula>();
    AIAbilityAG->Initialize(ECTLOperator::AG, AIAbilityAtomic);
    Formulas.Add(2, AIAbilityAG);

    //AG(CurrentAIAbilityPoints - AIAbilityPoints > x)
    UAtomicIntFormula* PlayerAbilityAtomic = NewObject<UAtomicIntFormula>();
    PlayerAbilityAtomic->Initialize([](const FState& State, const FState& CurrentState)
        {
            int32 PlayerAbilityPoints = State.Properties.Find("PlayerAbilityPoints")->IntValue;
            int32 CurrentPlayerAbilityPoints = State.Properties.Find("PlayerAbilityPoints")->IntValue;
            return CurrentPlayerAbilityPoints - PlayerAbilityPoints > 0;
        });

    UUnaryFormula* PlayerAbilityAG = NewObject<UUnaryFormula>();
    PlayerAbilityAG->Initialize(ECTLOperator::AG, PlayerAbilityAtomic);
    Formulas.Add(3, PlayerAbilityAG);

    PlayerActionRates = ActionRates;
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

TArray<UStateNode*> UCTLModel::PreImageExistential(const TArray<UStateNode*>& states, TArray<UStateNode*>& targetStates) const
{
    TSet<UStateNode*> PreImage;

    for (UStateNode* StateNode : states)
        PreImage.Append(StateNode->GetParents());

    targetStates = states;

    return PreImage.Array();
}

TArray<UStateNode*> UCTLModel::PreImageUniversal(const TArray<UStateNode*>& states, TArray<UStateNode*>& targetStates) const
{
    TSet<UStateNode*> PreImage;

    for (UStateNode* StateNode : states)
    {
        for (UStateNode* parents : StateNode->GetParents())
        {
            TArray<UStateNode*> Successors = parents->GetChildren();
            bool AllSuccessorsInQ = true;

            for (UStateNode* Successor : Successors)
            {
                if (!states.Contains(Successor))
                {
                    AllSuccessorsInQ = false;
                }
            }

            if(AllSuccessorsInQ)
            {
                targetStates.Add(StateNode);
                PreImage.Add(StateNode);
            }
        }
    }

    return PreImage.Array();
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
            for (const UStateNode* Parent : CurrentNode->GetParents())
            {
                FString KeyString;

                if (Parent)
                {
                    UE_LOG(LogTemp, Log, TEXT("    Parent Node ID: %s"), *Parent->GetState().Id);
                }
                else
                {
                    UE_LOG(LogTemp, Warning, TEXT("    Null parent node encountered."));
                }
            }
        }
    }
}


TMap<FString, FActionsToNode> UCTLModel::EvaluateFormula(UStateNode* node, UCTLFormula* formula, bool ShortestPath)
{
    TMap<FString, FActionsToNode> result;
    if (ShortestPath)
        result = AStar::ExecuteAStar(this, node, formula);
    else
        result = AStar::ExecuteBFS(this, node, formula);

    this->rootNode = nullptr;
    this->stateNodes.Empty();
    return result;
}

void UCTLModel::UpdateModel(UStateNode* node, UCTLFormula* formula, TMap<FString, int32>& unsatScores, int32 depth, int32 MAX_UNSAT_SCORE)
{
    UModelParser::UpdateModelFromState(node, this, depth);
    int subFormulasNum = formula->CountSubformulas();
    int subFormulaWeight = MAX_UNSAT_SCORE / subFormulasNum;
    for (const UStateNode* currNode : GetReachableNodes(node))
    {
        unsatScores.Add(currNode->GetState().Id, MAX_UNSAT_SCORE);
    }
    //TArray<UStateNode*> result = formula->Evaluate(this, node, unsatScores, subFormulaWeight);
}

// This function returns a set of valid target nodes from the original targetStates set.
// A target node is considered valid if, for every node in its parent chain,
// all of that parent's children are contained in the targetStates set.
TArray<UStateNode*> UCTLModel::EvaluateUniversalG(TArray<UStateNode*>& targetStates, bool universalCheck) const
{
    TSet<UStateNode*> validTargets;

    // Process each target node individually.
    for (UStateNode* target : targetStates)
    {
        bool bIsValid = true;
        TQueue<UStateNode*> queue;
        TSet<UStateNode*> visited; // To avoid processing the same node more than once
        queue.Enqueue(target);
        visited.Add(target);

        // Process nodes in a FIFO order.
        while (!queue.IsEmpty() && bIsValid)
        {
            bool parentInTarget = false;
            bool bChildrenConditionMet = true;
            UStateNode* currentNode;
            queue.Dequeue(currentNode);

            // If currentNode has no parents in our map, it's a root; no further check is needed.
            if (currentNode->GetParents().IsEmpty())
                continue;

            // Iterate over each parent of the current node.
            for (UStateNode* parentNode : currentNode->GetParents())
            {
                //Ensure that the parent itself is in the targetStates set.
                if (!targetStates.Contains(parentNode))
                    continue;
                parentInTarget = true;

                // Check parent's children condition.
                if (universalCheck)
                {
                    // Every child of the parent must be in targetStates.
                    for (UStateNode* child : parentNode->GetChildren())
                    {
                        if (!targetStates.Contains(child))
                        {
                            bChildrenConditionMet = false;
                            break;
                        }
                    }
                }

                // If the condition on the parent's children is not met, mark as invalid.
                if (!bChildrenConditionMet)
                    continue;

                // Enqueue the parent for further processing if not already visited.
                if (!visited.Contains(parentNode))
                {
                    visited.Add(parentNode);
                    queue.Enqueue(parentNode);
                }
            }

            if (!parentInTarget || !bChildrenConditionMet)
                bIsValid = false;
        }

        // If the entire parent chain satisfied the conditions, add the target to the valid set.
        if (bIsValid)
        {
            validTargets.Add(target);
        }
    }

    return validTargets.Array();
}