#pragma once

#include "CoreMinimal.h"
#include "StateNode.h"
#include "StateTreeUtils.generated.h"

UCLASS()
class CTL_LABYRINTH_API UStateTreeUtils : public UObject
{
    GENERATED_BODY()

public:
    static bool VerifyEFFormula(UStateNode* root, TFunction<bool(UStateNode*)> evaluate);

    static bool VerifyAFFormula(UStateNode* root, TFunction<bool(UStateNode*)> evaluate);

    static bool VerifyEGFormula(UStateNode* root, TFunction<bool(UStateNode*)> evaluate);

    static bool VerifyAGFormula(UStateNode* root, TFunction<bool(UStateNode*)> evaluate);

    static bool VerifyIfAnyChild(UStateNode* root, TFunction<bool(UStateNode*)> evaluate);

    static bool VerifyIfAllChildren(UStateNode* root, TFunction<bool(UStateNode*)> evaluate);
};
