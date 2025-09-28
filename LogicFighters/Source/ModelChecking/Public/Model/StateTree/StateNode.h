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

    UPROPERTY(BlueprintReadWrite, Category = "StateNode")
    TArray<ECharacterActions> PreviousTurnActions;

    TMap<FActionsArray, UStateNode*> GetChildrenMap() {
        return Children;
    }

    UFUNCTION(BlueprintCallable, Category = "StateNode")
    void AddChild(FActionsArray actions, UStateNode* child)
    {
        if (child)
        {
            Children.Add(actions, child);
        }
    }

    UFUNCTION(BlueprintCallable, Category = "StateNode")
    void AddParent(UStateNode* parent, FActionsArray actions)
    {
        if (parent)
        {
            Parents.Add(parent, actions);
        }
    }

    UFUNCTION(BlueprintCallable, Category = "StateNode")
    TMap<UStateNode*, FActionsArray> GetParents()
    {
        return Parents;
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
    TMap<FActionsArray, UStateNode*> GetChildrenMap() const { return Children; }

    UFUNCTION(BlueprintSetter)
    void SetChildrenMap(const TMap<FActionsArray, UStateNode*>& InChildren) { Children = InChildren; }


private:
    UPROPERTY(BlueprintGetter = GetStateData, BlueprintSetter = SetStateData, Category = "StateNode")
    FState StateData;

    UPROPERTY(BlueprintGetter = GetChildrenMap, BlueprintSetter = SetChildrenMap, Category = "StateNode")
    TMap<FActionsArray, UStateNode*> Children;

    TMap<UStateNode*, FActionsArray> Parents;
};
