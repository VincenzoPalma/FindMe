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

        satisfyingStatesArray = satisfyingStatesSet.Array();

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

        satisfyingStatesArray = satisfyingStatesSet.Array();

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

        satisfyingStatesArray = satisfyingStatesSet.Array();

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

        satisfyingStatesArray = satisfyingStatesSet.Array();

        break;
    }

    case ECTLOperator::AF:
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

            CurrentStates = model->PreImageUniversal(CurrentStates, stateNode);
            CurrentStates = CurrentStates.FilterByPredicate([&](UStateNode* StateNode) { return !VisitedStates.Contains(StateNode); });
        }

        satisfyingStatesArray = satisfyingStatesSet.Array();

        break;
    }

    case ECTLOperator::EG:
    {
        //TODO
        // Find all states where a path exists that is entirely within states satisfying the sub-formula
        TArray<UStateNode*> AllStates = model->GetReachableNodes(stateNode);
        AllStates = SubResults;

        do
        {
            TArray<UStateNode*> preImage = model->PreImageExistential(AllStates, stateNode);
            SubResults = StatesUtils::StatesIntersection(preImage, AllStates);
            AllStates = SubResults;
        } while (!StatesUtils::IsSubSet(AllStates, SubResults));

        satisfyingStatesArray = AllStates;

        break;
    }

    case ECTLOperator::AG:
    {
        //TODO
        // Find all states where every path is entirely within states satisfying the sub-formula
        TArray<UStateNode*> AllStates = model->GetReachableNodes(stateNode);
        AllStates = SubResults;

        do
        {
            TArray<UStateNode*> preImage = model->PreImageUniversal(AllStates, stateNode);
            SubResults = StatesUtils::StatesIntersection(preImage, AllStates);
            AllStates = SubResults;
        } while (!StatesUtils::IsSubSet(AllStates, SubResults));

        satisfyingStatesArray = AllStates;

        break;
    }

    default:
        break;
    }

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
        satisfyingStatesArray = satisfyingStatesSet.Array();

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
        satisfyingStatesArray = satisfyingStatesSet.Array();

        break;
    }

    case ECTLOperator::EU:
    {
        // Existential Until: States from which we can eventually reach a state satisfying Right,
        // while satisfying Left up to that point
        while (!StatesUtils::IsSubSet(rightStates, satisfyingStatesArray)) {
            satisfyingStatesArray = StatesUtils::StatesUnion(satisfyingStatesArray, rightStates);
            TArray<UStateNode*> preImage = model->PreImageExistential(satisfyingStatesArray, stateNode);
            rightStates = StatesUtils::StatesIntersection(preImage, leftStates);
        }
     
        break;
    }

    case ECTLOperator::AU:
    {
        // Always Until: States from which every path remains in states satisfying Right,
        // and eventually reaches a state satisfying Left
        while (!StatesUtils::IsSubSet(rightStates, satisfyingStatesArray)) {
            satisfyingStatesArray = StatesUtils::StatesUnion(satisfyingStatesArray, rightStates);
            TArray<UStateNode*> preImage = model->PreImageUniversal(satisfyingStatesArray, stateNode);
            rightStates = StatesUtils::StatesIntersection(preImage, leftStates);
        }

        break;
    }

    default:
        break;
    }

    return satisfyingStatesArray;
}