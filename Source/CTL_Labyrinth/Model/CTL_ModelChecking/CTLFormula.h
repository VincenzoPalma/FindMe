#pragma once

#include "CoreMinimal.h"
#include "../StateTree/StateNode.h"
#include "../StateTree/StateTreeUtils.h"
#include "CTLFormula.generated.h"

UENUM(BlueprintType)
enum class ECTLOperator : uint8 {
    AND,
    OR,
    NOT,
    EX,
    AX,
    EF,
    AF,
    EG,
    AG,
    EU,
    AU
};

UCLASS(Blueprintable)
class CTL_LABYRINTH_API UCTLFormula : public UObject
{
    GENERATED_BODY()

public:
    virtual ~UCTLFormula() = default;
    virtual bool Evaluate(UStateNode* node) const PURE_VIRTUAL(UCTLFormula::Evaluate, return false;);
};

UCLASS(Blueprintable)
class CTL_LABYRINTH_API UAtomicFormula : public UCTLFormula
{
    GENERATED_BODY()

public:
    UAtomicFormula();

    UFUNCTION(BlueprintCallable, Category = "AtomicFormula")
    virtual bool Evaluate(UStateNode* node) const override;

    void Initialize(TFunction<bool(const FState&)> InPredicate);

private:
    TFunction<bool(const FState&)> Predicate;
};

UCLASS(Blueprintable)
class CTL_LABYRINTH_API UUnaryFormula : public UCTLFormula
{
    GENERATED_BODY()

public:
    UUnaryFormula();
    virtual bool Evaluate(UStateNode* node) const override;

    void Initialize(ECTLOperator InOp, UCTLFormula* InSubFormula);

private:
    ECTLOperator Op;
    UCTLFormula* SubFormula;
};

UCLASS(Blueprintable)
class CTL_LABYRINTH_API UBinaryFormula : public UCTLFormula
{
    GENERATED_BODY()

public:
    UBinaryFormula();
    virtual bool Evaluate(UStateNode* node) const override;

    void Initialize(ECTLOperator InOp, UCTLFormula* InLeft, UCTLFormula* InRight);

private:
    ECTLOperator Op;
    UCTLFormula* Left;
    UCTLFormula* Right;
};
