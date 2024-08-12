#include "../Public/Model/CTLModel.h"

UCTLModel::UCTLModel()
    : rootNode(nullptr)
{
}

void UCTLModel::AddState(const FState& state)
{
    if (!stateNodes.Contains(state.Id))
    {
        UStateNode* NewNode = NewObject<UStateNode>();
        NewNode->SetStateData(state);

        stateNodes.Add(state.Id, NewNode);

        if (!rootNode)
        {
            rootNode = NewNode;
        }
    }
}

void UCTLModel::AddTransition(const FState& from, const FState& to)
{
    UStateNode** FromNode = stateNodes.Find(from.Id);
    UStateNode** ToNode = stateNodes.Find(to.Id);

    if (FromNode && ToNode)
    {
        (*FromNode)->AddChild(*ToNode);
    }
}

void UCTLModel::AddFormula(UCTLFormula* Formula)
{
    if (Formula)
    {
        Formulas.Add(Formula);
    }
}