#include "AStar.h"

AStar::AStar()
{
}

AStar::~AStar()
{
}
/*
unsatScore deve essere 0 nello stato in cui (F x) x � soddisfatta
insieme al g score, quando incontriamo un nodo gi� messo nell'open set, invece di controllare solo il g score dobbiamo controllare anche la preferenza dell'utente (la prob che l'utente faccia una certa azione)
*/
TMap<FString, FActionsToNode> AStar::ExecuteAStar(UCTLModel* model, UStateNode* startingNode, UCTLFormula* formula, bool ShortestPath)
{
	//Structures for the path, if found
	UStateNode* bestNode = NULL;
	TMap<FString, FActionsToNode> finalPath;
	TMap<FString, FActionsToNode> cameFrom; //le key sono gli id dei nodi figlio, i value gli id dei nodi padre
	//Initialization and evaluation of the score for the starting state
	int MAX_UNSAT_SCORE = 12;
	float MAX_PATH_COST = MAX_UNSAT_SCORE;
	int subFormulasNum = formula->CountSubformulas();
	int subFormulaWeight = MAX_UNSAT_SCORE / subFormulasNum;
	TMap<FString, int32> unsatScores;

	unsatScores.Add(startingNode->GetState().Id, MAX_UNSAT_SCORE);
	formula->Evaluate(model, startingNode, unsatScores, subFormulaWeight);
	ECTLOperator formulaOp = formula->GetOperator();

	bool found = false;
	int totalDepth = 0, bestValue = MAX_int32;
	int MAX_DEPTH = (formulaOp == ECTLOperator::EX || formulaOp == ECTLOperator::AX) ? 1 : 4;

	//Initialization of the pathCost and HeuristicTotalCosts values for the starting state
	TMap<FString, float> pathCost;
	TMap<FString, int32> HeuristicTotalCosts;
	FString startingNodeId = startingNode->GetState().Id;

	UpdatePathCosts(pathCost, startingNodeId, ShortestPath ? 0 : MAX_PATH_COST);
	UpdateHeuristicTotalCosts(HeuristicTotalCosts, startingNodeId, pathCost, unsatScores);

	//Initialization of the priority queue
	TArray<UStateNode*> openSet;
	AddToOpenSet(openSet, startingNode, HeuristicTotalCosts);

	TSet<UStateNode*> closedSet;

	//Main loop
	while (!openSet.IsEmpty() && !found) {
		//The state in position 0 will always be the best choice
		UStateNode* currentNode = openSet[0];
		openSet.RemoveAt(0);

		//Get the adjacent states, updating the model and initializing their scores
		if (currentNode->GetChildren().IsEmpty() && totalDepth < MAX_DEPTH)
		{
			model->UpdateModel(currentNode, formula, unsatScores, MAX_DEPTH, MAX_UNSAT_SCORE);
			formula->Evaluate(model, currentNode, unsatScores, subFormulaWeight);

			InitializeScores(unsatScores, pathCost, HeuristicTotalCosts);

			totalDepth = MAX_DEPTH;
		}

		//Add state to closed set so that it will not be visited in the future
		closedSet.Add(currentNode);

		if (*unsatScores.Find(currentNode->GetState().Id) == 0 && ShortestPath) {
			bestNode = currentNode;
			found = true;
		}
		else if (*HeuristicTotalCosts.Find(currentNode->GetState().Id) < bestValue) {
			bestNode = currentNode;
			bestValue = *HeuristicTotalCosts.Find(currentNode->GetState().Id);
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
			float tentative_pathCost = *pathCost.Find(currentNode->GetState().Id) + (ShortestPath ? MAX_PATH_COST/MAX_DEPTH : - MAX_PATH_COST / MAX_DEPTH)
				+ *(model->GetPlayerActionRates().Find(Pair.Key.Keys[0])); //1 in this case. The weight of the edge generally.
			//Update the scores and add the state to the cameFrom map, used to build the resulting path
			if (tentative_pathCost < *pathCost.Find(nodeId)) {
				
				UpdatePathCosts(pathCost, nodeId, tentative_pathCost);
				UpdateHeuristicTotalCosts(HeuristicTotalCosts, nodeId, pathCost, unsatScores);
				FActionsToNode ActToNode;
				ActToNode.ToNodeId = currentNode->GetState().Id;
				ActToNode.Actions = Pair.Key.Keys;
				cameFrom.Add(nodeId, ActToNode);

				//Add it to the priority queue
				if (!openSet.Contains(node))
				{
					AddToOpenSet(openSet, node, HeuristicTotalCosts);
				}
			}
		}
	}

	finalPath = ReconstructPath(bestNode->GetState().Id, cameFrom);
	return finalPath;
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

void AStar::UpdatePathCosts(TMap<FString, float>& pathCost, FString nodeId, float newValue)
{
	pathCost.Remove(nodeId);
	pathCost.Add(nodeId, newValue);
}

void AStar::UpdateHeuristicTotalCosts(TMap<FString, int32>& HeuristicTotalCosts, FString nodeId, TMap<FString, float>& pathCost, TMap<FString, int32>& statesScores)
{
	HeuristicTotalCosts.Remove(nodeId);
	HeuristicTotalCosts.Add(nodeId, *pathCost.Find(nodeId) + *statesScores.Find(nodeId));
}

TMap<FString, FActionsToNode> AStar::ReconstructPath(FString currentNodeId, const TMap<FString, FActionsToNode>& cameFrom)
{
	TMap<FString, FActionsToNode> totalPath;

	while (cameFrom.Contains(currentNodeId))
	{
		FActionsToNode ActToNode;
		ActToNode = *cameFrom.Find(currentNodeId);
		FString ParentNodeId = ActToNode.ToNodeId;
		ActToNode.ToNodeId = currentNodeId;
		totalPath.Add(ParentNodeId, ActToNode);

		currentNodeId = ParentNodeId;
	}

	return totalPath;
}

void AStar::InitializeScores(const TMap<FString, int32>& unsatScores, TMap<FString, float>& pathCost, TMap<FString, int32>& HeuristicTotalCosts)
{
	for (const TPair<FString, int32>& entry : unsatScores)
	{
		FString key = entry.Key;

		if (!pathCost.Contains(key)) {
			pathCost.Add(key, INFINITY);
		}
		if (!HeuristicTotalCosts.Contains(key)) {
			HeuristicTotalCosts.Add(key, MAX_int32);
		}
	}
}
