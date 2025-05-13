#pragma once

#include "CoreMinimal.h"
#include "Model/StateTree/StateNode.h"
#include "Model/CTLModel.h"
#include "Model/ModelParser/ModelParser.h"
#include "Containers/Queue.h"
#include "Containers/Set.h"

class CTL_LABYRINTH_API AStar
{
public:
	AStar();
	~AStar();

	static TMap<FString, FActionsToNode> ExecuteAStar(UCTLModel* model, UStateNode* startingNode, UCTLFormula* formula);
	static TMap<FString, FActionsToNode> ExecuteBFS(UCTLModel* model, UStateNode* startingNode, UCTLFormula* formula);
	static void AddToOpenSet(TArray <UStateNode*>& openSet, UStateNode* node, TMap<FString, int32> HeuristicTotalCosts);
	static TMap<FString, FActionsToNode> ReconstructPath(FString currentNodeId, const TMap<FString, FActionsToNode>& cameFrom);
	static void InitializeScores(const TMap<FString, int32>& unsatScores, TMap<FString, float>& pathCost, TMap<FString, int32>& HeuristicTotalCosts);
	static void UpdatePathCosts(TMap<FString, float>& pathCost, FString nodeId, float newValue);
	static void UpdateHeuristicTotalCosts(TMap<FString, int32>& HeuristicTotalCosts, FString nodeId, TMap<FString, float>& pathCost, TMap<FString, int32>& unsatScores);
	static float NPCCounterAttackBonus(TArray<ECharacterActions> actionsTuple);
};
