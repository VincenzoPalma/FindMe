#include "../Public/Model/CTL_ModelChecking/CTLFormula.h"


UAtomicFormula::UAtomicFormula()
{
}

void UAtomicFormula::Initialize(TFunction<bool(const FState&)> InPredicate)
{
    Predicate = InPredicate;
}

bool UAtomicFormula::EvaluatePredicate(UStateNode* stateNode) const
{
    if (stateNode)
    {
        return Predicate(stateNode->GetState());
    }
    return false;
}

TArray<UStateNode*> UAtomicFormula::Evaluate(const UCTLModel* model, UStateNode* stateNode) const
{
    TArray<UStateNode*> satisfyingStates;

    if (!model)
    {
        UE_LOG(LogTemp, Error, TEXT("Invalid model passed to Evaluate"));
        return satisfyingStates;
    }

    // If stateNode is null, verifies all states in the model
    if (!stateNode)
    {
        const TMap<int32, UStateNode*>& allStateNodes = model->GetStateNodes();
        for (const auto& StateNodeEntry : allStateNodes)
        {
            UStateNode* node = StateNodeEntry.Value;
            if (EvaluatePredicate(node))
            {
                satisfyingStates.Add(node);
            }
        }
    }
    else
    {
        // Verifies the predicate on the passed stateNode and all reachable nodes
        TArray<UStateNode*> nodesToCheck;
        nodesToCheck.Add(stateNode);

        TSet<UStateNode*> visitedNodes;

        while (nodesToCheck.Num() > 0)
        {
            UStateNode* currentNode = nodesToCheck.Pop(false);
            if (!visitedNodes.Contains(currentNode))
            {
                visitedNodes.Add(currentNode);

                // Check the predicate on the current node
                if (EvaluatePredicate(currentNode))
                {
                    satisfyingStates.Add(currentNode);
                }

                // Add all children (successors) to the list of nodes to check
                const TArray<UStateNode*>& children = currentNode->GetChildren();
                for (UStateNode* childNode : children)
                {
                    nodesToCheck.Add(childNode);
                }
            }
        }
    }

    return satisfyingStates;
}


UUnaryFormula::UUnaryFormula()
{
}

void UUnaryFormula::Initialize(ECTLOperator InOp, UCTLFormula* InSubFormula)
{
    Op = InOp;
    SubFormula = InSubFormula;
}

TArray<UStateNode*> UUnaryFormula::Evaluate(const UCTLModel* model, UStateNode* stateNode) const
{
    // Temporary array to collect results
    TArray<UStateNode*> satisfyingStatesArray;

    // Set to ensure uniqueness
    TSet<UStateNode*> satisfyingStatesSet;

    // Check if model, stateNode, and SubFormula are valid
    if (!model || !SubFormula)
    {
        return satisfyingStatesArray;
    }

    // Evaluate the sub-formula
    TArray<UStateNode*> SubResults = SubFormula->Evaluate(model, stateNode);

    switch (Op)
    {
    case ECTLOperator::NOT:
    {
        // Find all states not satisfying the sub-formula
        for (const auto& StateNode : model->GetReachableNodes(stateNode))
        {
            if (!SubResults.Contains(StateNode))
            {
                satisfyingStatesSet.Add(StateNode);
            }
        }
        break;
    }

    case ECTLOperator::EX:
    {
        // Find all states from which there exists a successor satisfying the sub-formula
        TArray<UStateNode*> PreImage = model->PreImageExistential(SubResults, stateNode);
        for (UStateNode* Node : PreImage)
        {
            satisfyingStatesSet.Add(Node);
        }
        break;
    }

    case ECTLOperator::AX:
    {
        // Find all states from which all successors satisfy the sub-formula
        TArray<UStateNode*> PreImage = model->PreImageUniversal(SubResults, stateNode);
        for (UStateNode* Node : PreImage)
        {
            satisfyingStatesSet.Add(Node);
        }
        break;
    }

    case ECTLOperator::EF:
    {
        TArray<UStateNode*> ReachableStates;
        TArray<UStateNode*> CurrentStates = SubResults;
        TSet<UStateNode*> VisitedStates;

        while (!CurrentStates.IsEmpty())
        {
            for (UStateNode* StateNode : CurrentStates)
            {
                satisfyingStatesSet.Add(StateNode);
                VisitedStates.Add(StateNode);
            }

            CurrentStates = model->PreImageExistential(CurrentStates, stateNode);
            CurrentStates = CurrentStates.FilterByPredicate([&](UStateNode* StateNode) { return !VisitedStates.Contains(StateNode); });
        }

        break;
    }

    case ECTLOperator::AF:
    {
        //TODO
        TArray<UStateNode*> AllStates;
        model->GetStateNodes().GenerateValueArray(AllStates);
        TArray<UStateNode*> CurrentStates = SubResults;
        TSet<UStateNode*> VisitedStates;

        while (!CurrentStates.IsEmpty())
        {
            for (UStateNode* StateNode : CurrentStates)
            {
                satisfyingStatesSet.Add(StateNode);
                VisitedStates.Add(StateNode);
            }

            CurrentStates = model->PreImageUniversal(AllStates, stateNode);
            CurrentStates = CurrentStates.FilterByPredicate([&](UStateNode* StateNode) { return !VisitedStates.Contains(StateNode); });
        }

        break;
    }

    case ECTLOperator::EG:
    {
        //TODO
        TArray<UStateNode*> AllStates = model->GetReachableNodes(stateNode);
        TArray<UStateNode*> TempResults;

        while (TempResults != SubResults) {
            TempResults = SubResults;
            SubResults.Empty();

            TArray<UStateNode*> PreImage = model->PreImageExistential(TempResults, stateNode);

            for (UStateNode* State : TempResults) {
                if (PreImage.Contains(State)) {
                    SubResults.Add(State);
                }
            }
            for (UStateNode* State : TempResults) {
                UE_LOG(LogTemp, Log, TEXT("Temp Elemento %d"), State->GetState().Id);
            }
            for (UStateNode* State : SubResults) {
                UE_LOG(LogTemp, Log, TEXT("Sub Elemento %d"), State->GetState().Id);
            }
        }

        break;
    }



    case ECTLOperator::AG:
    {
        //TODO
        // Find all states where every path is entirely within states satisfying the sub-formula
        TArray<UStateNode*> AllStates;
        model->GetStateNodes().GenerateValueArray(AllStates);
        TArray<UStateNode*> CurrentStates = SubResults;

        while (!CurrentStates.IsEmpty())
        {
            for (UStateNode* StateNode : AllStates)
            {
                if (CurrentStates.Contains(StateNode))
                {
                    satisfyingStatesSet.Add(StateNode);
                }
            }
            CurrentStates = model->PreImageUniversal(AllStates, stateNode);
            CurrentStates = CurrentStates.FilterByPredicate([&](UStateNode* StateNode) { return SubResults.Contains(StateNode); });
        }

        break;
    }

    default:
        break;
    }

    satisfyingStatesArray = satisfyingStatesSet.Array();
    return satisfyingStatesArray;
}



UBinaryFormula::UBinaryFormula()
{
}

void UBinaryFormula::Initialize(ECTLOperator InOp, UCTLFormula* InLeft, UCTLFormula* InRight)
{
    Op = InOp;
    Left = InLeft;
    Right = InRight;
}

TArray<UStateNode*> UBinaryFormula::Evaluate(const UCTLModel* model, UStateNode* stateNode) const
{
    // Temporary array to collect results
    TArray<UStateNode*> satisfyingStatesArray;

    // Set to ensure uniqueness
    TSet<UStateNode*> satisfyingStatesSet;

    // Check if stateNode, Left, or Right are null
    if (!stateNode || !Left || !Right)
    {
        return satisfyingStatesArray;
    }

    // Evaluate the left and right formulas
    TArray<UStateNode*> leftStates = Left->Evaluate(model, stateNode);
    TArray<UStateNode*> rightStates = Right->Evaluate(model, stateNode);

    switch (Op)
    {
    case ECTLOperator::AND:
    {
        // Find states satisfying both Left and Right formulas
        for (UStateNode* leftNode : leftStates)
        {
            if (rightStates.Contains(leftNode))
            {
                satisfyingStatesSet.Add(leftNode);
            }
        }
        break;
    }

    case ECTLOperator::OR:
    {
        // Find states satisfying either Left or Right formula
        for (UStateNode* node : leftStates)
        {
            satisfyingStatesSet.Add(node);
        }

        for (UStateNode* node : rightStates)
        {
            satisfyingStatesSet.Add(node);
        }
        break;
    }

    case ECTLOperator::EU:
    {
        //TODO
        // Existential Until: States from which we can eventually reach a state satisfying Right,
        // while satisfying Left up to that point
        TArray<UStateNode*> reachableStates;
        TArray<UStateNode*> currentStates = rightStates;

        while (!currentStates.IsEmpty())
        {
            reachableStates.Append(currentStates);
            currentStates = model->PreImageExistential(currentStates, stateNode);
            currentStates = currentStates.FilterByPredicate([&](UStateNode* StateNode) { return leftStates.Contains(StateNode); });
        }

        // Add all reachable states to the set
        for (UStateNode* state : reachableStates)
        {
            satisfyingStatesSet.Add(state);
        }
        break;
    }

    case ECTLOperator::AU:
    {
        //TODO
        // Always Until: States from which every path remains in states satisfying Right,
        // and eventually reaches a state satisfying Left
        TArray<UStateNode*> allStates;
        model->GetStateNodes().GenerateValueArray(allStates);
        TArray<UStateNode*> currentStates = rightStates;

        while (!currentStates.IsEmpty())
        {
            allStates = allStates.FilterByPredicate([&](UStateNode* StateNode) { return currentStates.Contains(StateNode); });
            currentStates = model->PreImageUniversal(allStates, stateNode);
            currentStates = currentStates.FilterByPredicate([&](UStateNode* StateNode) { return leftStates.Contains(StateNode); });
        }

        // Add all remaining states to the set
        for (UStateNode* state : allStates)
        {
            satisfyingStatesSet.Add(state);
        }
        break;
    }

    default:
        break;
    }

    satisfyingStatesArray = satisfyingStatesSet.Array();
    return satisfyingStatesArray;
}