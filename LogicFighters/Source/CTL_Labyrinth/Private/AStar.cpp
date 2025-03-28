#include "AStar.h"

AStar::AStar()
{
}

AStar::~AStar()
{
}

TArray<UStateNode*> AStar::ExecuteAStar(UCTLModel* model, UStateNode* startingNode, UCTLFormula* formula)
{
	//Structures for the path, if found
	int totalDepth = 0, MAX_DEPTH = 6, MAX_UNSAT_SCORE = 12;
	UStateNode* bestNode;
	TArray<UStateNode*> finalPath;
	TMap<FString, UStateNode*> cameFrom;
	//Initialization and evaluation of the score for the starting state
	int subFormulasNum = formula->CountSubformulas();
	int subFormulaWeight = MAX_UNSAT_SCORE / subFormulasNum;
	TMap<FString, int32> unsatScores;
	unsatScores.Add(startingNode->GetState().Id, MAX_UNSAT_SCORE);
	formula->Evaluate(model, startingNode, unsatScores, subFormulaWeight);

	//Initialization of the g and f values for the starting state
	TMap<FString, int32> pathCost;
	TMap<FString, int32> HeuristicTotalCosts;
	FString startingNodeId = startingNode->GetState().Id;
	UpdatePathCosts(pathCost, startingNodeId, 0);
	UpdateHeuristicTotalCosts(HeuristicTotalCosts, startingNodeId, pathCost, unsatScores);

	//Initialization of the priority queue
	TArray<UStateNode*> openSet;
	AddToOpenSet(openSet, startingNode, HeuristicTotalCosts);

	TSet<UStateNode*> closedSet;

	//Main loop
	while (!openSet.IsEmpty()) {
		//The state in position 0 will always be the best choice
		UStateNode* currentNode = openSet[0];
		openSet.RemoveAt(0);

		//Get the adjacent states, updating the model and initializing their scores
		if (currentNode->GetChildren().IsEmpty() && totalDepth < MAX_DEPTH)
		{
			model->UpdateModel(currentNode, formula, unsatScores, MAX_DEPTH, MAX_UNSAT_SCORE);
			InitializeScores(unsatScores, pathCost, HeuristicTotalCosts);

			totalDepth = MAX_DEPTH;
		}
		else if (totalDepth == MAX_DEPTH)
		{
			finalPath = ReconstructPath(bestNode, cameFrom);
			return finalPath;
		}

		//Add state to closed set so that it will not be visited in the future
		closedSet.Add(currentNode);

		//If the current state satifies the entire formula, then it is a target state
		for (UStateNode* node : closedSet) {
			if (*unsatScores.Find(node->GetState().Id) == 0) {
				finalPath = ReconstructPath(currentNode, cameFrom);
				return finalPath;
			}
		}
		
		//Loop for each adjacent state of the current state
		for (const TPair<FActionsArray, UStateNode*> Pair : currentNode->GetChildrenMap()) {
			UStateNode* node = Pair.Value;
			FString nodeId = node->GetState().Id;

			//Skip it if it was already visited
			if (closedSet.Contains(node)) {
				continue;
			}

			//Calculate a possible new path cost
			int tentative_pathCost = *pathCost.Find(currentNode->GetState().Id) + 1; //1 in this case. The weight of the edge generally.
			//Update the scores and add the state to the cameFrom map, used to build the resulting path
			if (tentative_pathCost < *pathCost.Find(nodeId)) {
				currentNode->PreviousTurnActions = Pair.Key.Keys;
				UpdatePathCosts(pathCost, nodeId, tentative_pathCost);
				UpdateHeuristicTotalCosts(HeuristicTotalCosts, nodeId, pathCost, unsatScores);
				cameFrom.Add(nodeId, currentNode);

				//Add it to the priority queue
				if (!openSet.Contains(node))
				{
					AddToOpenSet(openSet, node, HeuristicTotalCosts);
				}
			}
		}
	}
	return finalPath; //Empty array if no path was found
}

void AStar::AddToOpenSet(TArray<UStateNode*>& openSet, UStateNode* node, TMap<FString, int32> HeuristicTotalCosts)
{
	if (openSet.IsEmpty()) {
		openSet.Add(node);
	}
	else {
		int32 newNodeScore = *HeuristicTotalCosts.Find(node->GetState().Id);

		bool added = false;
		for (int32 i = 0; i < openSet.Num(); ++i) {
			UStateNode* currentNode = openSet[i];
			int32 currentNodeScore = *HeuristicTotalCosts.Find(currentNode->GetState().Id);

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

void AStar::UpdatePathCosts(TMap<FString, int32>& pathCost, FString nodeId, int newValue)
{
	pathCost.Remove(nodeId);
	pathCost.Add(nodeId, newValue);
}

void AStar::UpdateHeuristicTotalCosts(TMap<FString, int32>& HeuristicTotalCosts, FString nodeId, TMap<FString, int32>& gScores, TMap<FString, int32>& statesScores)
{
	HeuristicTotalCosts.Remove(nodeId);
	HeuristicTotalCosts.Add(nodeId, *gScores.Find(nodeId) + *statesScores.Find(nodeId));
}

TArray<UStateNode*> AStar::ReconstructPath(UStateNode* currentNode, const TMap<FString, UStateNode*>& cameFrom)
{
	TArray<UStateNode*> totalPath;
	totalPath.Add(currentNode);

	while (cameFrom.Contains(currentNode->GetState().Id))
	{
		UStateNode* ParentNode = cameFrom[currentNode->GetState().Id];
		currentNode = ParentNode;
		totalPath.Add(currentNode);
	}

	Algo::Reverse(totalPath);
	return totalPath;
}

void AStar::InitializeScores(const TMap<FString, int32>& unsatScores, TMap<FString, int32>& pathCost, TMap<FString, int32>& HeuristicTotalCosts)
{
	for (const TPair<FString, int32>& entry : unsatScores)
	{
		FString key = entry.Key;

		if (!pathCost.Contains(key)) {
			pathCost.Add(key, MAX_int32);
		}
		if (!HeuristicTotalCosts.Contains(key)) {
			HeuristicTotalCosts.Add(key, MAX_int32);
		}
	}
}
