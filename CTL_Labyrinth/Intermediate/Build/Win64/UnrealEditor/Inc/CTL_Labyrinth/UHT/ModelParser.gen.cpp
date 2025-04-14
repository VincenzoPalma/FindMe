// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CTL_Labyrinth/Public/Model/ModelParser/ModelParser.h"
#include "CTL_Labyrinth/Public/Model/ModelStructures.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeModelParser() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
CTL_LABYRINTH_API UClass* Z_Construct_UClass_UCTLModel_NoRegister();
CTL_LABYRINTH_API UClass* Z_Construct_UClass_UModelParser();
CTL_LABYRINTH_API UClass* Z_Construct_UClass_UModelParser_NoRegister();
CTL_LABYRINTH_API UClass* Z_Construct_UClass_UStateNode_NoRegister();
CTL_LABYRINTH_API UScriptStruct* Z_Construct_UScriptStruct_FVariantValue();
UPackage* Z_Construct_UPackage__Script_CTL_Labyrinth();
// End Cross Module References

// Begin Class UModelParser Function FindAndParseState
struct Z_Construct_UFunction_UModelParser_FindAndParseState_Statics
{
	struct ModelParser_eventFindAndParseState_Parms
	{
		FString FilePath;
		TMap<FString,FVariantValue> Properties;
		UCTLModel* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Model Parsing" },
		{ "ModuleRelativePath", "Public/Model/ModelParser/ModelParser.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FilePath_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Properties_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_FilePath;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Properties_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Properties_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_Properties;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UModelParser_FindAndParseState_Statics::NewProp_FilePath = { "FilePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModelParser_eventFindAndParseState_Parms, FilePath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FilePath_MetaData), NewProp_FilePath_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UModelParser_FindAndParseState_Statics::NewProp_Properties_ValueProp = { "Properties", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FVariantValue, METADATA_PARAMS(0, nullptr) }; // 249394340
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UModelParser_FindAndParseState_Statics::NewProp_Properties_Key_KeyProp = { "Properties_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UModelParser_FindAndParseState_Statics::NewProp_Properties = { "Properties", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModelParser_eventFindAndParseState_Parms, Properties), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Properties_MetaData), NewProp_Properties_MetaData) }; // 249394340
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UModelParser_FindAndParseState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModelParser_eventFindAndParseState_Parms, ReturnValue), Z_Construct_UClass_UCTLModel_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UModelParser_FindAndParseState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModelParser_FindAndParseState_Statics::NewProp_FilePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModelParser_FindAndParseState_Statics::NewProp_Properties_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModelParser_FindAndParseState_Statics::NewProp_Properties_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModelParser_FindAndParseState_Statics::NewProp_Properties,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModelParser_FindAndParseState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UModelParser_FindAndParseState_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UModelParser_FindAndParseState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UModelParser, nullptr, "FindAndParseState", nullptr, nullptr, Z_Construct_UFunction_UModelParser_FindAndParseState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UModelParser_FindAndParseState_Statics::PropPointers), sizeof(Z_Construct_UFunction_UModelParser_FindAndParseState_Statics::ModelParser_eventFindAndParseState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UModelParser_FindAndParseState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UModelParser_FindAndParseState_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UModelParser_FindAndParseState_Statics::ModelParser_eventFindAndParseState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModelParser_FindAndParseState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UModelParser_FindAndParseState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UModelParser::execFindAndParseState)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FilePath);
	P_GET_TMAP_REF(FString,FVariantValue,Z_Param_Out_Properties);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UCTLModel**)Z_Param__Result=UModelParser::FindAndParseState(Z_Param_FilePath,Z_Param_Out_Properties);
	P_NATIVE_END;
}
// End Class UModelParser Function FindAndParseState

// Begin Class UModelParser Function FindStateWithProperties
struct Z_Construct_UFunction_UModelParser_FindStateWithProperties_Statics
{
	struct ModelParser_eventFindStateWithProperties_Parms
	{
		FString FilePath;
		TMap<FString,FVariantValue> Properties;
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Model Parsing" },
		{ "ModuleRelativePath", "Public/Model/ModelParser/ModelParser.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FilePath_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Properties_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_FilePath;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Properties_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Properties_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_Properties;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UModelParser_FindStateWithProperties_Statics::NewProp_FilePath = { "FilePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModelParser_eventFindStateWithProperties_Parms, FilePath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FilePath_MetaData), NewProp_FilePath_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UModelParser_FindStateWithProperties_Statics::NewProp_Properties_ValueProp = { "Properties", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FVariantValue, METADATA_PARAMS(0, nullptr) }; // 249394340
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UModelParser_FindStateWithProperties_Statics::NewProp_Properties_Key_KeyProp = { "Properties_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UModelParser_FindStateWithProperties_Statics::NewProp_Properties = { "Properties", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModelParser_eventFindStateWithProperties_Parms, Properties), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Properties_MetaData), NewProp_Properties_MetaData) }; // 249394340
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UModelParser_FindStateWithProperties_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModelParser_eventFindStateWithProperties_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UModelParser_FindStateWithProperties_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModelParser_FindStateWithProperties_Statics::NewProp_FilePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModelParser_FindStateWithProperties_Statics::NewProp_Properties_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModelParser_FindStateWithProperties_Statics::NewProp_Properties_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModelParser_FindStateWithProperties_Statics::NewProp_Properties,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModelParser_FindStateWithProperties_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UModelParser_FindStateWithProperties_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UModelParser_FindStateWithProperties_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UModelParser, nullptr, "FindStateWithProperties", nullptr, nullptr, Z_Construct_UFunction_UModelParser_FindStateWithProperties_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UModelParser_FindStateWithProperties_Statics::PropPointers), sizeof(Z_Construct_UFunction_UModelParser_FindStateWithProperties_Statics::ModelParser_eventFindStateWithProperties_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UModelParser_FindStateWithProperties_Statics::Function_MetaDataParams), Z_Construct_UFunction_UModelParser_FindStateWithProperties_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UModelParser_FindStateWithProperties_Statics::ModelParser_eventFindStateWithProperties_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModelParser_FindStateWithProperties()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UModelParser_FindStateWithProperties_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UModelParser::execFindStateWithProperties)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FilePath);
	P_GET_TMAP_REF(FString,FVariantValue,Z_Param_Out_Properties);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=UModelParser::FindStateWithProperties(Z_Param_FilePath,Z_Param_Out_Properties);
	P_NATIVE_END;
}
// End Class UModelParser Function FindStateWithProperties

// Begin Class UModelParser Function LoadModelFromJson
struct Z_Construct_UFunction_UModelParser_LoadModelFromJson_Statics
{
	struct ModelParser_eventLoadModelFromJson_Parms
	{
		FString FilePath;
		UCTLModel* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Model Parsing" },
		{ "ModuleRelativePath", "Public/Model/ModelParser/ModelParser.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FilePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_FilePath;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UModelParser_LoadModelFromJson_Statics::NewProp_FilePath = { "FilePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModelParser_eventLoadModelFromJson_Parms, FilePath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FilePath_MetaData), NewProp_FilePath_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UModelParser_LoadModelFromJson_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModelParser_eventLoadModelFromJson_Parms, ReturnValue), Z_Construct_UClass_UCTLModel_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UModelParser_LoadModelFromJson_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModelParser_LoadModelFromJson_Statics::NewProp_FilePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModelParser_LoadModelFromJson_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UModelParser_LoadModelFromJson_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UModelParser_LoadModelFromJson_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UModelParser, nullptr, "LoadModelFromJson", nullptr, nullptr, Z_Construct_UFunction_UModelParser_LoadModelFromJson_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UModelParser_LoadModelFromJson_Statics::PropPointers), sizeof(Z_Construct_UFunction_UModelParser_LoadModelFromJson_Statics::ModelParser_eventLoadModelFromJson_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UModelParser_LoadModelFromJson_Statics::Function_MetaDataParams), Z_Construct_UFunction_UModelParser_LoadModelFromJson_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UModelParser_LoadModelFromJson_Statics::ModelParser_eventLoadModelFromJson_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModelParser_LoadModelFromJson()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UModelParser_LoadModelFromJson_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UModelParser::execLoadModelFromJson)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FilePath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UCTLModel**)Z_Param__Result=UModelParser::LoadModelFromJson(Z_Param_FilePath);
	P_NATIVE_END;
}
// End Class UModelParser Function LoadModelFromJson

// Begin Class UModelParser Function LoadPartialModelFromJson
struct Z_Construct_UFunction_UModelParser_LoadPartialModelFromJson_Statics
{
	struct ModelParser_eventLoadPartialModelFromJson_Parms
	{
		FString FilePath;
		int32 StartingStateId;
		UCTLModel* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Model Parsing" },
		{ "ModuleRelativePath", "Public/Model/ModelParser/ModelParser.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FilePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_FilePath;
	static const UECodeGen_Private::FIntPropertyParams NewProp_StartingStateId;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UModelParser_LoadPartialModelFromJson_Statics::NewProp_FilePath = { "FilePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModelParser_eventLoadPartialModelFromJson_Parms, FilePath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FilePath_MetaData), NewProp_FilePath_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UModelParser_LoadPartialModelFromJson_Statics::NewProp_StartingStateId = { "StartingStateId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModelParser_eventLoadPartialModelFromJson_Parms, StartingStateId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UModelParser_LoadPartialModelFromJson_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModelParser_eventLoadPartialModelFromJson_Parms, ReturnValue), Z_Construct_UClass_UCTLModel_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UModelParser_LoadPartialModelFromJson_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModelParser_LoadPartialModelFromJson_Statics::NewProp_FilePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModelParser_LoadPartialModelFromJson_Statics::NewProp_StartingStateId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModelParser_LoadPartialModelFromJson_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UModelParser_LoadPartialModelFromJson_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UModelParser_LoadPartialModelFromJson_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UModelParser, nullptr, "LoadPartialModelFromJson", nullptr, nullptr, Z_Construct_UFunction_UModelParser_LoadPartialModelFromJson_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UModelParser_LoadPartialModelFromJson_Statics::PropPointers), sizeof(Z_Construct_UFunction_UModelParser_LoadPartialModelFromJson_Statics::ModelParser_eventLoadPartialModelFromJson_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UModelParser_LoadPartialModelFromJson_Statics::Function_MetaDataParams), Z_Construct_UFunction_UModelParser_LoadPartialModelFromJson_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UModelParser_LoadPartialModelFromJson_Statics::ModelParser_eventLoadPartialModelFromJson_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModelParser_LoadPartialModelFromJson()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UModelParser_LoadPartialModelFromJson_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UModelParser::execLoadPartialModelFromJson)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FilePath);
	P_GET_PROPERTY(FIntProperty,Z_Param_StartingStateId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UCTLModel**)Z_Param__Result=UModelParser::LoadPartialModelFromJson(Z_Param_FilePath,Z_Param_StartingStateId);
	P_NATIVE_END;
}
// End Class UModelParser Function LoadPartialModelFromJson

// Begin Class UModelParser Function ParseStartingState
struct Z_Construct_UFunction_UModelParser_ParseStartingState_Statics
{
	struct ModelParser_eventParseStartingState_Parms
	{
		FString FilePath;
		int32 StartingStateId;
		UCTLModel* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Model Parsing" },
		{ "ModuleRelativePath", "Public/Model/ModelParser/ModelParser.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FilePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_FilePath;
	static const UECodeGen_Private::FIntPropertyParams NewProp_StartingStateId;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UModelParser_ParseStartingState_Statics::NewProp_FilePath = { "FilePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModelParser_eventParseStartingState_Parms, FilePath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FilePath_MetaData), NewProp_FilePath_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UModelParser_ParseStartingState_Statics::NewProp_StartingStateId = { "StartingStateId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModelParser_eventParseStartingState_Parms, StartingStateId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UModelParser_ParseStartingState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModelParser_eventParseStartingState_Parms, ReturnValue), Z_Construct_UClass_UCTLModel_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UModelParser_ParseStartingState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModelParser_ParseStartingState_Statics::NewProp_FilePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModelParser_ParseStartingState_Statics::NewProp_StartingStateId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModelParser_ParseStartingState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UModelParser_ParseStartingState_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UModelParser_ParseStartingState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UModelParser, nullptr, "ParseStartingState", nullptr, nullptr, Z_Construct_UFunction_UModelParser_ParseStartingState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UModelParser_ParseStartingState_Statics::PropPointers), sizeof(Z_Construct_UFunction_UModelParser_ParseStartingState_Statics::ModelParser_eventParseStartingState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UModelParser_ParseStartingState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UModelParser_ParseStartingState_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UModelParser_ParseStartingState_Statics::ModelParser_eventParseStartingState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModelParser_ParseStartingState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UModelParser_ParseStartingState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UModelParser::execParseStartingState)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FilePath);
	P_GET_PROPERTY(FIntProperty,Z_Param_StartingStateId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UCTLModel**)Z_Param__Result=UModelParser::ParseStartingState(Z_Param_FilePath,Z_Param_StartingStateId);
	P_NATIVE_END;
}
// End Class UModelParser Function ParseStartingState

// Begin Class UModelParser Function UpdateModelFromNode
struct Z_Construct_UFunction_UModelParser_UpdateModelFromNode_Statics
{
	struct ModelParser_eventUpdateModelFromNode_Parms
	{
		FString FilePath;
		UCTLModel* model;
		UStateNode* node;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Model Parsing" },
		{ "ModuleRelativePath", "Public/Model/ModelParser/ModelParser.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FilePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_FilePath;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_model;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_node;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UModelParser_UpdateModelFromNode_Statics::NewProp_FilePath = { "FilePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModelParser_eventUpdateModelFromNode_Parms, FilePath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FilePath_MetaData), NewProp_FilePath_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UModelParser_UpdateModelFromNode_Statics::NewProp_model = { "model", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModelParser_eventUpdateModelFromNode_Parms, model), Z_Construct_UClass_UCTLModel_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UModelParser_UpdateModelFromNode_Statics::NewProp_node = { "node", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModelParser_eventUpdateModelFromNode_Parms, node), Z_Construct_UClass_UStateNode_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UModelParser_UpdateModelFromNode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModelParser_UpdateModelFromNode_Statics::NewProp_FilePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModelParser_UpdateModelFromNode_Statics::NewProp_model,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModelParser_UpdateModelFromNode_Statics::NewProp_node,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UModelParser_UpdateModelFromNode_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UModelParser_UpdateModelFromNode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UModelParser, nullptr, "UpdateModelFromNode", nullptr, nullptr, Z_Construct_UFunction_UModelParser_UpdateModelFromNode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UModelParser_UpdateModelFromNode_Statics::PropPointers), sizeof(Z_Construct_UFunction_UModelParser_UpdateModelFromNode_Statics::ModelParser_eventUpdateModelFromNode_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UModelParser_UpdateModelFromNode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UModelParser_UpdateModelFromNode_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UModelParser_UpdateModelFromNode_Statics::ModelParser_eventUpdateModelFromNode_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModelParser_UpdateModelFromNode()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UModelParser_UpdateModelFromNode_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UModelParser::execUpdateModelFromNode)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FilePath);
	P_GET_OBJECT(UCTLModel,Z_Param_model);
	P_GET_OBJECT(UStateNode,Z_Param_node);
	P_FINISH;
	P_NATIVE_BEGIN;
	UModelParser::UpdateModelFromNode(Z_Param_FilePath,Z_Param_model,Z_Param_node);
	P_NATIVE_END;
}
// End Class UModelParser Function UpdateModelFromNode

// Begin Class UModelParser
void UModelParser::StaticRegisterNativesUModelParser()
{
	UClass* Class = UModelParser::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "FindAndParseState", &UModelParser::execFindAndParseState },
		{ "FindStateWithProperties", &UModelParser::execFindStateWithProperties },
		{ "LoadModelFromJson", &UModelParser::execLoadModelFromJson },
		{ "LoadPartialModelFromJson", &UModelParser::execLoadPartialModelFromJson },
		{ "ParseStartingState", &UModelParser::execParseStartingState },
		{ "UpdateModelFromNode", &UModelParser::execUpdateModelFromNode },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UModelParser);
UClass* Z_Construct_UClass_UModelParser_NoRegister()
{
	return UModelParser::StaticClass();
}
struct Z_Construct_UClass_UModelParser_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Model/ModelParser/ModelParser.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Model/ModelParser/ModelParser.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UModelParser_FindAndParseState, "FindAndParseState" }, // 1012218672
		{ &Z_Construct_UFunction_UModelParser_FindStateWithProperties, "FindStateWithProperties" }, // 1098867919
		{ &Z_Construct_UFunction_UModelParser_LoadModelFromJson, "LoadModelFromJson" }, // 3449121822
		{ &Z_Construct_UFunction_UModelParser_LoadPartialModelFromJson, "LoadPartialModelFromJson" }, // 3750242296
		{ &Z_Construct_UFunction_UModelParser_ParseStartingState, "ParseStartingState" }, // 539784505
		{ &Z_Construct_UFunction_UModelParser_UpdateModelFromNode, "UpdateModelFromNode" }, // 3753620417
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UModelParser>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UModelParser_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_CTL_Labyrinth,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UModelParser_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UModelParser_Statics::ClassParams = {
	&UModelParser::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UModelParser_Statics::Class_MetaDataParams), Z_Construct_UClass_UModelParser_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UModelParser()
{
	if (!Z_Registration_Info_UClass_UModelParser.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UModelParser.OuterSingleton, Z_Construct_UClass_UModelParser_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UModelParser.OuterSingleton;
}
template<> CTL_LABYRINTH_API UClass* StaticClass<UModelParser>()
{
	return UModelParser::StaticClass();
}
UModelParser::UModelParser(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UModelParser);
UModelParser::~UModelParser() {}
// End Class UModelParser

// Begin Registration
struct Z_CompiledInDeferFile_FID_CTL_Labyrinth_Source_CTL_Labyrinth_Public_Model_ModelParser_ModelParser_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UModelParser, UModelParser::StaticClass, TEXT("UModelParser"), &Z_Registration_Info_UClass_UModelParser, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UModelParser), 2833993374U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CTL_Labyrinth_Source_CTL_Labyrinth_Public_Model_ModelParser_ModelParser_h_2936385800(TEXT("/Script/CTL_Labyrinth"),
	Z_CompiledInDeferFile_FID_CTL_Labyrinth_Source_CTL_Labyrinth_Public_Model_ModelParser_ModelParser_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CTL_Labyrinth_Source_CTL_Labyrinth_Public_Model_ModelParser_ModelParser_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
