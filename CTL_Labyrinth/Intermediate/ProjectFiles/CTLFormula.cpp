AtomicFormula::AtomicFormula(std::function<bool(const State&)> predicate) : predicate(predicate) {}

bool AtomicFormula::Evaluate(const std::shared_ptr<StateNode>& stateNode) const {
    return predicate(stateNode->GetState());
}

UnaryFormula::UnaryFormula(CTLOperator op, std::shared_ptr<CTLFormula> subFormula) : op(op), subFormula(subFormula) {}

bool UnaryFormula::Evaluate(const std::shared_ptr<StateNode>& stateNode) const {
    // Implementazione logica degli operatori unari come EX, AX, EF, ecc.
    switch (op)
    {
    case CTLOperator::NOT:
        return !subFormula->Evaluate(stateNode);
        break;
    case CTLOperator::EX:
        return StateTreeUtils::VerifyIfAnyChild(stateNode, [this](const std::shared_ptr<StateNode>& child) {
            return subFormula->Evaluate(child);
            });
        break;
    case CTLOperator::AX:
        return StateTreeUtils::VerifyIfAllChildren(stateNode, [this](const std::shared_ptr<StateNode>& child) {
            return subFormula->Evaluate(child);
            });
        break;
    case CTLOperator::EF:
        return StateTreeUtils::VerifyEFFormula(stateNode, [this](const std::shared_ptr<StateNode>& child) {
            return subFormula->Evaluate(child);
            });
        break;
    case CTLOperator::AF:
        return StateTreeUtils::VerifyAFFormula(stateNode, [this](const std::shared_ptr<StateNode>& child) {
            return subFormula->Evaluate(child);
            });
        break;
    case CTLOperator::EG:
        return StateTreeUtils::VerifyEGFormula(stateNode, [this](const std::shared_ptr<StateNode>& child) {
            return subFormula->Evaluate(child);
            });
        break;
    case CTLOperator::AG:
        return StateTreeUtils::VerifyAGFormula(stateNode, [this](const std::shared_ptr<StateNode>& child) {
            return subFormula->Evaluate(child);
            });
        break;
    default:
        break;
    }
}

BinaryFormula::BinaryFormula(CTLOperator op, std::shared_ptr<CTLFormula> left, std::shared_ptr<CTLFormula> right) : op(op), left(left), right(right) {}

bool BinaryFormula::Evaluate(const std::shared_ptr<StateNode>& stateNode) const {
    // Implementazione logica degli operatori binari come AND, OR, EU, AU, ecc.
    switch (op)
    {
    case CTLOperator::AND:
        return left->Evaluate(stateNode) && right->Evaluate(stateNode);
        break;
    case CTLOperator::OR:
        return left->Evaluate(stateNode) || right->Evaluate(stateNode);
        break;
    case CTLOperator::EU:
        break;
    case CTLOperator::AU:
        break;
    default:
        break;
    }
}