#include "PredicateManager.h"

void UPredicateManager::RegisterPredicate(const FString& PredicateName, PredicateFunction InPredicate)
{
    Predicates.Add(PredicateName, InPredicate);
}

bool UPredicateManager::EvaluatePredicate(const FString& PredicateName, const FState& State) const
{
    const PredicateFunction* Predicate = Predicates.Find(PredicateName);
    if (Predicate)
    {
        return (*Predicate)(State);
    }
    return false; 
}

TFunction<bool(const FState&)> UPredicateManager::GetPredicate(const FString& Name) const
{
    const TFunction<bool(const FState&)>* Predicate = Predicates.Find(Name);
    if (Predicate)
    {
        return *Predicate;
    }
    return nullptr;
}