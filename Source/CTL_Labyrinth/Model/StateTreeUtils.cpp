#include "StateTreeUtils.h"

bool StateTreeUtils::VerifyEGFormula(const std::shared_ptr<StateNode>& root, std::function<bool(const std::shared_ptr<StateNode>&)> evaluate) {
    if (!root) return false;

    std::stack<std::shared_ptr<StateNode>> toVisit;
    toVisit.push(root);

    while (!toVisit.empty()) {
        auto currentNode = toVisit.top();
        toVisit.pop();

        bool allStatesSatisfy = true;
        std::stack<std::shared_ptr<StateNode>> pathStack;
        pathStack.push(currentNode);

        while (!pathStack.empty()) {
            auto pathNode = pathStack.top();
            pathStack.pop();

            // If the current node does not verify the formula, this path is not valid
            if (!evaluate(pathNode)) {
                allStatesSatisfy = false;
                break;
            }

            for (const auto& child : pathNode->GetChildren()) {
                pathStack.push(child);
            }
        }

        // Returns true if all the states of the current path verify the formula
        if (allStatesSatisfy) {
            return true;
        }

        for (const auto& child : currentNode->GetChildren()) {
            toVisit.push(child);
        }
    }

    return false;
}

bool StateTreeUtils::VerifyAGFormula(const std::shared_ptr<StateNode>& root, std::function<bool(const std::shared_ptr<StateNode>&)> evaluate) {
    if (!root) return false;

    std::stack<std::shared_ptr<StateNode>> toVisit;
    toVisit.push(root);

    while (!toVisit.empty()) {
        auto currentNode = toVisit.top();
        toVisit.pop();

        // If the current node does not verify the formula, the formula is not valid
        if (!evaluate(currentNode)) {
            return false;
        }

        for (const auto& child : currentNode->GetChildren()) {
            toVisit.push(child);
        }
    }
    // Returns true if all states of all paths verify the formula
    return true;
}

bool StateTreeUtils::VerifyAFFormula(const std::shared_ptr<StateNode>& root, std::function<bool(const std::shared_ptr<StateNode>&)> evaluate) {
    if (!root) return false;

    std::stack<std::shared_ptr<StateNode>> toVisit;
    toVisit.push(root);

    while (!toVisit.empty()) {
        auto currentNode = toVisit.top();
        toVisit.pop();

        std::stack<std::shared_ptr<StateNode>> pathStack;
        pathStack.push(currentNode);

        bool pathContainsValidState = false;
        while (!pathStack.empty()) {
            auto pathNode = pathStack.top();
            pathStack.pop();

            // If the state verifies the formula, the path is valid
            if (evaluate(pathNode)) {
                pathContainsValidState = true;
                break;
            }

            for (const auto& child : pathNode->GetChildren()) {
                pathStack.push(child);
            }
        }

        // If the path is not valid, returns false
        if (!pathContainsValidState) {
            return false;
        }

        for (const auto& child : currentNode->GetChildren()) {
            toVisit.push(child);
        }
    }

    // Returns true if all paths have at least on state that verifies the formula
    return true;
}

bool StateTreeUtils::VerifyEFFormula(const std::shared_ptr<StateNode>& root, std::function<bool(const std::shared_ptr<StateNode>&)> evaluate) {
    if (!root) return false;

    std::queue<std::shared_ptr<StateNode>> toVisit;
    toVisit.push(root);

    while (!toVisit.empty()) {
        auto currentNode = toVisit.front();
        toVisit.pop();

        // Returns true if the current state of the current path verifies the formula
        if (evaluate(currentNode)) {
            return true;
        }

        for (const auto& child : currentNode->GetChildren()) {
            toVisit.push(child);
        }
    }

    // Return false there are no states in any path that verifies the formula
    return false;
}

bool StateTreeUtils::VerifyIfAnyChild(const std::shared_ptr<StateNode>& root, std::function<bool(const std::shared_ptr<StateNode>&)> evaluate) {
    if (!root) return false;

    for (const auto& child : root->GetChildren()) {
        if (evaluate(child)) {
            return true;
        }
    }

    return false;
}

bool StateTreeUtils::VerifyIfAllChildren(const std::shared_ptr<StateNode>& root, std::function<bool(const std::shared_ptr<StateNode>&)> evaluate) {
    if (!root) return false;

    for (const auto& child : root->GetChildren()) {
        if (!evaluate(child)) {
            return false;
        }
    }
    return true;
}