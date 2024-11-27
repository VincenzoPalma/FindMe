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

USTRUCT(BlueprintType)
struct FActionsArray
{
    GENERATED_BODY()

    UPROPERTY()
    TArray<FString> Keys;

    bool operator==(const FActionsArray& Other) const
    {
        return Keys == Other.Keys;
    }
};

FORCEINLINE uint32 GetTypeHash(const FActionsArray& Key)
{
    uint32 Hash = 0;
    for (const FString& Str : Key.Keys)
    {
        Hash = HashCombine(Hash, GetTypeHash(Str));
    }
    return Hash;
}