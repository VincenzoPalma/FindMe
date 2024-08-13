#pragma once

#include "StateTree/StateNode.h"
#include "CTL_ModelChecking/CTLFormula.h"
#include "PredicateManager.h"
#include "CoreMinimal.h"
#include "ModelStructures.h"
#include "CTLModel.generated.h"

UCLASS(Blueprintable)
class CTL_LABYRINTH_API UCTLModel : public UObject
{
    GENERATED_BODY()

public:
    UCTLModel();

    void AddState(const FState& state);
    void AddTransition(UStateNode* FromNode, UStateNode* ToNode);
    void AddFormula(int32 FormulaId, UCTLFormula* Formula);

    UFUNCTION(BlueprintCallable, Category = "Model")
    UCTLFormula* GetFormula(int32 Id) const;

    UFUNCTION(BlueprintCallable, Category = "Model")
    UStateNode* GetRootNode() const {
        return rootNode;
    }

    UFUNCTION(BlueprintCallable, Category = "Model")
    const TMap<int32, UStateNode*>& GetStateNodes() const { 
        return stateNodes; 
    }

    UFUNCTION(BlueprintCallable, Category = "Model")
    const TMap<int32, UCTLFormula*>& GetFormulas() const {
        return Formulas;
    }

    UFUNCTION(BlueprintCallable, Category = "Model")
    UPredicateManager* GetPredicateManager() const
    {
        return PredicateManager;
    }

    UFUNCTION(BlueprintCallable, Category = "Debug")
    void DebugPrintModel() const;

    virtual void PostInitProperties() override;

private:
    UPROPERTY()
    TMap<int32, UStateNode*> stateNodes;

    UPROPERTY()
    UStateNode* rootNode;

    UPROPERTY()

    TMap<int32, UCTLFormula*> Formulas;

    UPROPERTY()
    UPredicateManager* PredicateManager;

};