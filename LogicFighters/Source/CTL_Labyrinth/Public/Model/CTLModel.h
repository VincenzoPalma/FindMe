#pragma once

#include "StateTree/StateNode.h"
#include "PredicateManager.h"
#include "Model/CTL_ModelChecking/CTLFormula.h"
#include "Model/ModelParser/ModelParser.h"
#include "CoreMinimal.h"
#include "ModelStructures.h"
#include "HAL/PlatformTime.h"
#include "AStar.h"
#include "Templates/SharedPointer.h"
#include "Json.h"
#include "JsonUtilities.h"
#include "Dom/JsonObject.h"
#include "CTLModel.generated.h"


UCLASS(Blueprintable)
class CTL_LABYRINTH_API UCTLModel : public UObject
{
    GENERATED_BODY()

public:
    UCTLModel();

    void AddState(const FState& state);
    void AddTransition(FActionsArray actions, UStateNode* FromNode, UStateNode* ToNode);
    void AddFormula(int32 FormulaId, UCTLFormula* Formula);
    TSharedPtr<FJsonObject> GetJsonFile();

    UFUNCTION(BlueprintCallable, Category = "Model")
    bool InitializeModel(const FString& Character1Class, const FString& Character2Class, const TMap<ECharacterActions, float> ActionRates);

    UFUNCTION(BlueprintCallable, Category = "Model")
    UCTLFormula* GetFormula(int32 Id) const;

    UFUNCTION(BlueprintCallable, Category = "Model")
    UStateNode* GetRootNode() const {
        return rootNode;
    }

    UFUNCTION(BlueprintCallable, Category = "Model")
    TMap<ECharacterActions, float> GetPlayerActionRates() const {
        return PlayerActionRates;
    }

    UFUNCTION(BlueprintCallable, Category = "Model")
    const TMap<FString, UStateNode*>& GetStateNodes() const { 
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

    UFUNCTION(BlueprintCallable, Category = "Model")
    TArray<UStateNode*> GetReachableNodes(UStateNode* StartNode) const;
    
    UFUNCTION(BlueprintCallable, Category = "Debug")
    void DebugPrintModel() const;


    virtual void PostInitProperties() override;

    TArray<UStateNode*> PreImageUniversal(const TArray<UStateNode*>& states, TArray<UStateNode*>& targetStates) const;

    TArray<UStateNode*> PreImageExistential(const TArray<UStateNode*>& states, TArray<UStateNode*>& targetStates) const;

    TArray<UStateNode*> EvaluateUniversalG(TArray<UStateNode*>& targetStates, bool universalCheck = true) const;

    UFUNCTION(BlueprintCallable, Category = "Model")
    TMap<FString, FActionsToNode> EvaluateFormula(UStateNode* node, UCTLFormula* formula, bool ShortestPath);

    void UpdateModel(UStateNode* node, UCTLFormula* formula, TMap<FString, int32>& unsatScores, int32 depth, int32 MAX_UNSAT_SCORE);

private:
    UPROPERTY()
    TMap<FString, UStateNode*> stateNodes;

    UPROPERTY()
    UStateNode* rootNode;

    UPROPERTY()
    TMap<int32, UCTLFormula*> Formulas;

    UPROPERTY()
    UPredicateManager* PredicateManager;

    TSharedPtr<FJsonObject> JsonFile;

    UPROPERTY()
    TMap<ECharacterActions, float> PlayerActionRates;
};
