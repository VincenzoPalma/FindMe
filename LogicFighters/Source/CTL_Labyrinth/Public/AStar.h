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

	static TArray<UStateNode*> ExecuteAStar(UCTLModel* model, UStateNode* startingNode, UCTLFormula* formula);
	static void AddToOpenSet(TArray <UStateNode*>& openSet, UStateNode* node, TMap<FString, int32> HeuristicTotalCosts);
	static TArray<UStateNode*> ReconstructPath(UStateNode* currentNode, const TMap<FString, UStateNode*>& cameFrom);
	static void InitializeScores(const TMap<FString, int32>& unsatScores, TMap<FString, int32>& pathCost, TMap<FString, int32>& HeuristicTotalCosts);
	static void UpdatePathCosts(TMap<FString, int32>& pathCost, FString nodeId, int newValue);
	static void UpdateHeuristicTotalCosts(TMap<FString, int32>& HeuristicTotalCosts, FString nodeId, TMap<FString, int32>& pathCost, TMap<FString, int32>& unsatScores);
};
