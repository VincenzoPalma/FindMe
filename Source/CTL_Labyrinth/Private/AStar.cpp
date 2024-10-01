#include "AStar.h"

AStar::AStar()
{
}

AStar::~AStar()
{
}

TArray<UStateNode*> AStar::ExecuteAStar(UCTLModel* model, UStateNode* startingNode, TMap<int32, int32> statesScores, UCTLFormula* formula)
{
	TArray<UStateNode*> finalPath;
	TMap<int32, UStateNode*> cameFrom;


	TMap<int32, int32> gScores;
	TMap<int32, int32> fScores;
	InitializeScores(statesScores, gScores, fScores);
	int startingNodeId = startingNode->GetState().Id;
	UpdateGScores(gScores, startingNodeId, 0);
	UpdateFScores(fScores, startingNodeId, gScores, statesScores);

	TArray<UStateNode*> openSet;
	AddToOpenSet(openSet, startingNode, fScores);

	TSet<UStateNode*> closedSet;
	while (!openSet.IsEmpty()) {
		UStateNode* currentNode = openSet[0];
		openSet.RemoveAt(0);

		UE_LOG(LogTemp, Log, TEXT("Inizio Ciclo Esterno, ID: %d"), currentNode->GetState().Id);

		if (*statesScores.Find(currentNode->GetState().Id) == 0) {
			finalPath = ReconstructPath(currentNode, cameFrom);
			return finalPath;
		}
		if (currentNode->GetChildren().IsEmpty())
		{
			//statesScores.Empty();
			model->UpdateModel(currentNode, formula, statesScores);
			InitializeScores(statesScores, gScores, fScores);
		}

		closedSet.Add(currentNode);

		
		for (UStateNode* node : currentNode->GetChildren()) {
			int nodeId = node->GetState().Id;

			UE_LOG(LogTemp, Log, TEXT("Inizio ciclo interno, ID: %d"), nodeId);

			if (closedSet.Contains(node)) {
				continue;
			}

			int tentative_gScore = *gScores.Find(currentNode->GetState().Id) + 1; //1 in this case. The weight of the edge generally.
			if (tentative_gScore < *gScores.Find(nodeId)) {
				UpdateGScores(gScores, nodeId, tentative_gScore);
				UpdateFScores(fScores, nodeId, gScores, statesScores);
				cameFrom.Add(nodeId, currentNode);

				if (!openSet.Contains(node))
				{
					AddToOpenSet(openSet, node, fScores);
				}
			}
			UE_LOG(LogTemp, Log, TEXT("Fine ciclo interno"));
		}
		UE_LOG(LogTemp, Log, TEXT("Fine Ciclo Esterno"));
	}
	return finalPath; //empty array
}

void AStar::AddToOpenSet(TArray<UStateNode*>& openSet, UStateNode* node, TMap<int32, int32> fScores)
{
	if (openSet.IsEmpty()) {
		openSet.Add(node);
	}
	else {
		int32 newNodeScore = *fScores.Find(node->GetState().Id);

		bool added = false;
		for (int32 i = 0; i < openSet.Num(); ++i) {
			UStateNode* currentNode = openSet[i];
			int32 currentNodeScore = *fScores.Find(currentNode->GetState().Id);

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

void AStar::InitializeScores(const TMap<int32, int32>& statesScores, TMap<int32, int32>& gScore, TMap<int32, int32>& fScore)
{
	for (const TPair<int32, int32>& entry : statesScores)
	{
		int32 key = entry.Key;

		if (!gScore.Contains(key)) {
			gScore.Add(key, MAX_int32);
		}
		if (!fScore.Contains(key)) {
			fScore.Add(key, MAX_int32);
		}
	}
}
