#pragma once

#include "StateTree/StateNode.h"
#include "CoreMinimal.h"
#include "ModelStructures.h"
#include "CTLModel.generated.h"

UCLASS(Blueprintable)
class CTL_LABYRINTH_API UCTLModel : public UObject
{
    GENERATED_BODY()

public:
    UCTLModel();

    void AddState(const FState& state);

    void AddTransition(const FState& from, const FState& to);

    void RegisterPredicate(const FString& name, TFunction<bool(const FState&)> predicate);

    bool EvaluatePredicate(const FState& state, const FString& predicateName) const;

    UStateNode* GetRootNode() const {
        return rootNode;
    }

private:
    UPROPERTY()
    TMap<int32, UStateNode*> stateNodes;

    UPROPERTY()
    UStateNode* rootNode;

    TMap<FString, TFunction<bool(const FState&)>> Predicates;
};
