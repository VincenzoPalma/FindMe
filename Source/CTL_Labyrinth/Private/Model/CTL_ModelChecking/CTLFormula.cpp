#include "../Public/Model/CTL_ModelChecking/CTLFormula.h"

UAtomicFormula::UAtomicFormula()
{
}

void UAtomicFormula::Initialize(TFunction<bool(const FState&)> InPredicate)
{
    Predicate = InPredicate;
}

bool UAtomicFormula::Evaluate(UStateNode* stateNode) const
{
    if (stateNode)
    {
        return Predicate(stateNode->GetState());
    }
    return false;
}

UUnaryFormula::UUnaryFormula()
{
}

void UUnaryFormula::Initialize(ECTLOperator InOp, UCTLFormula* InSubFormula)
{
    Op = InOp;
    SubFormula = InSubFormula;
}

bool UUnaryFormula::Evaluate(UStateNode* stateNode) const
{
    if (!stateNode || !SubFormula)
    {
        return false;
    }

    switch (Op)
    {
    case ECTLOperator::NOT:
        return !SubFormula->Evaluate(stateNode);
    case ECTLOperator::EX:
        return UStateTreeUtils::VerifyIfAnyChild(stateNode, [this](UStateNode* child) {
            return SubFormula->Evaluate(child);
            });
    case ECTLOperator::AX:
        return UStateTreeUtils::VerifyIfAllChildren(stateNode, [this](UStateNode* child) {
            return SubFormula->Evaluate(child);
            });
    case ECTLOperator::EF:
        return UStateTreeUtils::VerifyEFFormula(stateNode, [this](UStateNode* node) {
            return SubFormula->Evaluate(node);
            });
    case ECTLOperator::AF:
        return UStateTreeUtils::VerifyAFFormula(stateNode, [this](UStateNode* node) {
            return SubFormula->Evaluate(node);
            });
    case ECTLOperator::EG:
        return UStateTreeUtils::VerifyEGFormula(stateNode, [this](UStateNode* node) {
            return SubFormula->Evaluate(node);
            });
    case ECTLOperator::AG:
        return UStateTreeUtils::VerifyAGFormula(stateNode, [this](UStateNode* node) {
            return SubFormula->Evaluate(node);
            });
    default:
        return false;
    }
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

bool UBinaryFormula::Evaluate(UStateNode* stateNode) const
{
    if (!stateNode || !Left || !Right)
    {
        return false;
    }

    switch (Op)
    {
    case ECTLOperator::AND:
        return Left->Evaluate(stateNode) && Right->Evaluate(stateNode);
    case ECTLOperator::OR:
        return Left->Evaluate(stateNode) || Right->Evaluate(stateNode);
    case ECTLOperator::EU:
        return UStateTreeUtils::VerifyEUFormula(
            stateNode,
            [this](UStateNode* node) { return Left->Evaluate(node); },
            [this](UStateNode* node) { return Right->Evaluate(node); }
        );
    case ECTLOperator::AU:
        return UStateTreeUtils::VerifyAUFormula(
            stateNode,
            [this](UStateNode* node) { return Left->Evaluate(node); },
            [this](UStateNode* node) { return Right->Evaluate(node); }
        );
    default:
        return false;
    }
}
