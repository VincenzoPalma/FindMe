#include "Model/ModelParser/ModelParser.h"
#include "../Public/Model/CTLModel.h"
#include "Serialization/JsonSerializer.h"
#include "Json.h"
#include "JsonUtilities.h"
#include "Misc/FileHelper.h"

UCTLModel* UModelParser::LoadModelFromJson(const FString& FilePath)
{
    FString JsonString;

    if (!FFileHelper::LoadFileToString(JsonString, *FilePath))
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to load JSON file from path: %s"), *FilePath);
        return nullptr;
    }

    TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(JsonString);
    TSharedPtr<FJsonObject> JsonObject;

    UCTLModel* Model = NewObject<UCTLModel>();

    if (FJsonSerializer::Deserialize(JsonReader, JsonObject) && JsonObject.IsValid())
    {

        const TArray<TSharedPtr<FJsonValue>>* StatesArray;
        if (JsonObject->TryGetArrayField(TEXT("states"), StatesArray))
        {
            ParseStates(*StatesArray, Model);
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("JSON file does not contain 'states' array or it is invalid."));
        }

        const TArray<TSharedPtr<FJsonValue>>* TransitionsArray;
        if (JsonObject->TryGetArrayField(TEXT("transitions"), TransitionsArray))
        {
            ParseTransitions(*TransitionsArray, Model);
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("JSON file does not contain 'transitions' array or it is invalid."));
        }

        const TArray<TSharedPtr<FJsonValue>>* FormulasArray;
        if (JsonObject->TryGetArrayField(TEXT("formulas"), FormulasArray))
        {
            ParseFormulas(*FormulasArray, Model);
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("JSON file does not contain 'formulas' array or it is invalid."));
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to deserialize JSON file from path: %s"), *FilePath);
    }

    return Model;
}



void UModelParser::ParseStates(const TArray<TSharedPtr<FJsonValue>>& StatesArray, UCTLModel* Model)
{
    for (const TSharedPtr<FJsonValue>& StateValue : StatesArray)
    {
        TSharedPtr<FJsonObject> StateObject = StateValue->AsObject();
        if (StateObject.IsValid())
        {

            if (StateObject->HasField(TEXT("id")))
            {
                int32 Id = StateObject->GetNumberField(TEXT("id"));

                if (StateObject->HasField(TEXT("properties")))
                {
                    TSharedPtr<FJsonObject> PropertiesObject = StateObject->GetObjectField(TEXT("properties"));

                    FState State;
                    State.Id = Id;

                    for (const TPair<FString, TSharedPtr<FJsonValue>>& Property : PropertiesObject->Values)
                    {
                        if (Property.Value.IsValid())
                        {
                            bool PropertyValue = Property.Value->AsBool();
                            State.Properties.Add(Property.Key, PropertyValue);
                        }
                        else
                        {
                            UE_LOG(LogTemp, Warning, TEXT("Property value for '%s' is invalid."), *Property.Key);
                        }
                    }

                    Model->AddState(State);
                }
                else
                {
                    UE_LOG(LogTemp, Warning, TEXT("State with ID %d is missing 'properties' field."), Id);
                }
            }
            else
            {
                UE_LOG(LogTemp, Warning, TEXT("State object is missing 'id' field"));
            }
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("State value is not a valid JSON object."));
        }
    }
}


void UModelParser::ParseTransitions(const TArray<TSharedPtr<FJsonValue>>& TransitionsArray, UCTLModel* Model)
{
    for (const TSharedPtr<FJsonValue>& TransitionValue : TransitionsArray)
    {
        TSharedPtr<FJsonObject> TransitionObject = TransitionValue->AsObject();
        if (TransitionObject.IsValid())
        {
            int32 FromId = TransitionObject->GetNumberField(TEXT("from"));
            int32 ToId = TransitionObject->GetNumberField(TEXT("to"));
            FString Action = TransitionObject->GetStringField(TEXT("action"));
            const UStateNode* const* FromNodePtr = Model->GetStateNodes().Find(FromId);
            const UStateNode* const* ToNodePtr = Model->GetStateNodes().Find(ToId);

            if (FromNodePtr && ToNodePtr)
            {
                UStateNode* FromNode = const_cast<UStateNode*>(*FromNodePtr);
                UStateNode* ToNode = const_cast<UStateNode*>(*ToNodePtr);

                Model->AddTransition(Action, FromNode, ToNode);
            }
            else
            {
                UE_LOG(LogTemp, Warning, TEXT("Failed to add transition from State ID: %d to State ID: %d. One or both states are not found."), FromId, ToId);
            }
        }
    }
}

void UModelParser::ParseFormulas(const TArray<TSharedPtr<FJsonValue>>& FormulasArray, UCTLModel* Model)
{
    auto PredicateManager = Model->GetPredicateManager();

    for (const TSharedPtr<FJsonValue>& FormulaValue : FormulasArray)
    {
        TSharedPtr<FJsonObject> FormulaObject = FormulaValue->AsObject();
        if (FormulaObject.IsValid())
        {
            // Extract the type and ID of the formula
            FString Type = FormulaObject->GetStringField(TEXT("type"));
            int32 Id = FormulaObject->GetNumberField(TEXT("id"));

            UCTLFormula* NewFormula = nullptr;

            if (Type == TEXT("Atomic"))
            {
                // Extract the predicate name for the atomic formula
                FString PredicateName = FormulaObject->GetStringField(TEXT("predicate"));

                // Register the predicate if it is not already registered
                if (!PredicateManager->GetPredicate(PredicateName))
                {
                    // Register the predicate with a lambda function that checks the state properties
                    PredicateManager->RegisterPredicate(PredicateName, [PredicateName](const FState& State) -> bool {
                        return State.Properties.Contains(PredicateName) && State.Properties[PredicateName];
                        });
                }

                // Create a new atomic formula and initialize it
                NewFormula = NewObject<UAtomicFormula>();
                auto Predicate = PredicateManager->GetPredicate(PredicateName);
                if (Predicate)
                {
                    UAtomicFormula* AtomicFormula = Cast<UAtomicFormula>(NewFormula);
                    AtomicFormula->Initialize(Predicate);
                    // Add the new formula to the model
                    Model->AddFormula(Id, AtomicFormula);
                }
                else
                {
                    // Log a warning if the predicate was not found
                    UE_LOG(LogTemp, Warning, TEXT("Predicate %s not found"), *PredicateName);
                }
            }
            else if (Type == TEXT("Unary"))
            {
                // Extract the operator and subformula ID for the unary formula
                FString OperatorString = FormulaObject->GetStringField(TEXT("operator"));
                ECTLOperator Operator = StringToOperator(OperatorString);
                int32 SubFormulaId = FormulaObject->GetNumberField(TEXT("subformula_id"));

                // Create a new unary formula and initialize it
                NewFormula = NewObject<UUnaryFormula>();
                UCTLFormula* SubFormula = Model->GetFormula(SubFormulaId);
                if (SubFormula)
                {
                    UUnaryFormula* UnaryFormula = Cast<UUnaryFormula>(NewFormula);
                    UnaryFormula->Initialize(Operator, SubFormula);
                    // Add the new formula to the model
                    Model->AddFormula(Id, UnaryFormula);
                }
                else
                {
                    UE_LOG(LogTemp, Warning, TEXT("Subformula with ID %d not found"), SubFormulaId);
                }
            }
            else if (Type == TEXT("Binary"))
            {
                // Extract the operator and IDs for the left and right formulas
                FString OperatorString = FormulaObject->GetStringField(TEXT("operator"));
                ECTLOperator Operator = StringToOperator(OperatorString);
                int32 LeftId = FormulaObject->GetNumberField(TEXT("left_id"));
                int32 RightId = FormulaObject->GetNumberField(TEXT("right_id"));

                // Create a new binary formula and initialize it
                NewFormula = NewObject<UBinaryFormula>();
                UCTLFormula* LeftFormula = Model->GetFormula(LeftId);
                UCTLFormula* RightFormula = Model->GetFormula(RightId);
                if (LeftFormula && RightFormula)
                {
                    UBinaryFormula* BinaryFormula = Cast<UBinaryFormula>(NewFormula);
                    BinaryFormula->Initialize(Operator, LeftFormula, RightFormula);
                    // Add the new formula to the model
                    Model->AddFormula(Id, BinaryFormula);
                }
                else
                {
                    UE_LOG(LogTemp, Warning, TEXT("Left or right formula with IDs %d or %d not found"), LeftId, RightId);
                }
            }
        }
    }
}



ECTLOperator UModelParser::StringToOperator(const FString& OperatorString)
{
    if (OperatorString == TEXT("AND")) return ECTLOperator::AND;
    if (OperatorString == TEXT("OR")) return ECTLOperator::OR;
    if (OperatorString == TEXT("NOT")) return ECTLOperator::NOT;
    if (OperatorString == TEXT("EX")) return ECTLOperator::EX;
    if (OperatorString == TEXT("AX")) return ECTLOperator::AX;
    if (OperatorString == TEXT("EF")) return ECTLOperator::EF;
    if (OperatorString == TEXT("AF")) return ECTLOperator::AF;
    if (OperatorString == TEXT("EG")) return ECTLOperator::EG;
    if (OperatorString == TEXT("AG")) return ECTLOperator::AG;
    if (OperatorString == TEXT("EU")) return ECTLOperator::EU;
    if (OperatorString == TEXT("AU")) return ECTLOperator::AU;

    UE_LOG(LogTemp, Warning, TEXT("Unknown operator: %s"), *OperatorString);
    return ECTLOperator::AND;
}
