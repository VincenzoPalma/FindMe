#pragma once

#include "CoreMinimal.h"
#include "../ModelStructures.h"
#include "StateNode.generated.h"

UCLASS(Blueprintable)
class CTL_LABYRINTH_API UStateNode : public UObject
{
    GENERATED_BODY()

public:
    UStateNode() {}

    UFUNCTION(BlueprintCallable, Category = "StateNode")
    void AddChild(FString& action, UStateNode* child)
    {
        if (child)
        {
            Children.Add(action, child);
        }
    }

    UFUNCTION(BlueprintCallable, Category = "StateNode")
    const TArray<UStateNode*> GetChildren() const
    {
        TArray<UStateNode*> ChildrenArray;
        Children.GenerateValueArray(ChildrenArray);
        return ChildrenArray;
    }

    UFUNCTION(BlueprintCallable, Category = "StateNode")
    const FState& GetState() const
    {
        return StateData;
    }

    UFUNCTION(BlueprintGetter)
    FState GetStateData() const { return StateData; }

    UFUNCTION(BlueprintSetter)
    void SetStateData(const FState& InStateData) { StateData = InStateData; }

    UFUNCTION(BlueprintGetter)
    TMap<FString, UStateNode*> GetChildrenMap() const { return Children; }

    UFUNCTION(BlueprintSetter)
    void SetChildrenMap(const TMap<FString, UStateNode*>& InChildren) { Children = InChildren; }


private:
    UPROPERTY(BlueprintGetter = GetStateData, BlueprintSetter = SetStateData, Category = "StateNode")
    FState StateData;

    UPROPERTY(BlueprintGetter = GetChildrenMap, BlueprintSetter = SetChildrenMap, Category = "StateNode")
    TMap<FString, UStateNode*> Children;
};
