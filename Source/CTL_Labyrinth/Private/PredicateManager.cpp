#include "PredicateManager.h"

void UPredicateManager::RegisterPredicate(const FString& PredicateName, PredicateFunction InPredicate)
{
    Predicates.Add(PredicateName, InPredicate);
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