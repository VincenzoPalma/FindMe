#pragma once

#include "CoreMinimal.h"
#include "../ModelStructures.h"
#include "../CTL_ModelChecking/CTLFormula.h"
#include "ModelParser.generated.h"

UCLASS(Blueprintable)
class CTL_LABYRINTH_API UModelParser : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Model Parsing")
    UCTLModel* LoadModelFromJson(const FString& FilePath);
    UFUNCTION(BlueprintCallable, Category = "Model Parsing")
    UCTLModel* LoadPartialModelFromJson(const FString& FilePath);

private:
    void ParseStateById(const TArray<TSharedPtr<FJsonValue>>& StatesArray, int32 TargetId, UCTLModel* Model);
    void ParseStates(const TArray<TSharedPtr<FJsonValue>>& StatesArray, UCTLModel* Model);
    void ParseTransitions(const TArray<TSharedPtr<FJsonValue>>& TransitionsArray, UCTLModel* Model);
    void ParseFormulas(const TArray<TSharedPtr<FJsonValue>>& FormulasArray, UCTLModel* Model);
    ECTLOperator StringToOperator(const FString& OperatorString);
};