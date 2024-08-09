#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "../CTL_ModelChecking/CTLFormula.h"
#include "CTLFormulaWrapper.generated.h"

UCLASS(Blueprintable)
class CTL_LABYRINTH_API UCTLFormulaWrapper : public UObject
{
    GENERATED_BODY()

public:

protected:
    TSharedPtr<CTLFormula> FormulaInstance;
};