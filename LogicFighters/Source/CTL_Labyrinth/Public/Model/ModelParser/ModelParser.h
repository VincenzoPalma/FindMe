#pragma once

#include "CoreMinimal.h"
#include "../ModelStructures.h"
#include "../CTL_ModelChecking/CTLFormula.h"
#include "Model/ModelParser/JsonDataManager.h"
#include "ModelParser.generated.h"

UCLASS(Blueprintable)
class CTL_LABYRINTH_API UModelParser : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Model Parsing")
    static UCTLModel* ParseStateById(const FString& Character1Class, const FString& Character2Class, const FString& TargetStateId);



private:
    static FState ParseStateProperties(const FString& StateId);
    static void AddTransitionsFromState(const FString& FromStateId, const TSharedPtr<FJsonObject>& JsonObject, UCTLModel* Model);
    static FString GetJsonFilePath(const FString& Character1Class, const FString& Character2Class);
};