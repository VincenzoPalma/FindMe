#include "AStar.h"

AStar::AStar()
{
}

AStar::~AStar()
{
}

TArray<UStateNode*> AStar::ExecuteAStar(const UCTLModel* model, UStateNode* startingNode, TArray<UStateNode*> satisfyingStatesArray, TMap<int32, int32> statesScores)
{
	TArray<UStateNode*> finalPath;
	TMap<int32, UStateNode*> cameFrom;

	TArray<UStateNode*> openSet;
	AddToOpenSet(openSet, startingNode, statesScores);

	TSet<UStateNode*> closedSet;

	TMap<int32, int32> gScores;
	gScores.Add(startingNode->GetState().Id, 0);

	TMap<int32, int32> fScores;
	fScores.Add(startingNode->GetState().Id, *statesScores.Find(startingNode->GetState().Id));

	while (!openSet.IsEmpty()) {
		UStateNode* currentNode = openSet[0];
		openSet.RemoveAt(0);

		if (satisfyingStatesArray.Contains(currentNode)) {
			finalPath = ReconstructPath(currentNode, cameFrom);
			return finalPath;
		}

		closedSet.Add(currentNode);

		for (UStateNode* node : currentNode->GetChildren()) {
			int nodeId = node->GetState().Id;
			if (!gScores.Contains(nodeId)) {
				gScores.Add(nodeId, INFINITY);
			}//???

			if (closedSet.Contains(node)) {
				continue;
			}

			int tentative_gScore = *gScores.Find(currentNode->GetState().Id) + 1;

			if (!openSet.Contains(node))
			{
				AddToOpenSet(openSet, node, statesScores);
				cameFrom.Add(nodeId, currentNode);
			}
			else if (tentative_gScore < *gScores.Find(nodeId)) {
				UpdateGScores(gScores, nodeId, tentative_gScore);
				UpdateFScores(fScores, nodeId, gScores, statesScores);
				cameFrom.Add(nodeId, currentNode);
			}
		}
	}

	return finalPath; //empty array
}

TArray<UStateNode*> AStar::AddToOpenSet(TArray<UStateNode*> openSet, UStateNode* node, TMap<int32, int32> statesScores)
{
	if (openSet.IsEmpty()) {
		openSet.Add(node);
	}
	else {
		int32 newNodeScore = *statesScores.Find(node->GetState().Id);

		bool added = false;
		for (int32 i = 0; i < openSet.Num(); ++i) {
			UStateNode* currentNode = openSet[i];
			int32 currentNodeScore = *statesScores.Find(currentNode->GetState().Id);

			if (newNodeScore < currentNodeScore) {
				openSet.Insert(node, i);
				added = true;
				break;
			}
		}

		if (!added) {
			openSet.Add(node);
		}
	}
	return openSet;
}


int AStar::g(UStateNode* node)
{
	return 0;
}

void AStar::UpdateGScores(TMap<int32, int32>& gScores, int nodeId, int newValue)
{
	gScores.Remove(nodeId);
	gScores.Add(nodeId, newValue);
}

void AStar::UpdateFScores(TMap<int32, int32>& fScores, int nodeId, TMap<int32, int32>& gScores, TMap<int32, int32>& statesScores)
{
	fScores.Remove(nodeId);
	fScores.Add(nodeId, *gScores.Find(nodeId) + *statesScores.Find(nodeId));
}

TArray<UStateNode*> AStar::ReconstructPath(UStateNode* currentNode, const TMap<int32, UStateNode*>& cameFrom)
{
	TArray<UStateNode*> totalPath;
	totalPath.Add(currentNode);

	while (cameFrom.Contains(currentNode->GetState().Id))
	{
		currentNode = cameFrom[currentNode->GetState().Id];
		totalPath.Add(currentNode);
	}

	Algo::Reverse(totalPath);
	return totalPath;
}
