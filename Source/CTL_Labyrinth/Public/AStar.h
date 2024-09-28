#pragma once

#include "CoreMinimal.h"
#include "Model/StateTree/StateNode.h"
#include "Model/CTLModel.h"
#include "Containers/Queue.h"
#include "Containers/Set.h"

class CTL_LABYRINTH_API AStar
{
public:
	AStar();
	~AStar();

	TArray<UStateNode*> ExecuteAStar(const UCTLModel* model, UStateNode* startingNode, TArray<UStateNode*> satisfyingStatesArray, TMap<int32, int32> statesScores);
	TArray <UStateNode*> AddToOpenSet(TArray <UStateNode*> openSet, UStateNode* node, TMap<int32, int32> statesScores);
	int g(UStateNode* node);
	void UpdateGScores(TMap<int32, int32>& gScores, int nodeId, int newValue);
	void UpdateFScores(TMap<int32, int32>& fScores, int nodeId, TMap<int32, int32>& gScores, TMap<int32, int32>& statesScores);
	TArray<UStateNode*> ReconstructPath(UStateNode* currentNode, const TMap<int32, UStateNode*>& cameFrom);
};
