#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CTLFormula.h"
#include "StateNode.h"
#include "CTLFormula_Interface.generated.h"


class AtomicFormula;
class UnaryFormula;
class BinaryFormula;
class StateNode;

UCLASS(Blueprintable)
class CTL_LABYRINTH_API UCTLFormulaInterface : public UObject {
    GENERATED_BODY()

public:
  

private:
    TSharedPtr<AtomicFormula> AtomicFormulaInstance;
    TSharedPtr<UnaryFormula> UnaryFormulaInstance;
    TSharedPtr<BinaryFormula> BinaryFormulaInstance;
};