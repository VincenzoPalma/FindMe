#pragma once

#include "CoreMinimal.h"
#include "StateNode.h"
#include "Model/CTLModel.h"
#include "StateTreeUtils.generated.h"


UCLASS()
class CTL_LABYRINTH_API UStateTreeUtils : public UObject
{
    GENERATED_BODY()

public:

    static TArray<UStateNode*> PreImageUniversal(const UCTLModel* model, const TArray<UStateNode*>& states);

    static TArray<UStateNode*> PreImageExistential(const UCTLModel* model, const TArray<UStateNode*>& states);

};
