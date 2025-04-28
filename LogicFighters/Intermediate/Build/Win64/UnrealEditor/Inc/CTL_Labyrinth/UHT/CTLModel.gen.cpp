// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CTL_Labyrinth/Public/Model/CTLModel.h"
#include "CTL_Labyrinth/Public/Model/ModelStructures.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCTLModel() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
CTL_LABYRINTH_API UClass* Z_Construct_UClass_UCTLFormula_NoRegister();
CTL_LABYRINTH_API UClass* Z_Construct_UClass_UCTLModel();
CTL_LABYRINTH_API UClass* Z_Construct_UClass_UCTLModel_NoRegister();
CTL_LABYRINTH_API UClass* Z_Construct_UClass_UPredicateManager_NoRegister();
CTL_LABYRINTH_API UClass* Z_Construct_UClass_UStateNode_NoRegister();
CTL_LABYRINTH_API UEnum* Z_Construct_UEnum_CTL_Labyrinth_ECharacterActions();
CTL_LABYRINTH_API UScriptStruct* Z_Construct_UScriptStruct_FActionsToNode();
UPackage* Z_Construct_UPackage__Script_CTL_Labyrinth();
// End Cross Module References

// Begin Class UCTLModel Function DebugPrintModel
struct Z_Construct_UFunction_UCTLModel_DebugPrintModel_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Debug" },
		{ "ModuleRelativePath", "Public/Model/CTLModel.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCTLModel_DebugPrintModel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCTLModel, nullptr, "DebugPrintModel", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x44020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCTLModel_DebugPrintModel_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCTLModel_DebugPrintModel_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UCTLModel_DebugPrintModel()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCTLModel_DebugPrintModel_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCTLModel::execDebugPrintModel)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DebugPrintModel();
	P_NATIVE_END;
}
// End Class UCTLModel Function DebugPrintModel

// Begin Class UCTLModel Function EvaluateFormula
struct Z_Construct_UFunction_UCTLModel_EvaluateFormula_Statics
{
	struct CTLModel_eventEvaluateFormula_Parms
	{
		UStateNode* node;
		UCTLFormula* formula;
		bool ShortestPath;
		TMap<FString,FActionsToNode> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Model" },
		{ "CPP_Default_ShortestPath", "true" },
		{ "ModuleRelativePath", "Public/Model/CTLModel.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_node;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_formula;
	static void NewProp_ShortestPath_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ShortestPath;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCTLModel_EvaluateFormula_Statics::NewProp_node = { "node", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CTLModel_eventEvaluateFormula_Parms, node), Z_Construct_UClass_UStateNode_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCTLModel_EvaluateFormula_Statics::NewProp_formula = { "formula", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CTLModel_eventEvaluateFormula_Parms, formula), Z_Construct_UClass_UCTLFormula_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UCTLModel_EvaluateFormula_Statics::NewProp_ShortestPath_SetBit(void* Obj)
{
	((CTLModel_eventEvaluateFormula_Parms*)Obj)->ShortestPath = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCTLModel_EvaluateFormula_Statics::NewProp_ShortestPath = { "ShortestPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CTLModel_eventEvaluateFormula_Parms), &Z_Construct_UFunction_UCTLModel_EvaluateFormula_Statics::NewProp_ShortestPath_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCTLModel_EvaluateFormula_Statics::NewProp_ReturnValue_ValueProp = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FActionsToNode, METADATA_PARAMS(0, nullptr) }; // 4027915148
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCTLModel_EvaluateFormula_Statics::NewProp_ReturnValue_Key_KeyProp = { "ReturnValue_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UCTLModel_EvaluateFormula_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CTLModel_eventEvaluateFormula_Parms, ReturnValue), EMapPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 4027915148
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCTLModel_EvaluateFormula_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCTLModel_EvaluateFormula_Statics::NewProp_node,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCTLModel_EvaluateFormula_Statics::NewProp_formula,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCTLModel_EvaluateFormula_Statics::NewProp_ShortestPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCTLModel_EvaluateFormula_Statics::NewProp_ReturnValue_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCTLModel_EvaluateFormula_Statics::NewProp_ReturnValue_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCTLModel_EvaluateFormula_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCTLModel_EvaluateFormula_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCTLModel_EvaluateFormula_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCTLModel, nullptr, "EvaluateFormula", nullptr, nullptr, Z_Construct_UFunction_UCTLModel_EvaluateFormula_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCTLModel_EvaluateFormula_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCTLModel_EvaluateFormula_Statics::CTLModel_eventEvaluateFormula_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCTLModel_EvaluateFormula_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCTLModel_EvaluateFormula_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCTLModel_EvaluateFormula_Statics::CTLModel_eventEvaluateFormula_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCTLModel_EvaluateFormula()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCTLModel_EvaluateFormula_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCTLModel::execEvaluateFormula)
{
	P_GET_OBJECT(UStateNode,Z_Param_node);
	P_GET_OBJECT(UCTLFormula,Z_Param_formula);
	P_GET_UBOOL(Z_Param_ShortestPath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TMap<FString,FActionsToNode>*)Z_Param__Result=P_THIS->EvaluateFormula(Z_Param_node,Z_Param_formula,Z_Param_ShortestPath);
	P_NATIVE_END;
}
// End Class UCTLModel Function EvaluateFormula

// Begin Class UCTLModel Function GetFormula
struct Z_Construct_UFunction_UCTLModel_GetFormula_Statics
{
	struct CTLModel_eventGetFormula_Parms
	{
		int32 Id;
		UCTLFormula* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Model" },
		{ "ModuleRelativePath", "Public/Model/CTLModel.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Id;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UCTLModel_GetFormula_Statics::NewProp_Id = { "Id", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CTLModel_eventGetFormula_Parms, Id), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCTLModel_GetFormula_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CTLModel_eventGetFormula_Parms, ReturnValue), Z_Construct_UClass_UCTLFormula_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCTLModel_GetFormula_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCTLModel_GetFormula_Statics::NewProp_Id,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCTLModel_GetFormula_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCTLModel_GetFormula_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCTLModel_GetFormula_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCTLModel, nullptr, "GetFormula", nullptr, nullptr, Z_Construct_UFunction_UCTLModel_GetFormula_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCTLModel_GetFormula_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCTLModel_GetFormula_Statics::CTLModel_eventGetFormula_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCTLModel_GetFormula_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCTLModel_GetFormula_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCTLModel_GetFormula_Statics::CTLModel_eventGetFormula_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCTLModel_GetFormula()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCTLModel_GetFormula_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCTLModel::execGetFormula)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Id);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UCTLFormula**)Z_Param__Result=P_THIS->GetFormula(Z_Param_Id);
	P_NATIVE_END;
}
// End Class UCTLModel Function GetFormula

// Begin Class UCTLModel Function GetFormulas
struct Z_Construct_UFunction_UCTLModel_GetFormulas_Statics
{
	struct CTLModel_eventGetFormulas_Parms
	{
		TMap<int32,UCTLFormula*> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Model" },
		{ "ModuleRelativePath", "Public/Model/CTLModel.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_ValueProp;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCTLModel_GetFormulas_Statics::NewProp_ReturnValue_ValueProp = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UCTLFormula_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UCTLModel_GetFormulas_Statics::NewProp_ReturnValue_Key_KeyProp = { "ReturnValue_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UCTLModel_GetFormulas_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000008000582, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CTLModel_eventGetFormulas_Parms, ReturnValue), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCTLModel_GetFormulas_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCTLModel_GetFormulas_Statics::NewProp_ReturnValue_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCTLModel_GetFormulas_Statics::NewProp_ReturnValue_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCTLModel_GetFormulas_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCTLModel_GetFormulas_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCTLModel_GetFormulas_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCTLModel, nullptr, "GetFormulas", nullptr, nullptr, Z_Construct_UFunction_UCTLModel_GetFormulas_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCTLModel_GetFormulas_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCTLModel_GetFormulas_Statics::CTLModel_eventGetFormulas_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCTLModel_GetFormulas_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCTLModel_GetFormulas_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCTLModel_GetFormulas_Statics::CTLModel_eventGetFormulas_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCTLModel_GetFormulas()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCTLModel_GetFormulas_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCTLModel::execGetFormulas)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TMap<int32,UCTLFormula*>*)Z_Param__Result=P_THIS->GetFormulas();
	P_NATIVE_END;
}
// End Class UCTLModel Function GetFormulas

// Begin Class UCTLModel Function GetPlayerActionRates
struct Z_Construct_UFunction_UCTLModel_GetPlayerActionRates_Statics
{
	struct CTLModel_eventGetPlayerActionRates_Parms
	{
		TMap<ECharacterActions,float> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Model" },
		{ "ModuleRelativePath", "Public/Model/CTLModel.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue_ValueProp;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Key_KeyProp_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCTLModel_GetPlayerActionRates_Statics::NewProp_ReturnValue_ValueProp = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCTLModel_GetPlayerActionRates_Statics::NewProp_ReturnValue_Key_KeyProp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UCTLModel_GetPlayerActionRates_Statics::NewProp_ReturnValue_Key_KeyProp = { "ReturnValue_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_CTL_Labyrinth_ECharacterActions, METADATA_PARAMS(0, nullptr) }; // 997799828
const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UCTLModel_GetPlayerActionRates_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CTLModel_eventGetPlayerActionRates_Parms, ReturnValue), EMapPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 997799828
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCTLModel_GetPlayerActionRates_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCTLModel_GetPlayerActionRates_Statics::NewProp_ReturnValue_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCTLModel_GetPlayerActionRates_Statics::NewProp_ReturnValue_Key_KeyProp_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCTLModel_GetPlayerActionRates_Statics::NewProp_ReturnValue_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCTLModel_GetPlayerActionRates_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCTLModel_GetPlayerActionRates_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCTLModel_GetPlayerActionRates_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCTLModel, nullptr, "GetPlayerActionRates", nullptr, nullptr, Z_Construct_UFunction_UCTLModel_GetPlayerActionRates_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCTLModel_GetPlayerActionRates_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCTLModel_GetPlayerActionRates_Statics::CTLModel_eventGetPlayerActionRates_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCTLModel_GetPlayerActionRates_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCTLModel_GetPlayerActionRates_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCTLModel_GetPlayerActionRates_Statics::CTLModel_eventGetPlayerActionRates_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCTLModel_GetPlayerActionRates()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCTLModel_GetPlayerActionRates_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCTLModel::execGetPlayerActionRates)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TMap<ECharacterActions,float>*)Z_Param__Result=P_THIS->GetPlayerActionRates();
	P_NATIVE_END;
}
// End Class UCTLModel Function GetPlayerActionRates

// Begin Class UCTLModel Function GetPredicateManager
struct Z_Construct_UFunction_UCTLModel_GetPredicateManager_Statics
{
	struct CTLModel_eventGetPredicateManager_Parms
	{
		UPredicateManager* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Model" },
		{ "ModuleRelativePath", "Public/Model/CTLModel.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCTLModel_GetPredicateManager_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CTLModel_eventGetPredicateManager_Parms, ReturnValue), Z_Construct_UClass_UPredicateManager_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCTLModel_GetPredicateManager_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCTLModel_GetPredicateManager_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCTLModel_GetPredicateManager_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCTLModel_GetPredicateManager_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCTLModel, nullptr, "GetPredicateManager", nullptr, nullptr, Z_Construct_UFunction_UCTLModel_GetPredicateManager_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCTLModel_GetPredicateManager_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCTLModel_GetPredicateManager_Statics::CTLModel_eventGetPredicateManager_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCTLModel_GetPredicateManager_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCTLModel_GetPredicateManager_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCTLModel_GetPredicateManager_Statics::CTLModel_eventGetPredicateManager_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCTLModel_GetPredicateManager()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCTLModel_GetPredicateManager_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCTLModel::execGetPredicateManager)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UPredicateManager**)Z_Param__Result=P_THIS->GetPredicateManager();
	P_NATIVE_END;
}
// End Class UCTLModel Function GetPredicateManager

// Begin Class UCTLModel Function GetReachableNodes
struct Z_Construct_UFunction_UCTLModel_GetReachableNodes_Statics
{
	struct CTLModel_eventGetReachableNodes_Parms
	{
		UStateNode* StartNode;
		TArray<UStateNode*> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Model" },
		{ "ModuleRelativePath", "Public/Model/CTLModel.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StartNode;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCTLModel_GetReachableNodes_Statics::NewProp_StartNode = { "StartNode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CTLModel_eventGetReachableNodes_Parms, StartNode), Z_Construct_UClass_UStateNode_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCTLModel_GetReachableNodes_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UStateNode_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCTLModel_GetReachableNodes_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CTLModel_eventGetReachableNodes_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCTLModel_GetReachableNodes_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCTLModel_GetReachableNodes_Statics::NewProp_StartNode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCTLModel_GetReachableNodes_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCTLModel_GetReachableNodes_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCTLModel_GetReachableNodes_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCTLModel_GetReachableNodes_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCTLModel, nullptr, "GetReachableNodes", nullptr, nullptr, Z_Construct_UFunction_UCTLModel_GetReachableNodes_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCTLModel_GetReachableNodes_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCTLModel_GetReachableNodes_Statics::CTLModel_eventGetReachableNodes_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCTLModel_GetReachableNodes_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCTLModel_GetReachableNodes_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCTLModel_GetReachableNodes_Statics::CTLModel_eventGetReachableNodes_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCTLModel_GetReachableNodes()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCTLModel_GetReachableNodes_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCTLModel::execGetReachableNodes)
{
	P_GET_OBJECT(UStateNode,Z_Param_StartNode);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<UStateNode*>*)Z_Param__Result=P_THIS->GetReachableNodes(Z_Param_StartNode);
	P_NATIVE_END;
}
// End Class UCTLModel Function GetReachableNodes

// Begin Class UCTLModel Function GetRootNode
struct Z_Construct_UFunction_UCTLModel_GetRootNode_Statics
{
	struct CTLModel_eventGetRootNode_Parms
	{
		UStateNode* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Model" },
		{ "ModuleRelativePath", "Public/Model/CTLModel.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCTLModel_GetRootNode_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CTLModel_eventGetRootNode_Parms, ReturnValue), Z_Construct_UClass_UStateNode_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCTLModel_GetRootNode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCTLModel_GetRootNode_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCTLModel_GetRootNode_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCTLModel_GetRootNode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCTLModel, nullptr, "GetRootNode", nullptr, nullptr, Z_Construct_UFunction_UCTLModel_GetRootNode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCTLModel_GetRootNode_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCTLModel_GetRootNode_Statics::CTLModel_eventGetRootNode_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCTLModel_GetRootNode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCTLModel_GetRootNode_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCTLModel_GetRootNode_Statics::CTLModel_eventGetRootNode_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCTLModel_GetRootNode()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCTLModel_GetRootNode_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCTLModel::execGetRootNode)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UStateNode**)Z_Param__Result=P_THIS->GetRootNode();
	P_NATIVE_END;
}
// End Class UCTLModel Function GetRootNode

// Begin Class UCTLModel Function GetStateNodes
struct Z_Construct_UFunction_UCTLModel_GetStateNodes_Statics
{
	struct CTLModel_eventGetStateNodes_Parms
	{
		TMap<FString,UStateNode*> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Model" },
		{ "ModuleRelativePath", "Public/Model/CTLModel.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCTLModel_GetStateNodes_Statics::NewProp_ReturnValue_ValueProp = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UStateNode_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCTLModel_GetStateNodes_Statics::NewProp_ReturnValue_Key_KeyProp = { "ReturnValue_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UCTLModel_GetStateNodes_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000008000582, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CTLModel_eventGetStateNodes_Parms, ReturnValue), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCTLModel_GetStateNodes_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCTLModel_GetStateNodes_Statics::NewProp_ReturnValue_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCTLModel_GetStateNodes_Statics::NewProp_ReturnValue_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCTLModel_GetStateNodes_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCTLModel_GetStateNodes_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCTLModel_GetStateNodes_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCTLModel, nullptr, "GetStateNodes", nullptr, nullptr, Z_Construct_UFunction_UCTLModel_GetStateNodes_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCTLModel_GetStateNodes_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCTLModel_GetStateNodes_Statics::CTLModel_eventGetStateNodes_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCTLModel_GetStateNodes_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCTLModel_GetStateNodes_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCTLModel_GetStateNodes_Statics::CTLModel_eventGetStateNodes_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCTLModel_GetStateNodes()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCTLModel_GetStateNodes_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCTLModel::execGetStateNodes)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TMap<FString,UStateNode*>*)Z_Param__Result=P_THIS->GetStateNodes();
	P_NATIVE_END;
}
// End Class UCTLModel Function GetStateNodes

// Begin Class UCTLModel Function InitializeModel
struct Z_Construct_UFunction_UCTLModel_InitializeModel_Statics
{
	struct CTLModel_eventInitializeModel_Parms
	{
		FString Character1Class;
		FString Character2Class;
		TMap<ECharacterActions,float> ActionRates;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Model" },
		{ "ModuleRelativePath", "Public/Model/CTLModel.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Character1Class_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Character2Class_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActionRates_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_Character1Class;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Character2Class;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ActionRates_ValueProp;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ActionRates_Key_KeyProp_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ActionRates_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_ActionRates;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCTLModel_InitializeModel_Statics::NewProp_Character1Class = { "Character1Class", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CTLModel_eventInitializeModel_Parms, Character1Class), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Character1Class_MetaData), NewProp_Character1Class_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCTLModel_InitializeModel_Statics::NewProp_Character2Class = { "Character2Class", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CTLModel_eventInitializeModel_Parms, Character2Class), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Character2Class_MetaData), NewProp_Character2Class_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCTLModel_InitializeModel_Statics::NewProp_ActionRates_ValueProp = { "ActionRates", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCTLModel_InitializeModel_Statics::NewProp_ActionRates_Key_KeyProp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UCTLModel_InitializeModel_Statics::NewProp_ActionRates_Key_KeyProp = { "ActionRates_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_CTL_Labyrinth_ECharacterActions, METADATA_PARAMS(0, nullptr) }; // 997799828
const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UCTLModel_InitializeModel_Statics::NewProp_ActionRates = { "ActionRates", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CTLModel_eventInitializeModel_Parms, ActionRates), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActionRates_MetaData), NewProp_ActionRates_MetaData) }; // 997799828
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCTLModel_InitializeModel_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCTLModel_InitializeModel_Statics::NewProp_Character1Class,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCTLModel_InitializeModel_Statics::NewProp_Character2Class,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCTLModel_InitializeModel_Statics::NewProp_ActionRates_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCTLModel_InitializeModel_Statics::NewProp_ActionRates_Key_KeyProp_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCTLModel_InitializeModel_Statics::NewProp_ActionRates_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCTLModel_InitializeModel_Statics::NewProp_ActionRates,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCTLModel_InitializeModel_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCTLModel_InitializeModel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCTLModel, nullptr, "InitializeModel", nullptr, nullptr, Z_Construct_UFunction_UCTLModel_InitializeModel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCTLModel_InitializeModel_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCTLModel_InitializeModel_Statics::CTLModel_eventInitializeModel_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCTLModel_InitializeModel_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCTLModel_InitializeModel_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCTLModel_InitializeModel_Statics::CTLModel_eventInitializeModel_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCTLModel_InitializeModel()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCTLModel_InitializeModel_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCTLModel::execInitializeModel)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Character1Class);
	P_GET_PROPERTY(FStrProperty,Z_Param_Character2Class);
	P_GET_TMAP(ECharacterActions,float,Z_Param_ActionRates);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeModel(Z_Param_Character1Class,Z_Param_Character2Class,Z_Param_ActionRates);
	P_NATIVE_END;
}
// End Class UCTLModel Function InitializeModel

// Begin Class UCTLModel
void UCTLModel::StaticRegisterNativesUCTLModel()
{
	UClass* Class = UCTLModel::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "DebugPrintModel", &UCTLModel::execDebugPrintModel },
		{ "EvaluateFormula", &UCTLModel::execEvaluateFormula },
		{ "GetFormula", &UCTLModel::execGetFormula },
		{ "GetFormulas", &UCTLModel::execGetFormulas },
		{ "GetPlayerActionRates", &UCTLModel::execGetPlayerActionRates },
		{ "GetPredicateManager", &UCTLModel::execGetPredicateManager },
		{ "GetReachableNodes", &UCTLModel::execGetReachableNodes },
		{ "GetRootNode", &UCTLModel::execGetRootNode },
		{ "GetStateNodes", &UCTLModel::execGetStateNodes },
		{ "InitializeModel", &UCTLModel::execInitializeModel },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCTLModel);
UClass* Z_Construct_UClass_UCTLModel_NoRegister()
{
	return UCTLModel::StaticClass();
}
struct Z_Construct_UClass_UCTLModel_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Model/CTLModel.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Model/CTLModel.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_stateNodes_MetaData[] = {
		{ "ModuleRelativePath", "Public/Model/CTLModel.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_rootNode_MetaData[] = {
		{ "ModuleRelativePath", "Public/Model/CTLModel.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Formulas_MetaData[] = {
		{ "ModuleRelativePath", "Public/Model/CTLModel.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PredicateManager_MetaData[] = {
		{ "ModuleRelativePath", "Public/Model/CTLModel.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerActionRates_MetaData[] = {
		{ "ModuleRelativePath", "Public/Model/CTLModel.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_stateNodes_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_stateNodes_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_stateNodes;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_rootNode;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Formulas_ValueProp;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Formulas_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_Formulas;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PredicateManager;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayerActionRates_ValueProp;
	static const UECodeGen_Private::FBytePropertyParams NewProp_PlayerActionRates_Key_KeyProp_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_PlayerActionRates_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_PlayerActionRates;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCTLModel_DebugPrintModel, "DebugPrintModel" }, // 929795102
		{ &Z_Construct_UFunction_UCTLModel_EvaluateFormula, "EvaluateFormula" }, // 2565437833
		{ &Z_Construct_UFunction_UCTLModel_GetFormula, "GetFormula" }, // 2532571443
		{ &Z_Construct_UFunction_UCTLModel_GetFormulas, "GetFormulas" }, // 3559519032
		{ &Z_Construct_UFunction_UCTLModel_GetPlayerActionRates, "GetPlayerActionRates" }, // 233426100
		{ &Z_Construct_UFunction_UCTLModel_GetPredicateManager, "GetPredicateManager" }, // 3149239671
		{ &Z_Construct_UFunction_UCTLModel_GetReachableNodes, "GetReachableNodes" }, // 2871945672
		{ &Z_Construct_UFunction_UCTLModel_GetRootNode, "GetRootNode" }, // 3047178962
		{ &Z_Construct_UFunction_UCTLModel_GetStateNodes, "GetStateNodes" }, // 1143806030
		{ &Z_Construct_UFunction_UCTLModel_InitializeModel, "InitializeModel" }, // 4222063141
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCTLModel>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCTLModel_Statics::NewProp_stateNodes_ValueProp = { "stateNodes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UStateNode_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UCTLModel_Statics::NewProp_stateNodes_Key_KeyProp = { "stateNodes_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UCTLModel_Statics::NewProp_stateNodes = { "stateNodes", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCTLModel, stateNodes), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_stateNodes_MetaData), NewProp_stateNodes_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCTLModel_Statics::NewProp_rootNode = { "rootNode", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCTLModel, rootNode), Z_Construct_UClass_UStateNode_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_rootNode_MetaData), NewProp_rootNode_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCTLModel_Statics::NewProp_Formulas_ValueProp = { "Formulas", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UCTLFormula_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UCTLModel_Statics::NewProp_Formulas_Key_KeyProp = { "Formulas_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UCTLModel_Statics::NewProp_Formulas = { "Formulas", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCTLModel, Formulas), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Formulas_MetaData), NewProp_Formulas_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCTLModel_Statics::NewProp_PredicateManager = { "PredicateManager", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCTLModel, PredicateManager), Z_Construct_UClass_UPredicateManager_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PredicateManager_MetaData), NewProp_PredicateManager_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCTLModel_Statics::NewProp_PlayerActionRates_ValueProp = { "PlayerActionRates", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UCTLModel_Statics::NewProp_PlayerActionRates_Key_KeyProp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UCTLModel_Statics::NewProp_PlayerActionRates_Key_KeyProp = { "PlayerActionRates_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_CTL_Labyrinth_ECharacterActions, METADATA_PARAMS(0, nullptr) }; // 997799828
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UCTLModel_Statics::NewProp_PlayerActionRates = { "PlayerActionRates", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCTLModel, PlayerActionRates), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerActionRates_MetaData), NewProp_PlayerActionRates_MetaData) }; // 997799828
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCTLModel_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCTLModel_Statics::NewProp_stateNodes_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCTLModel_Statics::NewProp_stateNodes_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCTLModel_Statics::NewProp_stateNodes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCTLModel_Statics::NewProp_rootNode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCTLModel_Statics::NewProp_Formulas_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCTLModel_Statics::NewProp_Formulas_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCTLModel_Statics::NewProp_Formulas,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCTLModel_Statics::NewProp_PredicateManager,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCTLModel_Statics::NewProp_PlayerActionRates_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCTLModel_Statics::NewProp_PlayerActionRates_Key_KeyProp_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCTLModel_Statics::NewProp_PlayerActionRates_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCTLModel_Statics::NewProp_PlayerActionRates,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCTLModel_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UCTLModel_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_CTL_Labyrinth,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCTLModel_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCTLModel_Statics::ClassParams = {
	&UCTLModel::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UCTLModel_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UCTLModel_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCTLModel_Statics::Class_MetaDataParams), Z_Construct_UClass_UCTLModel_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCTLModel()
{
	if (!Z_Registration_Info_UClass_UCTLModel.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCTLModel.OuterSingleton, Z_Construct_UClass_UCTLModel_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCTLModel.OuterSingleton;
}
template<> CTL_LABYRINTH_API UClass* StaticClass<UCTLModel>()
{
	return UCTLModel::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCTLModel);
UCTLModel::~UCTLModel() {}
// End Class UCTLModel

// Begin Registration
struct Z_CompiledInDeferFile_FID_Progetti_Progetti_Unreal_FindMe_LogicFighters_Source_CTL_Labyrinth_Public_Model_CTLModel_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCTLModel, UCTLModel::StaticClass, TEXT("UCTLModel"), &Z_Registration_Info_UClass_UCTLModel, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCTLModel), 3389768684U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Progetti_Progetti_Unreal_FindMe_LogicFighters_Source_CTL_Labyrinth_Public_Model_CTLModel_h_2542082379(TEXT("/Script/CTL_Labyrinth"),
	Z_CompiledInDeferFile_FID_Progetti_Progetti_Unreal_FindMe_LogicFighters_Source_CTL_Labyrinth_Public_Model_CTLModel_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Progetti_Progetti_Unreal_FindMe_LogicFighters_Source_CTL_Labyrinth_Public_Model_CTLModel_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
