#pragma once

#include <queue>
#include <stack>
#include <functional>
#include <unordered_set>
#include "StateNode.h"

class StateTreeUtils {
public:
    static bool VerifyEFFormula(const std::shared_ptr<StateNode>& root, std::function<bool(const std::shared_ptr<StateNode>&)> evaluate);

    static bool VerifyAFFormula(const std::shared_ptr<StateNode>& root, std::function<bool(const std::shared_ptr<StateNode>&)> evaluate);

    static bool VerifyEGFormula(const std::shared_ptr<StateNode>& root, std::function<bool(const std::shared_ptr<StateNode>&)> evaluate);

    static bool VerifyAGFormula(const std::shared_ptr<StateNode>& root, std::function<bool(const std::shared_ptr<StateNode>&)> evaluate);

    static bool VerifyIfAnyChild(const std::shared_ptr<StateNode>& root, std::function<bool(const std::shared_ptr<StateNode>&)> evaluate);

    static bool VerifyIfAllChildren(const std::shared_ptr<StateNode>& root, std::function<bool(const std::shared_ptr<StateNode>&)> evaluate);
};