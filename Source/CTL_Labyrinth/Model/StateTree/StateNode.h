#pragma once

#include <vector>
#include <unordered_map>
#include <memory>
#include "ModelStructures.h"


class StateNode {
public:
    StateNode(const State& state) : StateData(state) {}

    void AddChild(std::shared_ptr<StateNode> child) {
        Children.push_back(child);
    }

    const std::vector<std::shared_ptr<StateNode>>& GetChildren() const {
        return Children;
    }

    const State& GetState() const {
        return StateData;
    }

private:
    State StateData;
    std::vector<std::shared_ptr<StateNode>> Children;
};