#pragma once

#include "CoreMinimal.h"
#include "ModelStructures.generated.h"

USTRUCT(BlueprintType)
struct FState
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "State")
    int32 Id;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "State")
    TMap<FString, bool> Properties;
};

USTRUCT(BlueprintType)
struct FTransition
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Transition")
    FState From;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Transition")
    FState To;
};
