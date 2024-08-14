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

TArray<UStateNode*> UAtomicFormula::Evaluate(UStateNode* stateNode) const
{
    TArray<UStateNode*> satisfyingStates;

    if (stateNode && EvaluatePredicate(stateNode))
    {
        satisfyingStates.Add(stateNode);
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

//TODO
TArray<UStateNode*> UUnaryFormula::Evaluate(UStateNode* stateNode) const
{
    TArray<UStateNode*> satisfyingStates;

    if (!stateNode || !SubFormula)
    {
        return satisfyingStates;
    }

    switch (Op)
    {
    case ECTLOperator::NOT:
    {
        // TODO
    }
    break;

    case ECTLOperator::EX:
    {
        TArray<UStateNode*> satisfyingNodes;
        UStateTreeUtils::VerifyIfAnyChild(stateNode, [this](UStateNode* child) {
            return SubFormula->Evaluate(child).Num() > 0;
            });
        satisfyingStates = satisfyingNodes;
    }
    break;

    case ECTLOperator::AX:
    {
        TArray<UStateNode*> satisfyingNodes;
        UStateTreeUtils::VerifyIfAllChildren(stateNode, [this](UStateNode* child) {
            return SubFormula->Evaluate(child).Num() > 0;
            });
        satisfyingStates = satisfyingNodes;
    }
    break;

    case ECTLOperator::EF:
        satisfyingStates = UStateTreeUtils::VerifyEFFormula(stateNode, [this](UStateNode* node) {
            return SubFormula->Evaluate(node).Num() > 0;
            });
        break;

    case ECTLOperator::AF:
        satisfyingStates = UStateTreeUtils::VerifyAFFormula(stateNode, [this](UStateNode* node) {
            return SubFormula->Evaluate(node).Num() > 0;
            });
        break;

    case ECTLOperator::EG:
        satisfyingStates = UStateTreeUtils::VerifyEGFormula(stateNode, [this](UStateNode* node) {
            return SubFormula->Evaluate(node).Num() > 0;
            });
        break;

    case ECTLOperator::AG:
        satisfyingStates = UStateTreeUtils::VerifyAGFormula(stateNode, [this](UStateNode* node) {
            return SubFormula->Evaluate(node).Num() > 0;
            });
        break;

    default:
        break;
    }

    return satisfyingStates;
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

//TODO
TArray<UStateNode*> UBinaryFormula::Evaluate(UStateNode* stateNode) const
{
    TArray<UStateNode*> satisfyingStates;

    if (!stateNode || !Left || !Right)
    {
        return satisfyingStates;
    }

    TArray<UStateNode*> leftStates = Left->Evaluate(stateNode);
    TArray<UStateNode*> rightStates = Right->Evaluate(stateNode);

    switch (Op)
    {
    case ECTLOperator::AND:
        for (UStateNode* leftNode : leftStates)
        {
            if (rightStates.Contains(leftNode))
            {
                satisfyingStates.Add(leftNode);
            }
        }
        break;

    case ECTLOperator::OR:
        satisfyingStates = leftStates;
        for (UStateNode* rightNode : rightStates)
        {
            if (!satisfyingStates.Contains(rightNode))
            {
                satisfyingStates.Add(rightNode);
            }
        }
        break;

    case ECTLOperator::EU:
        /*TODO if (UStateTreeUtils::VerifyEUFormula(
            stateNode,
            [this](UStateNode* node) { return Left->Evaluate(node).Num() > 0; },
            [this](UStateNode* node) { return Right->Evaluate(node).Num() > 0; }
        ))
        {
            satisfyingStates = leftStates;
        }*/
        break;

    case ECTLOperator::AU:
        /*TODO if (UStateTreeUtils::VerifyAUFormula(
            stateNode,
            [this](UStateNode* node) { return Left->Evaluate(node).Num() > 0; },
            [this](UStateNode* node) { return Right->Evaluate(node).Num() > 0; }
        ))
        {
            satisfyingStates = leftStates;
        }*/
        break;

    default:
        break;
    }

    return satisfyingStates;
}

