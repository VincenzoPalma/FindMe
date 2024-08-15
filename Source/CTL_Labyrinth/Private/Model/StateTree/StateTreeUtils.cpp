#include "../Public/Model/StateTree/StateTreeUtils.h"

TArray<UStateNode*> UStateTreeUtils::PreImageExistential(const UCTLModel* model, const TArray<UStateNode*>& states)
{
    TArray<UStateNode*> PreImage;

    const TMap<int32, UStateNode*>& StateNodes = model->GetStateNodes();

    for (const auto& StateNodeEntry : StateNodes)
    {
        UStateNode* StateNode = StateNodeEntry.Value;

        bool HasSuccessorInQ = false;
        for (UStateNode* Successor : StateNode->GetChildren())
        {
            if (states.Contains(Successor))
            {
                HasSuccessorInQ = true;
                break;
            }
        }

        if (HasSuccessorInQ)
        {
            PreImage.Add(StateNode);
        }
    }

    return PreImage;
}

TArray<UStateNode*> UStateTreeUtils::PreImageUniversal(const UCTLModel* model, const TArray<UStateNode*>& states)
{
    TArray<UStateNode*> PreImage;

    const TMap<int32, UStateNode*>& StateNodes = model->GetStateNodes();

    for (const auto& StateNodeEntry : StateNodes)
    {
        UStateNode* StateNode = StateNodeEntry.Value;

        bool AllSuccessorsInQ = true;
        for (UStateNode* Successor : StateNode->GetChildren())
        {
            if (!states.Contains(Successor))
            {
                AllSuccessorsInQ = false;
                break;
            }
        }

        if (AllSuccessorsInQ)
        {
            PreImage.Add(StateNode);
        }
    }

    return PreImage;
}

