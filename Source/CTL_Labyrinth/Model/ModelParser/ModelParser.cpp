#include "ModelParser.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

UModelParser::UModelParser() {}

void UModelParser::LoadModelFromJson(const FString& FilePath, UCTLModel* Model) {
    FString JsonString;
    if (!FFileHelper::LoadFileToString(JsonString, *FilePath)) {
        UE_LOG(LogTemp, Error, TEXT("Failed to load file: %s"), *FilePath);
        return;
    }

    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonString);
    TSharedPtr<FJsonObject> JsonObject;
    if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid()) {
        // Parsing degli stati
        const TArray<TSharedPtr<FJsonValue>> StatesArray = JsonObject->GetArrayField(TEXT("states"));
        for (const TSharedPtr<FJsonValue>& Value : StatesArray) {
            TSharedPtr<FJsonObject> StateObject = Value->AsObject();
            FState State;
            State.Id = StateObject->GetIntegerField(TEXT("id"));

            const TSharedPtr<FJsonObject> PropertiesObject = StateObject->GetObjectField(TEXT("properties"));
            for (const auto& Property : PropertiesObject->Values) {
                State.StateProperties.Add(Property.Key, Property.Value->AsBool());
            }

            Model->AddState(State);
        }

        // Parsing delle transizioni
        const TArray<TSharedPtr<FJsonValue>> TransitionsArray = JsonObject->GetArrayField(TEXT("transitions"));
        for (const TSharedPtr<FJsonValue>& Value : TransitionsArray) {
            TSharedPtr<FJsonObject> TransitionObject = Value->AsObject();
            int32 FromId = TransitionObject->GetIntegerField(TEXT("from"));
            int32 ToId = TransitionObject->GetIntegerField(TEXT("to"));

            FState FromState;
            FromState.Id = FromId;
            FState ToState;
            ToState.Id = ToId;

            Model->AddTransition(FromState, ToState);
        }

        // Parsing delle formule
        const TArray<TSharedPtr<FJsonValue>> FormulasArray = JsonObject->GetArrayField(TEXT("formulas"));
        for (const TSharedPtr<FJsonValue>& Value : FormulasArray) {
            TSharedPtr<FJsonObject> FormulaObject = Value->AsObject();
            FString Name = FormulaObject->GetStringField(TEXT("name"));
            FString Type = FormulaObject->GetStringField(TEXT("type"));
            FString PredicateName = FormulaObject->GetStringField(TEXT("predicate"));

            // Crea e aggiungi la formula basata sul tipo e sui predicati
            if (Type == TEXT("AG")) {
                Model->AddPredicate(PredicateName, CreatePredicate(PredicateName));
            }
            else if (Type == TEXT("EF")) {
                Model->AddPredicate(PredicateName, CreatePredicate(PredicateName));
            }
            // Aggiungi altre formule come necessario
        }
    }
    else {
        UE_LOG(LogTemp, Error, TEXT("Failed to deserialize JSON: %s"), *JsonString);
    }
}

TFunction<bool(const FState&)> UModelParser::CreatePredicate(const FString& PredicateName) const {
    // Implementa la logica per creare e restituire una funzione di predicato basata sul nome
    if (PredicateName == TEXT("evaluateNPC1IsAlert")) {
        return [](const FState& State) {
            bool* Value = State.StateProperties.Find(TEXT("NPC1IsAlert"));
            return Value ? *Value : false;
            };
    }
    else if (PredicateName == TEXT("evaluateNPC2IsAlert")) {
        return [](const FState& State) {
            bool* Value = State.StateProperties.Find(TEXT("NPC2IsAlert"));
            return Value ? *Value : false;
            };
    }
    // Aggiungi altre condizioni per i tuoi predicati
    return [](const FState& State) { return false; }; // Predicato di default
}
