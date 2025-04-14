#pragma once

#include "CoreMinimal.h"
#include "CTLModel.h"
#include "ModelParser.generated.h"

UCLASS()
class CTL_LABYRINTH_API UModelParser : public UObject
{
    GENERATED_BODY()

public:
    UModelParser();

    UFUNCTION(BlueprintCallable, Category = "ModelParser")
    void LoadModelFromJson(const FString& FilePath, UCTLModel* Model);

private:
    TFunction<bool(const FState&)> CreatePredicate(const FString& PredicateName) const;
};
