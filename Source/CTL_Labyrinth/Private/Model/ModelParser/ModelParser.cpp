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
            //ParseFormulas(*FormulasArray, Model);
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

            const UStateNode* const* FromNodePtr = Model->GetStateNodes().Find(FromId);
            const UStateNode* const* ToNodePtr = Model->GetStateNodes().Find(ToId);

            if (FromNodePtr && ToNodePtr)
            {
                UStateNode* FromNode = const_cast<UStateNode*>(*FromNodePtr);
                UStateNode* ToNode = const_cast<UStateNode*>(*ToNodePtr);

                Model->AddTransition(FromNode, ToNode);
            }
            else
            {
                UE_LOG(LogTemp, Warning, TEXT("Failed to add transition from State ID: %d to State ID: %d. One or both states are not found."), FromId, ToId);
            }
        }
    }
}