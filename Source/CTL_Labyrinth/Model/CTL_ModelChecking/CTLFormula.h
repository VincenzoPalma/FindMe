#pragma once

#include <functional>
#include <memory>
#include "../StateTree/StateNode.h"
#include "../StateTree/StateTreeUtils.h"

enum class CTLOperator {
    AND,
    OR,
    NOT,
    EX,
    AX,
    EF,
    AF,
    EG,
    AG,
    EU,
    AU
};

class CTLFormula {
public:
    virtual ~CTLFormula() = default;
    virtual bool Evaluate(const std::shared_ptr<StateNode>& node) const = 0;
};

class AtomicFormula : public CTLFormula {
public:
    AtomicFormula(std::function<bool(const State&)> predicate);
    bool Evaluate(const std::shared_ptr<StateNode>& node) const override;

private:
    std::function<bool(const State&)> predicate;
};

class UnaryFormula : public CTLFormula {
public:
    UnaryFormula(CTLOperator op, std::shared_ptr<CTLFormula> subFormula);
    bool Evaluate(const std::shared_ptr<StateNode>& node) const override;

private:
    CTLOperator op;
    std::shared_ptr<CTLFormula> subFormula;
};

class BinaryFormula : public CTLFormula {
public:
    BinaryFormula(CTLOperator op, std::shared_ptr<CTLFormula> left, std::shared_ptr<CTLFormula> right);
    bool Evaluate(const std::shared_ptr<StateNode>& node) const override;

private:
    CTLOperator op;
    std::shared_ptr<CTLFormula> left;
    std::shared_ptr<CTLFormula> right;
};
