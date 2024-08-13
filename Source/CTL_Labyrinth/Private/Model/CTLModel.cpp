#include "../Public/Model/CTLModel.h"

UCTLModel::UCTLModel()
    : rootNode(nullptr)
{
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
        UE_LOG(LogTemp, Log, TEXT("Transition added from State ID: %d to State ID: %d"), FromNode->GetState().Id, ToNode->GetState().Id);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Failed to add transition. FromNode or ToNode is null."));
    }
}


void UCTLModel::AddFormula(UCTLFormula* Formula)
{
    if (Formula)
    {
        Formulas.Add(Formula);
    }
}

void UCTLModel::DebugPrintModel() const
{
    if (GEngine)
    {
        // Print root
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
        for (const UCTLFormula* Formula : Formulas)
        {
            if (Formula)
            {
                FString FormulaMessage = FString::Printf(TEXT("Formula: %s"), *Formula->GetClass()->GetName());
                UE_LOG(LogTemp, Log, TEXT("%s"), *FormulaMessage);
            }
        }
    }
}