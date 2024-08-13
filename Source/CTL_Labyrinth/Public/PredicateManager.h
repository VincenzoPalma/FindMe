#pragma once

#include "CoreMinimal.h"
#include "Model/StateTree/StateNode.h"
#include "Model/ModelStructures.h"
#include "PredicateManager.generated.h"

typedef TFunction<bool(const FState&)> PredicateFunction;

UCLASS(Blueprintable)
class CTL_LABYRINTH_API UPredicateManager : public UObject
{
    GENERATED_BODY()

public:
    void RegisterPredicate(const FString& PredicateName, PredicateFunction InPredicate);

    bool EvaluatePredicate(const FString& PredicateName, const FState& State) const;

private:
    TMap<FString, PredicateFunction> Predicates;
};
