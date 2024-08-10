#pragma once

#include "CoreMinimal.h"
#include "ModelStructures.h"
#include "StateNode.generated.h"

UCLASS(Blueprintable)
class CTL_LABYRINTH_API UStateNode : public UObject
{
    GENERATED_BODY()

public:
    UStateNode() {}

    UFUNCTION(BlueprintCallable, Category = "StateNode")
    void AddChild(UStateNode* child)
    {
        if (child)
        {
            Children.Add(child);
        }
    }

    UFUNCTION(BlueprintCallable, Category = "StateNode")
    const TArray<UStateNode*>& GetChildren() const
    {
        return Children;
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
    TArray<UStateNode*> GetChildrenArray() const { return Children; }

    UFUNCTION(BlueprintSetter)
    void SetChildrenArray(const TArray<UStateNode*>& InChildren) { Children = InChildren; }

private:
    UPROPERTY(BlueprintGetter = GetStateData, BlueprintSetter = SetStateData, Category = "StateNode")
    FState StateData;

    UPROPERTY(BlueprintGetter = GetChildrenArray, BlueprintSetter = SetChildrenArray, Category = "StateNode")
    TArray<UStateNode*> Children;
};
