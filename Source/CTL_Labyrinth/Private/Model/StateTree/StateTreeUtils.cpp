#include "../Public/Model/StateTree/StateTreeUtils.h"

TArray<UStateNode*> UStateTreeUtils::VerifyEGFormula(UStateNode* root, TFunction<bool(UStateNode*)> predicate) {
    TArray<UStateNode*> satisfyingStates;
    TSet<UStateNode*> visitedNodes;
    TArray<UStateNode*> toVisit;

    if (!root) return satisfyingStates;

    toVisit.Add(root);

    while (toVisit.Num() > 0) {
        UStateNode* currentNode = toVisit.Pop();

        // Check if the node has already been visited
        if (visitedNodes.Contains(currentNode)) {
            continue;
        }

        visitedNodes.Add(currentNode);

        bool allStatesSatisfy = true;
        TArray<UStateNode*> pathStack;
        pathStack.Add(currentNode);

        while (pathStack.Num() > 0) {
            UStateNode* pathNode = pathStack.Pop();

            if (!predicate(pathNode)) {
                allStatesSatisfy = false;
                break;
            }

            for (UStateNode* child : pathNode->GetChildren()) {
                if (!visitedNodes.Contains(child) && !pathStack.Contains(child)) {
                    pathStack.Add(child);
                }
            }
        }

        if (allStatesSatisfy) {
            satisfyingStates.Add(currentNode);
        }

        for (UStateNode* child : currentNode->GetChildren()) {
            if (!visitedNodes.Contains(child) && !toVisit.Contains(child)) {
                toVisit.Add(child);
            }
        }
    }

    return satisfyingStates; // Return the list of nodes where the formula is satisfied
}


TArray<UStateNode*> UStateTreeUtils::VerifyAGFormula(UStateNode* startNode, TFunction<bool(UStateNode*)> predicate)
{
    TArray<UStateNode*> satisfiedNodes;
    TSet<UStateNode*> visitedNodes;
    TArray<UStateNode*> toVisit;

    if (!startNode) return satisfiedNodes;

    toVisit.Add(startNode);

    while (toVisit.Num() > 0)
    {
        UStateNode* currentNode = toVisit.Pop();

        // Skip nodes that have already been visited
        if (visitedNodes.Contains(currentNode))
        {
            continue;
        }

        visitedNodes.Add(currentNode);

        // Check if the current node satisfies the predicate
        if (predicate(currentNode))
        {
            satisfiedNodes.Add(currentNode); // Add node to the list if predicate is satisfied
        }

        for (UStateNode* child : currentNode->GetChildren())
        {
            if (!visitedNodes.Contains(child))
            {
                toVisit.Add(child);
            }
        }
    }

    return satisfiedNodes; // Return the list of nodes where the formula is satisfied
}


TArray<UStateNode*> UStateTreeUtils::VerifyAFFormula(UStateNode* root, TFunction<bool(UStateNode*)> predicate)
{
    TArray<UStateNode*> satisfiedNodes;
    TSet<UStateNode*> visitedNodes;
    TArray<UStateNode*> toVisit;

    if (!root) return satisfiedNodes;

    toVisit.Add(root);

    while (toVisit.Num() > 0)
    {
        UStateNode* currentNode = toVisit.Pop();

        // Skip nodes that have already been visited
        if (visitedNodes.Contains(currentNode))
        {
            continue;
        }

        visitedNodes.Add(currentNode);

        bool pathContainsValidState = false;
        TArray<UStateNode*> pathStack;
        pathStack.Add(currentNode);

        // Traverse the current path to find if any node satisfies the predicate
        while (pathStack.Num() > 0)
        {
            UStateNode* pathNode = pathStack.Pop();

            if (predicate(pathNode))
            {
                pathContainsValidState = true;
                satisfiedNodes.Add(pathNode); // Add the node where the predicate is satisfied
                break;
            }

            for (UStateNode* child : pathNode->GetChildren())
            {
                pathStack.Add(child);
            }
        }

        if (!pathContainsValidState)
        {
            continue;
        }

        for (UStateNode* child : currentNode->GetChildren())
        {
            if (!visitedNodes.Contains(child))
            {
                toVisit.Add(child);
            }
        }
    }

    return satisfiedNodes; // Return the list of nodes where the formula is satisfied
}


TArray<UStateNode*> UStateTreeUtils::VerifyEFFormula(UStateNode* root, TFunction<bool(UStateNode*)> predicate)
{
    TArray<UStateNode*> satisfiedNodes;
    TQueue<UStateNode*> toVisit;

    if (!root) return satisfiedNodes;

    toVisit.Enqueue(root);

    UStateNode* currentNode;
    while (toVisit.Dequeue(currentNode))
    {
        // Check if the current node satisfies the predicate
        if (predicate(currentNode))
        {
            satisfiedNodes.Add(currentNode);
        }

        for (UStateNode* child : currentNode->GetChildren())
        {
            toVisit.Enqueue(child);
        }
    }

    return satisfiedNodes; // Return the list of nodes where the formula is satisfied
}


TArray<UStateNode*> UStateTreeUtils::VerifyIfAnyChild(UStateNode* root, TFunction<bool(UStateNode*)> predicate)
{
    TArray<UStateNode*> satisfiedNodes;

    if (!root) return satisfiedNodes;

    for (UStateNode* child : root->GetChildren())
    {
        if (predicate(child))
        {
            satisfiedNodes.Add(child);
        }
    }

    return satisfiedNodes;
}


TArray<UStateNode*> UStateTreeUtils::VerifyIfAllChildren(UStateNode* root, TFunction<bool(UStateNode*)> predicate)
{
    TArray<UStateNode*> satisfiedNodes;

    if (!root) return satisfiedNodes;

    bool allSatisfy = true;

    for (UStateNode* child : root->GetChildren())
    {
        if (predicate(child))
        {
            satisfiedNodes.Add(child);
        }
        else
        {
            allSatisfy = false;
        }
    }

    return allSatisfy ? satisfiedNodes : TArray<UStateNode*>();
}


TArray<UStateNode*> UStateTreeUtils::VerifyAUFormula(UStateNode* root, TFunction<bool(UStateNode*)> predicateA, TFunction<bool(UStateNode*)> predicateB)
{
    TArray<UStateNode*> satisfyingNodes;

    if (!root) return satisfyingNodes;

    TSet<UStateNode*> visitedNodes;
    TQueue<UStateNode*> toVisit;
    toVisit.Enqueue(root);

    while (!toVisit.IsEmpty())
    {
        UStateNode* currentNode;
        toVisit.Dequeue(currentNode);

        TSet<UStateNode*> pathNodes;
        TQueue<UStateNode*> pathQueue;
        pathQueue.Enqueue(currentNode);
        bool pathSatisfiesPsi = false;

        // Check if there is a path where predicateB is true
        while (!pathQueue.IsEmpty())
        {
            UStateNode* pathNode;
            pathQueue.Dequeue(pathNode);

            if (predicateB(pathNode))
            {
                pathSatisfiesPsi = true;
                break;
            }

            for (UStateNode* child : pathNode->GetChildren())
            {
                if (!pathNodes.Contains(child)) // Ensure we don't revisit nodes in this path
                {
                    pathQueue.Enqueue(child);
                    pathNodes.Add(child);
                }
            }
        }

        if (!pathSatisfiesPsi)
        {
            continue; // Skip this node if no path satisfies predicateB
        }

        // Verify if predicateA is true in every state that leads to the state where predicateB is true
        pathQueue.Enqueue(currentNode);
        pathNodes.Add(currentNode);
        bool allStatesSatisfyA = true;

        while (!pathQueue.IsEmpty())
        {
            UStateNode* pathNode;
            pathQueue.Dequeue(pathNode);

            if (!predicateA(pathNode))
            {
                allStatesSatisfyA = false;
                break;
            }

            for (UStateNode* child : pathNode->GetChildren())
            {
                if (!pathNodes.Contains(child)) // Ensure we don't revisit nodes in this path
                {
                    pathQueue.Enqueue(child);
                    pathNodes.Add(child);
                }
            }
        }

        // If all states in the path satisfy predicateA, add the starting node to the result
        if (allStatesSatisfyA)
        {
            satisfyingNodes.Add(currentNode);
        }

        // Mark the current node as visited to avoid reprocessing it
        visitedNodes.Add(currentNode);
    }

    return satisfyingNodes; // Return the array of nodes that satisfy the formula
}


TArray<UStateNode*> UStateTreeUtils::VerifyEUFormula(UStateNode* root, TFunction<bool(UStateNode*)> predicateA, TFunction<bool(UStateNode*)> predicateB)
{
    TArray<UStateNode*> satisfyingNodes;

    if (!root) return satisfyingNodes;

    TSet<UStateNode*> visitedNodes;
    TQueue<UStateNode*> toVisit;
    toVisit.Enqueue(root);

    while (!toVisit.IsEmpty())
    {
        UStateNode* currentNode;
        toVisit.Dequeue(currentNode);

        // Use a set to track nodes visited in this particular search
        TSet<UStateNode*> pathNodes;
        TQueue<UStateNode*> pathQueue;
        pathQueue.Enqueue(currentNode);
        bool pathSatisfiesPsi = false;

        // Check if there is a path where predicateB is true
        while (!pathQueue.IsEmpty())
        {
            UStateNode* pathNode;
            pathQueue.Dequeue(pathNode);

            if (predicateB(pathNode))
            {
                pathSatisfiesPsi = true;
                break;
            }

            for (UStateNode* child : pathNode->GetChildren())
            {
                if (!pathNodes.Contains(child)) // Ensure we don't revisit nodes in this path
                {
                    pathQueue.Enqueue(child);
                    pathNodes.Add(child);
                }
            }
        }

        if (pathSatisfiesPsi)
        {
            // Verify if predicateA is true in every state that leads to the state where predicateB is true
            pathQueue.Enqueue(currentNode);
            bool allStatesSatisfyA = true;
            TSet<UStateNode*> allNodesInPath;

            while (!pathQueue.IsEmpty())
            {
                UStateNode* pathNode;
                pathQueue.Dequeue(pathNode);

                if (!predicateA(pathNode))
                {
                    allStatesSatisfyA = false;
                    break;
                }

                allNodesInPath.Add(pathNode);

                for (UStateNode* child : pathNode->GetChildren())
                {
                    if (!allNodesInPath.Contains(child)) // Ensure we don't revisit nodes in this path
                    {
                        pathQueue.Enqueue(child);
                        allNodesInPath.Add(child);
                    }
                }
            }

            // If all states in the path satisfy predicateA, add the starting node to the result
            if (allStatesSatisfyA)
            {
                satisfyingNodes.Add(currentNode);
            }
        }

        // Mark the current node as visited to avoid reprocessing it
        visitedNodes.Add(currentNode);

        for (UStateNode* child : currentNode->GetChildren())
        {
            if (!visitedNodes.Contains(child)) // Ensure we don't revisit nodes
            {
                toVisit.Enqueue(child);
            }
        }
    }

    return satisfyingNodes; // Return the array of nodes that satisfy the formula
}

