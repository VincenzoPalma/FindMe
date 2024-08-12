#include "Model/ModelParser/ModelParser.h"
#include "../Public/Model/CTLModel.h"
#include "Serialization/JsonSerializer.h"
#include "Json.h"
#include "JsonUtilities.h"
#include "Misc/FileHelper.h"

UCTLModel* UModelParser::LoadModelFromJson(const FString& FilePath)
{
    FString JsonString;
    FFileHelper::LoadFileToString(JsonString, *FilePath);

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

        const TArray<TSharedPtr<FJsonValue>>* TransitionsArray;
        if (JsonObject->TryGetArrayField(TEXT("transitions"), TransitionsArray))
        {
            ParseTransitions(*TransitionsArray, Model);
        }

        const TArray<TSharedPtr<FJsonValue>>* FormulasArray;
        if (JsonObject->TryGetArrayField(TEXT("formulas"), FormulasArray))
        {
            ParseFormulas(*FormulasArray, Model);
        }
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
            int32 Id = StateObject->GetNumberField(TEXT("id"));
            TSharedPtr<FJsonObject> PropertiesObject = StateObject->GetObjectField(TEXT("properties"));

            FState State;
            State.Id = Id;
            for (const TPair<FString, TSharedPtr<FJsonValue>>& Property : PropertiesObject->Values)
            {
                State.Properties.Add(Property.Key, Property.Value->AsBool());
            }

            Model->AddState(State);
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

            FState FromState, ToState;
            Model->AddTransition(FromState, ToState);
        }
    }
}

void UModelParser::ParseFormulas(const TArray<TSharedPtr<FJsonValue>>& FormulasArray, UCTLModel* Model)
{
    for (const TSharedPtr<FJsonValue>& FormulaValue : FormulasArray)
    {
        TSharedPtr<FJsonObject> FormulaObject = FormulaValue->AsObject();

        if (FormulaObject.IsValid())
        {
            FString Type = FormulaObject->GetStringField(TEXT("type"));
            FString PredicateName;
            FormulaObject->TryGetStringField(TEXT("predicate"), PredicateName);

            UCTLFormula* ParsedFormula = nullptr;

            if (Type == TEXT("AG") || Type == TEXT("EG") || Type == TEXT("AF") || Type == TEXT("EF"))
            {
                UUnaryFormula* UnaryFormula = NewObject<UUnaryFormula>();
                ECTLOperator Operator = GetCTLOperatorFromString(Type);
                UCTLFormula* SubFormula = ParseSubFormula(FormulaObject->GetObjectField(TEXT("subformula")), Model);
                UnaryFormula->Initialize(Operator, SubFormula);
                ParsedFormula = UnaryFormula;
            }
            else if (Type == TEXT("AND") || Type == TEXT("OR") || Type == TEXT("EU") || Type == TEXT("AU"))
            {
                UBinaryFormula* BinaryFormula = NewObject<UBinaryFormula>();
                ECTLOperator Operator = GetCTLOperatorFromString(Type);
                UCTLFormula* LeftFormula = ParseSubFormula(FormulaObject->GetObjectField(TEXT("left")), Model);
                UCTLFormula* RightFormula = ParseSubFormula(FormulaObject->GetObjectField(TEXT("right")), Model);
                BinaryFormula->Initialize(Operator, LeftFormula, RightFormula);
                ParsedFormula = BinaryFormula;
            }
            else if (Type == TEXT("Atomic"))
            {
                UAtomicFormula* AtomicFormula = NewObject<UAtomicFormula>();
                //TFunction<bool(const FState&)> Predicate = Model->GetPredicateByName(PredicateName);
                //AtomicFormula->Initialize(Predicate);
                ParsedFormula = AtomicFormula;
            }

            if (ParsedFormula)
            {
                Model->AddFormula(ParsedFormula);
            }
        }
    }
}

UCTLFormula* UModelParser::ParseSubFormula(const TSharedPtr<FJsonObject>& FormulaObject, UCTLModel* Model)
{
    if (!FormulaObject.IsValid())
    {
        return nullptr;
    }

    FString Type = FormulaObject->GetStringField(TEXT("type"));
    FString PredicateName;
    FormulaObject->TryGetStringField(TEXT("predicate"), PredicateName);

    UCTLFormula* ParsedFormula = nullptr;

    if (Type == TEXT("AG") || Type == TEXT("EG") || Type == TEXT("AF") || Type == TEXT("EF"))
    {
        UUnaryFormula* UnaryFormula = NewObject<UUnaryFormula>();
        ECTLOperator Operator = GetCTLOperatorFromString(Type);
        UCTLFormula* SubFormula = ParseSubFormula(FormulaObject->GetObjectField(TEXT("subformula")), Model);
        UnaryFormula->Initialize(Operator, SubFormula);
        ParsedFormula = UnaryFormula;
    }
    else if (Type == TEXT("AND") || Type == TEXT("OR") || Type == TEXT("EU") || Type == TEXT("AU"))
    {
        UBinaryFormula* BinaryFormula = NewObject<UBinaryFormula>();
        ECTLOperator Operator = GetCTLOperatorFromString(Type);
        UCTLFormula* LeftFormula = ParseSubFormula(FormulaObject->GetObjectField(TEXT("left")), Model);
        UCTLFormula* RightFormula = ParseSubFormula(FormulaObject->GetObjectField(TEXT("right")), Model);
        BinaryFormula->Initialize(Operator, LeftFormula, RightFormula);
        ParsedFormula = BinaryFormula;
    }
    else if (Type == TEXT("Atomic"))
    {
        UAtomicFormula* AtomicFormula = NewObject<UAtomicFormula>();
        //TFunction<bool(const FState&)> Predicate = Model->GetPredicateByName(PredicateName);
        //AtomicFormula->Initialize(Predicate);
        ParsedFormula = AtomicFormula;
    }

    return ParsedFormula;
}


ECTLOperator UModelParser::GetCTLOperatorFromString(const FString& Type)
{
    if (Type == TEXT("AG")) return ECTLOperator::AG;
    if (Type == TEXT("EG")) return ECTLOperator::EG;
    if (Type == TEXT("AF")) return ECTLOperator::AF;
    if (Type == TEXT("EF")) return ECTLOperator::EF;
    if (Type == TEXT("AND")) return ECTLOperator::AND;
    if (Type == TEXT("OR")) return ECTLOperator::OR;
    if (Type == TEXT("EU")) return ECTLOperator::EU;
    if (Type == TEXT("AU")) return ECTLOperator::AU;
    return ECTLOperator::AND;
}
