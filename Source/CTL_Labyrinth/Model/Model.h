#pragma once

#include <map>
#include <string>
#include <memory>
#include <unordered_map>
#include "ModelStructures.h"
#include "StateTree/StateNode.h"


class Model {
public:
    Model() : rootNode(nullptr) {}

    void AddState(const State& state);
    void AddTransition(const State& from, const State& to);

    std::shared_ptr<StateNode> GetRootNode() const {
        return rootNode;
    }

private:
    std::unordered_map<int, std::shared_ptr<StateNode>> stateNodes;
    std::shared_ptr<StateNode> rootNode;
};


