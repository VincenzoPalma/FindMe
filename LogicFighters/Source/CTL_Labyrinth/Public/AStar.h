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
	static void AddToOpenSet(TArray <UStateNode*>& openSet, UStateNode* node, TMap<FString, int32> fScores);
	static TArray<UStateNode*> ReconstructPath(UStateNode* currentNode, const TMap<FString, UStateNode*>& cameFrom);
	static void InitializeScores(const TMap<FString, int32>& statesScores, TMap<FString, int32>& gScore, TMap<FString, int32>& fScore);
	static void UpdateGScores(TMap<FString, int32>& gScores, FString nodeId, int newValue);
	static void UpdateFScores(TMap<FString, int32>& fScores, FString nodeId, TMap<FString, int32>& gScores, TMap<FString, int32>& statesScores);
};
