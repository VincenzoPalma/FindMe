#include "../Public/Model/StateTree/StateTreeUtils.h"

bool UStateTreeUtils::VerifyEGFormula(UStateNode* root, TFunction<bool(UStateNode*)> predicate) {
    if (!root) return false;

    TArray<UStateNode*> toVisit;
    toVisit.Add(root);

    while (toVisit.Num() > 0) {
        UStateNode* currentNode = toVisit.Pop();

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
                pathStack.Add(child);
            }
        }

        if (allStatesSatisfy) {
            return true;
        }

        for (UStateNode* child : currentNode->GetChildren()) {
            toVisit.Add(child);
        }
    }

    return false;
}

bool UStateTreeUtils::VerifyAGFormula(UStateNode* root, TFunction<bool(UStateNode*)> predicate) {
    if (!root) return false;

    TArray<UStateNode*> toVisit;
    toVisit.Add(root);

    while (toVisit.Num() > 0) {
        UStateNode* currentNode = toVisit.Pop();

        if (!predicate(currentNode)) {
            return false;
        }

        for (UStateNode* child : currentNode->GetChildren()) {
            toVisit.Add(child);
        }
    }
    return true;
}

bool UStateTreeUtils::VerifyAFFormula(UStateNode* root, TFunction<bool(UStateNode*)> predicate) {
    if (!root) return false;

    TArray<UStateNode*> toVisit;
    toVisit.Add(root);

    while (toVisit.Num() > 0) {
        UStateNode* currentNode = toVisit.Pop();

        TArray<UStateNode*> pathStack;
        pathStack.Add(currentNode);

        bool pathContainsValidState = false;
        while (pathStack.Num() > 0) {
            UStateNode* pathNode = pathStack.Pop();

            if (predicate(pathNode)) {
                pathContainsValidState = true;
                break;
            }

            for (UStateNode* child : pathNode->GetChildren()) {
                pathStack.Add(child);
            }
        }

        if (!pathContainsValidState) {
            return false;
        }

        for (UStateNode* child : currentNode->GetChildren()) {
            toVisit.Add(child);
        }
    }

    return true;
}

bool UStateTreeUtils::VerifyEFFormula(UStateNode* root, TFunction<bool(UStateNode*)> predicate) {
    if (!root) return false;

    TQueue<UStateNode*> toVisit;
    toVisit.Enqueue(root);

    UStateNode* currentNode;
    while (toVisit.Dequeue(currentNode)) {
        if (predicate(currentNode)) {
            return true;
        }

        for (UStateNode* child : currentNode->GetChildren()) {
            toVisit.Enqueue(child);
        }
    }

    return false;
}

bool UStateTreeUtils::VerifyIfAnyChild(UStateNode* root, TFunction<bool(UStateNode*)> predicate) {
    if (!root) return false;

    for (UStateNode* child : root->GetChildren()) {
        if (predicate(child)) {
            return true;
        }
    }

    return false;
}

bool UStateTreeUtils::VerifyIfAllChildren(UStateNode* root, TFunction<bool(UStateNode*)> predicate) {
    if (!root) return false;

    for (UStateNode* child : root->GetChildren()) {
        if (!predicate(child)) {
            return false;
        }
    }
    return true;
}

bool UStateTreeUtils::VerifyAUFormula(UStateNode* root, TFunction<bool(UStateNode*)> predicateA, TFunction<bool(UStateNode*)> predicateB) {
    if (!root) return false;

    TQueue<UStateNode*> toVisit;
    toVisit.Enqueue(root);

    while (!toVisit.IsEmpty()) {
        UStateNode* currentNode;
        toVisit.Dequeue(currentNode);

        TQueue<UStateNode*> pathQueue;
        pathQueue.Enqueue(currentNode);
        bool pathSatisfiesPsi = false;

        // Verifies if a path where predicateB is true exists
        while (!pathQueue.IsEmpty()) {
            UStateNode* pathNode;
            pathQueue.Dequeue(pathNode);

            if (predicateB(pathNode)) {
                pathSatisfiesPsi = true;
                break;
            }

            for (UStateNode* child : pathNode->GetChildren()) {
                pathQueue.Enqueue(child);
            }
        }

        if (!pathSatisfiesPsi) {
            return false;
        }

        // Verifies if predicateA is true in every state that leads to the state where predicateB is true
        pathQueue.Enqueue(currentNode);
        while (!pathQueue.IsEmpty()) {
            UStateNode* pathNode;
            pathQueue.Dequeue(pathNode);

            if (!predicateA(pathNode)) {
                return false;
            }

            for (UStateNode* child : pathNode->GetChildren()) {
                pathQueue.Enqueue(child);
            }
        }
    }

    return true;
}

bool UStateTreeUtils::VerifyEUFormula(UStateNode* root, TFunction<bool(UStateNode*)> predicateA, TFunction<bool(UStateNode*)> predicateB) {
    if (!root) return false;

    TQueue<UStateNode*> toVisit;
    toVisit.Enqueue(root);

    while (!toVisit.IsEmpty()) {
        UStateNode* currentNode;
        toVisit.Dequeue(currentNode);

        TQueue<UStateNode*> pathQueue;
        pathQueue.Enqueue(currentNode);
        bool pathSatisfiesPsi = false;

        // Verifies if a path where predicateB is true exists
        while (!pathQueue.IsEmpty()) {
            UStateNode* pathNode;
            pathQueue.Dequeue(pathNode);

            if (predicateB(pathNode)) {
                pathSatisfiesPsi = true;
                break;
            }

            for (UStateNode* child : pathNode->GetChildren()) {
                pathQueue.Enqueue(child);
            }
        }

        if (pathSatisfiesPsi) {
            // Verifies if predicateA is true in every state that leads to the state where predicateB is true
            pathQueue.Enqueue(currentNode);
            while (!pathQueue.IsEmpty()) {
                UStateNode* pathNode;
                pathQueue.Dequeue(pathNode);

                if (!predicateA(pathNode)) {
                    return false;
                }

                for (UStateNode* child : pathNode->GetChildren()) {
                    pathQueue.Enqueue(child);
                }
            }

            return true;
        }

        for (UStateNode* child : currentNode->GetChildren()) {
            toVisit.Enqueue(child);
        }
    }

    return false;
}
