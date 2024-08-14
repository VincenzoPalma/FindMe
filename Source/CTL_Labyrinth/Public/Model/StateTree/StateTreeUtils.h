#pragma once

#include "CoreMinimal.h"
#include "StateNode.h"
#include "StateTreeUtils.generated.h"

UCLASS()
class CTL_LABYRINTH_API UStateTreeUtils : public UObject
{
    GENERATED_BODY()

public:
    static TArray<UStateNode*> VerifyEFFormula(UStateNode* root, TFunction<bool(UStateNode*)> predicate);

    static TArray<UStateNode*> VerifyAFFormula(UStateNode* root, TFunction<bool(UStateNode*)> predicate);

    static TArray<UStateNode*> VerifyEGFormula(UStateNode* root, TFunction<bool(UStateNode*)> predicate);

    static TArray<UStateNode*> VerifyAGFormula(UStateNode* startNode, TFunction<bool(UStateNode*)> predicate);

    static TArray<UStateNode*> VerifyAUFormula(UStateNode* root, TFunction<bool(UStateNode*)> predicateA, TFunction<bool(UStateNode*)> predicateB);

    static TArray<UStateNode*> VerifyEUFormula(UStateNode* root, TFunction<bool(UStateNode*)> predicateA, TFunction<bool(UStateNode*)> predicateB);

    static TArray<UStateNode*> VerifyIfAnyChild(UStateNode* root, TFunction<bool(UStateNode*)> predicate);

    static TArray<UStateNode*> VerifyIfAllChildren(UStateNode* root, TFunction<bool(UStateNode*)> predicate);
};
