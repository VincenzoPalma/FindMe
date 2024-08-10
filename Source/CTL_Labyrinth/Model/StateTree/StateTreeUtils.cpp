#include "StateTreeUtils.h"

bool UStateTreeUtils::VerifyEGFormula(UStateNode* root, TFunction<bool(UStateNode*)> evaluate) {
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

            if (!evaluate(pathNode)) {
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

bool UStateTreeUtils::VerifyAGFormula(UStateNode* root, TFunction<bool(UStateNode*)> evaluate) {
    if (!root) return false;

    TArray<UStateNode*> toVisit;
    toVisit.Add(root);

    while (toVisit.Num() > 0) {
        UStateNode* currentNode = toVisit.Pop();

        if (!evaluate(currentNode)) {
            return false;
        }

        for (UStateNode* child : currentNode->GetChildren()) {
            toVisit.Add(child);
        }
    }
    return true;
}

bool UStateTreeUtils::VerifyAFFormula(UStateNode* root, TFunction<bool(UStateNode*)> evaluate) {
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

            if (evaluate(pathNode)) {
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

bool UStateTreeUtils::VerifyEFFormula(UStateNode* root, TFunction<bool(UStateNode*)> evaluate) {
    if (!root) return false;

    TQueue<UStateNode*> toVisit;
    toVisit.Enqueue(root);

    UStateNode* currentNode;
    while (toVisit.Dequeue(currentNode)) {
        if (evaluate(currentNode)) {
            return true;
        }

        for (UStateNode* child : currentNode->GetChildren()) {
            toVisit.Enqueue(child);
        }
    }

    return false;
}

bool UStateTreeUtils::VerifyIfAnyChild(UStateNode* root, TFunction<bool(UStateNode*)> evaluate) {
    if (!root) return false;

    for (UStateNode* child : root->GetChildren()) {
        if (evaluate(child)) {
            return true;
        }
    }

    return false;
}

bool UStateTreeUtils::VerifyIfAllChildren(UStateNode* root, TFunction<bool(UStateNode*)> evaluate) {
    if (!root) return false;

    for (UStateNode* child : root->GetChildren()) {
        if (!evaluate(child)) {
            return false;
        }
    }
    return true;
}
