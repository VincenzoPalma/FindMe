#include "AStar.h"

AStar::AStar()
{
}

AStar::~AStar()
{
}
/*
unsatScore deve essere 0 nello stato in cui (F x) x è soddisfatta
insieme al g score, quando incontriamo un nodo già messo nell'open set, invece di controllare solo il g score dobbiamo controllare anche la preferenza dell'utente (la prob che l'utente faccia una certa azione)
*/
TMap<FString, FActionsToNode> AStar::ExecuteAStar(UCTLModel* model, UStateNode* startingNode, UCTLFormula* formula)
{
	UE_LOG(LogTemp, Warning, TEXT("SONO DISPERATO"));
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

	UpdatePathCosts(pathCost, startingNodeId, 0);
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

		if (*unsatScores.Find(currentNode->GetState().Id) == 0) {
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
			float tentative_pathCost = *pathCost.Find(currentNode->GetState().Id) + MAX_PATH_COST/MAX_DEPTH	+ *(model->GetPlayerActionRates().Find(Pair.Key.Keys[0])); //1 in this case. The weight of the edge generally.
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


TMap<FString, FActionsToNode> AStar::ExecuteBFS(UCTLModel* model, UStateNode* startingNode, UCTLFormula* formula)
{

	UE_LOG(LogTemp, Warning, TEXT("NODE ESTERNO"));
	FString bestNodeId = "";
	int bestValue = MAX_int32;

	//Structures for the path, if found
	TMap<FString, FActionsToNode> finalPath;
	TMap<FString, int32> NodeDepth;
	TMap<FString, TPair<FActionsArray, FString>> Predecessors;
	TMap<int32, TArray<FString>> NodesByDepth;

	//Initialization and evaluation of the score for the starting state
	int MAX_UNSAT_SCORE = 12;
	int subFormulasNum = formula->CountSubformulas();
	int subFormulaWeight = MAX_UNSAT_SCORE / subFormulasNum;
	TMap<FString, int32> unsatScores;

	unsatScores.Add(startingNode->GetState().Id, MAX_UNSAT_SCORE);
	formula->Evaluate(model, startingNode, unsatScores, subFormulaWeight);
	ECTLOperator formulaOp = formula->GetOperator();

	bool bTargetFound = false;
	int totalDepth = 0;
	int MAX_DEPTH = (formulaOp == ECTLOperator::EX || formulaOp == ECTLOperator::AX) ? 1 : 4;

	FString startingNodeId = startingNode->GetState().Id;

	//Initialization of the priority queue
	TArray<UStateNode*> openSet;
	AddToOpenSet(openSet, startingNode, unsatScores);

	NodeDepth.Add(startingNodeId, 0);

	//Get the adjacent states, updating the model and initializing their scores
	if (startingNode->GetChildren().IsEmpty() && totalDepth < MAX_DEPTH)
	{
		model->UpdateModel(startingNode, formula, unsatScores, MAX_DEPTH, MAX_UNSAT_SCORE);
		formula->Evaluate(model, startingNode, unsatScores, subFormulaWeight);

		totalDepth = MAX_DEPTH;
	}

	//BFS Algorithm
	while (!openSet.IsEmpty()) {
		//The state in position 0 will always be the best choice
		UStateNode* currentNode = openSet[0];
		openSet.RemoveAt(0);
		int32 CurrentDepth = *NodeDepth.Find(currentNode->GetState().Id);

		NodesByDepth.FindOrAdd(CurrentDepth).Add(currentNode->GetState().Id);

		for (const TPair<FActionsArray, UStateNode*>& Pair : currentNode->GetChildrenMap())
		{
			const FActionsArray& CurrActions = Pair.Key;
			UStateNode* Child = Pair.Value;

			if (!NodeDepth.Contains(Child->GetState().Id))
			{
				//it's only an estimate of the node lowest depth
				NodeDepth.Add(Child->GetState().Id, CurrentDepth + 1);
				Predecessors.Add(Child->GetState().Id, TPair<FActionsArray, FString>(CurrActions, currentNode->GetState().Id));
	
				openSet.Add(Child);
			}
			else if (model->GetPlayerActionRates().Find(CurrActions.Keys[0]) > model->GetPlayerActionRates().Find((*Predecessors.Find(Child->GetState().Id)).Key.Keys[0]))
			{
				Predecessors.Add(Child->GetState().Id, TPair<FActionsArray, FString>(CurrActions, currentNode->GetState().Id));
			}
		}
	}
	UE_LOG(LogTemp, Error, TEXT("NODE SATSDSDS"));
	for (int32 Depth = MAX_DEPTH; Depth >= 0 && !bTargetFound; --Depth)
	{
		if (TArray<FString>* NodesAtDepth = NodesByDepth.Find(Depth))
		{
			for (FString CurrentId : *NodesAtDepth)
			{
				UE_LOG(LogTemp, Error, TEXT("NODE SATSDSDS"));
				if (*unsatScores.Find(CurrentId) == 0)
				{
					UE_LOG(LogTemp, Error, TEXT("NODE SATSDSDS %s"), *bestNodeId);
					bestNodeId = CurrentId;
					bTargetFound = true;
					break;
				}
				else if (*unsatScores.Find(CurrentId) < bestValue)
				{
					bestNodeId = CurrentId;
					bestValue = *unsatScores.Find(CurrentId);
				}
			}
		}

		if (bTargetFound)
			break;
	}

	if (!bestNodeId.IsEmpty())
	{
		FString CurrentId = bestNodeId;
		while (!CurrentId.IsEmpty() && Predecessors.Contains(CurrentId))
		{
			TPair<FActionsArray, FString> Info = *Predecessors.Find(CurrentId);
			const FActionsArray& Actions = Info.Key;
			FString ParentId = Info.Value;

			FActionsToNode Entry(CurrentId, Actions.Keys);
			finalPath.Add(ParentId, Entry);

			CurrentId = ParentId;
		}
	}

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
