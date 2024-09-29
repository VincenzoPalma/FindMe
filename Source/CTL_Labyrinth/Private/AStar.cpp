#include "AStar.h"

AStar::AStar()
{
}

AStar::~AStar()
{
}

TArray<UStateNode*> AStar::ExecuteAStar(const UCTLModel* model, UStateNode* startingNode, TArray<UStateNode*> satisfyingStatesArray, TMap<int32, int32> statesScores)
{
	UE_LOG(LogTemp, Log, TEXT("INIZIO"));
	TArray<UStateNode*> finalPath;
	TMap<int32, UStateNode*> cameFrom;


	TMap<int32, int32> gScores;
	TMap<int32, int32> fScores;
	InitializeScores(statesScores, gScores, fScores);
	int startingNodeId = startingNode->GetState().Id;
	gScores.Add(startingNodeId, 0);
	fScores.Add(startingNodeId, *statesScores.Find(startingNodeId));

	TArray<UStateNode*> openSet;
	AddToOpenSet(openSet, startingNode, fScores);

	TSet<UStateNode*> closedSet;

	UE_LOG(LogTemp, Log, TEXT("Score e set impostati"));

	while (!openSet.IsEmpty()) {
		UE_LOG(LogTemp, Log, TEXT("Inizio Ciclo Esterno"));
		UStateNode* currentNode = openSet[0];
		openSet.RemoveAt(0);

		if (satisfyingStatesArray.Contains(currentNode)) {
			UE_LOG(LogTemp, Log, TEXT("TROVATO"));
			finalPath = ReconstructPath(currentNode, cameFrom);
			return finalPath;
		}

		closedSet.Add(currentNode);

		for (UStateNode* node : currentNode->GetChildren()) {
			UE_LOG(LogTemp, Log, TEXT("Inizio ciclo interno"));
			int nodeId = node->GetState().Id;

			if (closedSet.Contains(node)) {
				continue;
			}
			int tentative_gScore = *gScores.Find(currentNode->GetState().Id) + 1; //1 in questo caso, ma in generale è il peso dell'arco per arrivare a node
			UE_LOG(LogTemp, Log, TEXT("INIZIO CONTROLLO"));
			if (tentative_gScore < *gScores.Find(nodeId)) {
				UE_LOG(LogTemp, Log, TEXT("DENTRO 1"));
				UpdateGScores(gScores, nodeId, tentative_gScore);
				UpdateFScores(fScores, nodeId, gScores, statesScores);
				cameFrom.Add(nodeId, currentNode);

				if (!openSet.Contains(node))
				{
					UE_LOG(LogTemp, Log, TEXT("DENTRO 2"));
					AddToOpenSet(openSet, node, statesScores);
				}
			}
			UE_LOG(LogTemp, Log, TEXT("FINE CONTROLLO"));
			UE_LOG(LogTemp, Log, TEXT("Fine ciclo interno"));
		}
		UE_LOG(LogTemp, Log, TEXT("Fine Ciclo Esterno"));
	}
	UE_LOG(LogTemp, Log, TEXT("FINE"));
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
	gScores.Add(nodeId, newValue);
}

void AStar::UpdateFScores(TMap<int32, int32>& fScores, int nodeId, TMap<int32, int32>& gScores, TMap<int32, int32>& statesScores)
{
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

		gScore.Add(key, MAX_int32);
		fScore.Add(key, MAX_int32);
	}
}
