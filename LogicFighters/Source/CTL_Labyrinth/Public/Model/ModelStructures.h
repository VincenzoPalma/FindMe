#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ModelStructures.generated.h"

UENUM(BlueprintType)
enum class ECharacterActions : uint8
{
    Attack        UMETA(DisplayName = "Attack"),
    Defense     UMETA(DisplayName = "Defense"),
    CounterAttack     UMETA(DisplayName = "CounterAttack"),
    Buff     UMETA(DisplayName = "Buff"),
    SpecialAttack     UMETA(DisplayName = "SpecialAttack"),
    Null     UMETA(DisplayName = "Null")
};

USTRUCT(BlueprintType)
struct FVariantValue
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variant")
    FString Type;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variant")
    FString StringValue;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variant")
    int32 IntValue;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variant")
    double DoubleValue;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variant")
    bool BoolValue;

    FVariantValue() : Type(TEXT("None")), StringValue(TEXT("")), IntValue(0), DoubleValue(0.0f), BoolValue(false) {}

    void SetBool(bool InValue)
    {
        Type = TEXT("bool");
        BoolValue = InValue;
    }

    void SetInt(int32 InValue)
    {
        Type = TEXT("int");
        IntValue = InValue;
    }

    void SetDouble(float InValue)
    {
        Type = TEXT("double");
        DoubleValue = InValue;
    }

    void SetString(const FString& InValue)
    {
        Type = TEXT("string");
        StringValue = InValue;
    }

    FString ToString() const
    {
        if (Type == TEXT("bool"))
        {
            return BoolValue ? TEXT("true") : TEXT("false");
        }
        else if (Type == TEXT("int"))
        {
            return FString::Printf(TEXT("%d"), IntValue);
        }
        else if (Type == TEXT("double"))
        {
            return FString::Printf(TEXT("%f"), DoubleValue);
        }
        else if (Type == TEXT("string"))
        {
            return StringValue;
        }
        return TEXT("Unknown");
    }

};

USTRUCT(BlueprintType)
struct FState
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "State")
    FString Id;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "State")
    TMap<FString, FVariantValue> Properties;

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
    TArray<ECharacterActions> Keys;

    bool operator==(const FActionsArray& Other) const
    {
        return Keys == Other.Keys;
    }
};

FORCEINLINE uint32 GetTypeHash(const FActionsArray& ActionsArray)
{
    uint32 Hash = 0;
    for (const ECharacterActions Key : ActionsArray.Keys)
    {
        Hash = HashCombine(Hash, GetTypeHash(Key));
    }
    return Hash;
}

USTRUCT(BlueprintType)
struct FActionsToNode
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FString ToNodeId;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<ECharacterActions> Actions;

    bool operator==(const FActionsToNode& Other) const
    {
        return Actions == Other.Actions && ToNodeId == Other.ToNodeId;
    }

    FActionsToNode() : Actions(), ToNodeId("") {}

    FActionsToNode(FString& InToNodeId, const TArray<ECharacterActions>& InActions)
        : Actions(InActions), ToNodeId(InToNodeId) {
    }
};