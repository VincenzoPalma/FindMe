#include "../Public/Model/CTLModel.h"

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

void UCTLModel::AddTransition(UStateNode* FromNode, UStateNode* ToNode)
{
    if (FromNode && ToNode)
    {
        FromNode->AddChild(ToNode);
    }
}


void UCTLModel::AddFormula(int32 FormulaId, UCTLFormula* Formula)
{
    if (Formula && !Formulas.Contains(FormulaId))
    {
        Formulas.Add(FormulaId, Formula);
    }
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



void UCTLModel::DebugPrintModel() const
{
    if (GEngine)
    {
        // Print root node
        if (rootNode)
        {
            FString RootNodeMessage = FString::Printf(TEXT("Root Node ID: %d"), rootNode->GetState().Id);
            UE_LOG(LogTemp, Log, TEXT("%s"), *RootNodeMessage);
        }
        else
        {
            UE_LOG(LogTemp, Log, TEXT("Root Node is not set."));
        }

        // Print states and their data
        for (const auto& StatePair : stateNodes)
        {
            const UStateNode* StateNode = StatePair.Value;
            FString StateMessage = FString::Printf(TEXT("State ID: %d"), StateNode->GetState().Id);
            UE_LOG(LogTemp, Log, TEXT("%s"), *StateMessage);

            for (const TPair<FString, bool>& Property : StateNode->GetState().Properties)
            {
                FString PropertyMessage = FString::Printf(TEXT("  Property: %s = %s"), *Property.Key, Property.Value ? TEXT("true") : TEXT("false"));
                UE_LOG(LogTemp, Log, TEXT("%s"), *PropertyMessage);
            }

            // Print child nodes
            for (const UStateNode* ChildNode : StateNode->GetChildren())
            {
                FString ChildMessage = FString::Printf(TEXT("  Child State ID: %d"), ChildNode->GetState().Id);
                UE_LOG(LogTemp, Log, TEXT("%s"), *ChildMessage);
            }
        }
        // Print formulas
        for (const auto& FormulaPair : GetFormulas())
        {

            const UCTLFormula* Formula = FormulaPair.Value;
            if (Formula)
            {
                FString FormulaMessage = FString::Printf(TEXT("Formula ID: %d, Type: %s"), FormulaPair.Key, *Formula->GetClass()->GetName());
                UE_LOG(LogTemp, Log, TEXT("%s"), *FormulaMessage);
            }
        }

        // Print predicates
        const UPredicateManager* PredManager = GetPredicateManager();
        if (PredManager)
        {
            for (const auto& PredicatePair : PredManager->GetPredicates())
            {

                FString PredicateName = PredicatePair.Key;
                FString PredicateMessage = FString::Printf(TEXT("Predicate: %s"), *PredicateName);
                UE_LOG(LogTemp, Log, TEXT("%s"), *PredicateMessage);
            }
        }
    }
}
