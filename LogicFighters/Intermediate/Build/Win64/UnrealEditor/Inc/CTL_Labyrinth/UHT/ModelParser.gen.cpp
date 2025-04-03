// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CTL_Labyrinth/Public/Model/ModelParser/ModelParser.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeModelParser() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
CTL_LABYRINTH_API UClass* Z_Construct_UClass_UCTLModel_NoRegister();
CTL_LABYRINTH_API UClass* Z_Construct_UClass_UModelParser();
CTL_LABYRINTH_API UClass* Z_Construct_UClass_UModelParser_NoRegister();
CTL_LABYRINTH_API UClass* Z_Construct_UClass_UStateNode_NoRegister();
UPackage* Z_Construct_UPackage__Script_CTL_Labyrinth();
// End Cross Module References

// Begin Class UModelParser Function ParseStateById
struct Z_Construct_UFunction_UModelParser_ParseStateById_Statics
{
	struct ModelParser_eventParseStateById_Parms
	{
		FString TargetStateId;
		UCTLModel* Model;
		UCTLModel* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Model Parsing" },
		{ "ModuleRelativePath", "Public/Model/ModelParser/ModelParser.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetStateId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_TargetStateId;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Model;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UModelParser_ParseStateById_Statics::NewProp_TargetStateId = { "TargetStateId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModelParser_eventParseStateById_Parms, TargetStateId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetStateId_MetaData), NewProp_TargetStateId_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UModelParser_ParseStateById_Statics::NewProp_Model = { "Model", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModelParser_eventParseStateById_Parms, Model), Z_Construct_UClass_UCTLModel_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UModelParser_ParseStateById_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModelParser_eventParseStateById_Parms, ReturnValue), Z_Construct_UClass_UCTLModel_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UModelParser_ParseStateById_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModelParser_ParseStateById_Statics::NewProp_TargetStateId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModelParser_ParseStateById_Statics::NewProp_Model,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModelParser_ParseStateById_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UModelParser_ParseStateById_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UModelParser_ParseStateById_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UModelParser, nullptr, "ParseStateById", nullptr, nullptr, Z_Construct_UFunction_UModelParser_ParseStateById_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UModelParser_ParseStateById_Statics::PropPointers), sizeof(Z_Construct_UFunction_UModelParser_ParseStateById_Statics::ModelParser_eventParseStateById_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UModelParser_ParseStateById_Statics::Function_MetaDataParams), Z_Construct_UFunction_UModelParser_ParseStateById_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UModelParser_ParseStateById_Statics::ModelParser_eventParseStateById_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModelParser_ParseStateById()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UModelParser_ParseStateById_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UModelParser::execParseStateById)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_TargetStateId);
	P_GET_OBJECT(UCTLModel,Z_Param_Model);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UCTLModel**)Z_Param__Result=UModelParser::ParseStateById(Z_Param_TargetStateId,Z_Param_Model);
	P_NATIVE_END;
}
// End Class UModelParser Function ParseStateById

// Begin Class UModelParser Function UpdateModelFromState
struct Z_Construct_UFunction_UModelParser_UpdateModelFromState_Statics
{
	struct ModelParser_eventUpdateModelFromState_Parms
	{
		const UStateNode* Node;
		UCTLModel* Model;
		int32 Steps;
		UCTLModel* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Model Parsing" },
		{ "ModuleRelativePath", "Public/Model/ModelParser/ModelParser.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Node_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Node;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Model;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Steps;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UModelParser_UpdateModelFromState_Statics::NewProp_Node = { "Node", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModelParser_eventUpdateModelFromState_Parms, Node), Z_Construct_UClass_UStateNode_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Node_MetaData), NewProp_Node_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UModelParser_UpdateModelFromState_Statics::NewProp_Model = { "Model", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModelParser_eventUpdateModelFromState_Parms, Model), Z_Construct_UClass_UCTLModel_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UModelParser_UpdateModelFromState_Statics::NewProp_Steps = { "Steps", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModelParser_eventUpdateModelFromState_Parms, Steps), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UModelParser_UpdateModelFromState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModelParser_eventUpdateModelFromState_Parms, ReturnValue), Z_Construct_UClass_UCTLModel_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UModelParser_UpdateModelFromState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModelParser_UpdateModelFromState_Statics::NewProp_Node,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModelParser_UpdateModelFromState_Statics::NewProp_Model,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModelParser_UpdateModelFromState_Statics::NewProp_Steps,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModelParser_UpdateModelFromState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UModelParser_UpdateModelFromState_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UModelParser_UpdateModelFromState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UModelParser, nullptr, "UpdateModelFromState", nullptr, nullptr, Z_Construct_UFunction_UModelParser_UpdateModelFromState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UModelParser_UpdateModelFromState_Statics::PropPointers), sizeof(Z_Construct_UFunction_UModelParser_UpdateModelFromState_Statics::ModelParser_eventUpdateModelFromState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UModelParser_UpdateModelFromState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UModelParser_UpdateModelFromState_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UModelParser_UpdateModelFromState_Statics::ModelParser_eventUpdateModelFromState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModelParser_UpdateModelFromState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UModelParser_UpdateModelFromState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UModelParser::execUpdateModelFromState)
{
	P_GET_OBJECT(UStateNode,Z_Param_Node);
	P_GET_OBJECT(UCTLModel,Z_Param_Model);
	P_GET_PROPERTY(FIntProperty,Z_Param_Steps);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UCTLModel**)Z_Param__Result=UModelParser::UpdateModelFromState(Z_Param_Node,Z_Param_Model,Z_Param_Steps);
	P_NATIVE_END;
}
// End Class UModelParser Function UpdateModelFromState

// Begin Class UModelParser
void UModelParser::StaticRegisterNativesUModelParser()
{
	UClass* Class = UModelParser::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ParseStateById", &UModelParser::execParseStateById },
		{ "UpdateModelFromState", &UModelParser::execUpdateModelFromState },
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
		{ &Z_Construct_UFunction_UModelParser_ParseStateById, "ParseStateById" }, // 1542493449
		{ &Z_Construct_UFunction_UModelParser_UpdateModelFromState, "UpdateModelFromState" }, // 2607845398
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
struct Z_CompiledInDeferFile_FID_LogicFighters_Source_CTL_Labyrinth_Public_Model_ModelParser_ModelParser_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UModelParser, UModelParser::StaticClass, TEXT("UModelParser"), &Z_Registration_Info_UClass_UModelParser, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UModelParser), 442459906U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LogicFighters_Source_CTL_Labyrinth_Public_Model_ModelParser_ModelParser_h_3092570086(TEXT("/Script/CTL_Labyrinth"),
	Z_CompiledInDeferFile_FID_LogicFighters_Source_CTL_Labyrinth_Public_Model_ModelParser_ModelParser_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LogicFighters_Source_CTL_Labyrinth_Public_Model_ModelParser_ModelParser_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
