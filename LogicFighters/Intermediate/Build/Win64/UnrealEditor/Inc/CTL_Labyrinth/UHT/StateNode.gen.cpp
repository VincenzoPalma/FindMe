// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CTL_Labyrinth/Public/Model/StateTree/StateNode.h"
#include "CTL_Labyrinth/Public/Model/ModelStructures.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeStateNode() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
CTL_LABYRINTH_API UClass* Z_Construct_UClass_UStateNode();
CTL_LABYRINTH_API UClass* Z_Construct_UClass_UStateNode_NoRegister();
CTL_LABYRINTH_API UScriptStruct* Z_Construct_UScriptStruct_FActionsArray();
CTL_LABYRINTH_API UScriptStruct* Z_Construct_UScriptStruct_FState();
UPackage* Z_Construct_UPackage__Script_CTL_Labyrinth();
// End Cross Module References

// Begin Class UStateNode Function AddChild
struct Z_Construct_UFunction_UStateNode_AddChild_Statics
{
	struct StateNode_eventAddChild_Parms
	{
		FActionsArray actions;
		UStateNode* child;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "StateNode" },
		{ "ModuleRelativePath", "Public/Model/StateTree/StateNode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_actions;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_child;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UStateNode_AddChild_Statics::NewProp_actions = { "actions", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StateNode_eventAddChild_Parms, actions), Z_Construct_UScriptStruct_FActionsArray, METADATA_PARAMS(0, nullptr) }; // 668278770
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UStateNode_AddChild_Statics::NewProp_child = { "child", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StateNode_eventAddChild_Parms, child), Z_Construct_UClass_UStateNode_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UStateNode_AddChild_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UStateNode_AddChild_Statics::NewProp_actions,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UStateNode_AddChild_Statics::NewProp_child,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UStateNode_AddChild_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UStateNode_AddChild_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UStateNode, nullptr, "AddChild", nullptr, nullptr, Z_Construct_UFunction_UStateNode_AddChild_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UStateNode_AddChild_Statics::PropPointers), sizeof(Z_Construct_UFunction_UStateNode_AddChild_Statics::StateNode_eventAddChild_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UStateNode_AddChild_Statics::Function_MetaDataParams), Z_Construct_UFunction_UStateNode_AddChild_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UStateNode_AddChild_Statics::StateNode_eventAddChild_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UStateNode_AddChild()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UStateNode_AddChild_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UStateNode::execAddChild)
{
	P_GET_STRUCT(FActionsArray,Z_Param_actions);
	P_GET_OBJECT(UStateNode,Z_Param_child);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddChild(Z_Param_actions,Z_Param_child);
	P_NATIVE_END;
}
// End Class UStateNode Function AddChild

// Begin Class UStateNode Function GetChildren
struct Z_Construct_UFunction_UStateNode_GetChildren_Statics
{
	struct StateNode_eventGetChildren_Parms
	{
		TArray<UStateNode*> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "StateNode" },
		{ "ModuleRelativePath", "Public/Model/StateTree/StateNode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UStateNode_GetChildren_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UStateNode_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UStateNode_GetChildren_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000582, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StateNode_eventGetChildren_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UStateNode_GetChildren_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UStateNode_GetChildren_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UStateNode_GetChildren_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UStateNode_GetChildren_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UStateNode_GetChildren_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UStateNode, nullptr, "GetChildren", nullptr, nullptr, Z_Construct_UFunction_UStateNode_GetChildren_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UStateNode_GetChildren_Statics::PropPointers), sizeof(Z_Construct_UFunction_UStateNode_GetChildren_Statics::StateNode_eventGetChildren_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UStateNode_GetChildren_Statics::Function_MetaDataParams), Z_Construct_UFunction_UStateNode_GetChildren_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UStateNode_GetChildren_Statics::StateNode_eventGetChildren_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UStateNode_GetChildren()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UStateNode_GetChildren_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UStateNode::execGetChildren)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<UStateNode*>*)Z_Param__Result=P_THIS->GetChildren();
	P_NATIVE_END;
}
// End Class UStateNode Function GetChildren

// Begin Class UStateNode Function GetChildrenMap
struct Z_Construct_UFunction_UStateNode_GetChildrenMap_Statics
{
	struct StateNode_eventGetChildrenMap_Parms
	{
		TMap<FActionsArray,UStateNode*> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintGetter", "" },
		{ "ModuleRelativePath", "Public/Model/StateTree/StateNode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_ValueProp;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UStateNode_GetChildrenMap_Statics::NewProp_ReturnValue_ValueProp = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UStateNode_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UStateNode_GetChildrenMap_Statics::NewProp_ReturnValue_Key_KeyProp = { "ReturnValue_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FActionsArray, METADATA_PARAMS(0, nullptr) }; // 668278770
const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UStateNode_GetChildrenMap_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StateNode_eventGetChildrenMap_Parms, ReturnValue), EMapPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 668278770
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UStateNode_GetChildrenMap_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UStateNode_GetChildrenMap_Statics::NewProp_ReturnValue_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UStateNode_GetChildrenMap_Statics::NewProp_ReturnValue_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UStateNode_GetChildrenMap_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UStateNode_GetChildrenMap_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UStateNode_GetChildrenMap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UStateNode, nullptr, "GetChildrenMap", nullptr, nullptr, Z_Construct_UFunction_UStateNode_GetChildrenMap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UStateNode_GetChildrenMap_Statics::PropPointers), sizeof(Z_Construct_UFunction_UStateNode_GetChildrenMap_Statics::StateNode_eventGetChildrenMap_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UStateNode_GetChildrenMap_Statics::Function_MetaDataParams), Z_Construct_UFunction_UStateNode_GetChildrenMap_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UStateNode_GetChildrenMap_Statics::StateNode_eventGetChildrenMap_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UStateNode_GetChildrenMap()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UStateNode_GetChildrenMap_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UStateNode::execGetChildrenMap)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TMap<FActionsArray,UStateNode*>*)Z_Param__Result=P_THIS->GetChildrenMap();
	P_NATIVE_END;
}
// End Class UStateNode Function GetChildrenMap

// Begin Class UStateNode Function GetState
struct Z_Construct_UFunction_UStateNode_GetState_Statics
{
	struct StateNode_eventGetState_Parms
	{
		FState ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "StateNode" },
		{ "ModuleRelativePath", "Public/Model/StateTree/StateNode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UStateNode_GetState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000008000582, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StateNode_eventGetState_Parms, ReturnValue), Z_Construct_UScriptStruct_FState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) }; // 3986796206
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UStateNode_GetState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UStateNode_GetState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UStateNode_GetState_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UStateNode_GetState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UStateNode, nullptr, "GetState", nullptr, nullptr, Z_Construct_UFunction_UStateNode_GetState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UStateNode_GetState_Statics::PropPointers), sizeof(Z_Construct_UFunction_UStateNode_GetState_Statics::StateNode_eventGetState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UStateNode_GetState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UStateNode_GetState_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UStateNode_GetState_Statics::StateNode_eventGetState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UStateNode_GetState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UStateNode_GetState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UStateNode::execGetState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FState*)Z_Param__Result=P_THIS->GetState();
	P_NATIVE_END;
}
// End Class UStateNode Function GetState

// Begin Class UStateNode Function GetStateData
struct Z_Construct_UFunction_UStateNode_GetStateData_Statics
{
	struct StateNode_eventGetStateData_Parms
	{
		FState ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintGetter", "" },
		{ "ModuleRelativePath", "Public/Model/StateTree/StateNode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UStateNode_GetStateData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StateNode_eventGetStateData_Parms, ReturnValue), Z_Construct_UScriptStruct_FState, METADATA_PARAMS(0, nullptr) }; // 3986796206
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UStateNode_GetStateData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UStateNode_GetStateData_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UStateNode_GetStateData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UStateNode_GetStateData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UStateNode, nullptr, "GetStateData", nullptr, nullptr, Z_Construct_UFunction_UStateNode_GetStateData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UStateNode_GetStateData_Statics::PropPointers), sizeof(Z_Construct_UFunction_UStateNode_GetStateData_Statics::StateNode_eventGetStateData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UStateNode_GetStateData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UStateNode_GetStateData_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UStateNode_GetStateData_Statics::StateNode_eventGetStateData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UStateNode_GetStateData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UStateNode_GetStateData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UStateNode::execGetStateData)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FState*)Z_Param__Result=P_THIS->GetStateData();
	P_NATIVE_END;
}
// End Class UStateNode Function GetStateData

// Begin Class UStateNode Function SetChildrenMap
struct Z_Construct_UFunction_UStateNode_SetChildrenMap_Statics
{
	struct StateNode_eventSetChildrenMap_Parms
	{
		TMap<FActionsArray,UStateNode*> InChildren;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintSetter", "" },
		{ "ModuleRelativePath", "Public/Model/StateTree/StateNode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InChildren_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InChildren_ValueProp;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InChildren_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_InChildren;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UStateNode_SetChildrenMap_Statics::NewProp_InChildren_ValueProp = { "InChildren", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UStateNode_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UStateNode_SetChildrenMap_Statics::NewProp_InChildren_Key_KeyProp = { "InChildren_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FActionsArray, METADATA_PARAMS(0, nullptr) }; // 668278770
const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UStateNode_SetChildrenMap_Statics::NewProp_InChildren = { "InChildren", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StateNode_eventSetChildrenMap_Parms, InChildren), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InChildren_MetaData), NewProp_InChildren_MetaData) }; // 668278770
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UStateNode_SetChildrenMap_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UStateNode_SetChildrenMap_Statics::NewProp_InChildren_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UStateNode_SetChildrenMap_Statics::NewProp_InChildren_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UStateNode_SetChildrenMap_Statics::NewProp_InChildren,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UStateNode_SetChildrenMap_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UStateNode_SetChildrenMap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UStateNode, nullptr, "SetChildrenMap", nullptr, nullptr, Z_Construct_UFunction_UStateNode_SetChildrenMap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UStateNode_SetChildrenMap_Statics::PropPointers), sizeof(Z_Construct_UFunction_UStateNode_SetChildrenMap_Statics::StateNode_eventSetChildrenMap_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UStateNode_SetChildrenMap_Statics::Function_MetaDataParams), Z_Construct_UFunction_UStateNode_SetChildrenMap_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UStateNode_SetChildrenMap_Statics::StateNode_eventSetChildrenMap_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UStateNode_SetChildrenMap()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UStateNode_SetChildrenMap_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UStateNode::execSetChildrenMap)
{
	P_GET_TMAP_REF(FActionsArray,UStateNode*,Z_Param_Out_InChildren);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetChildrenMap(Z_Param_Out_InChildren);
	P_NATIVE_END;
}
// End Class UStateNode Function SetChildrenMap

// Begin Class UStateNode Function SetStateData
struct Z_Construct_UFunction_UStateNode_SetStateData_Statics
{
	struct StateNode_eventSetStateData_Parms
	{
		FState InStateData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintSetter", "" },
		{ "ModuleRelativePath", "Public/Model/StateTree/StateNode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InStateData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_InStateData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UStateNode_SetStateData_Statics::NewProp_InStateData = { "InStateData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StateNode_eventSetStateData_Parms, InStateData), Z_Construct_UScriptStruct_FState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InStateData_MetaData), NewProp_InStateData_MetaData) }; // 3986796206
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UStateNode_SetStateData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UStateNode_SetStateData_Statics::NewProp_InStateData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UStateNode_SetStateData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UStateNode_SetStateData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UStateNode, nullptr, "SetStateData", nullptr, nullptr, Z_Construct_UFunction_UStateNode_SetStateData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UStateNode_SetStateData_Statics::PropPointers), sizeof(Z_Construct_UFunction_UStateNode_SetStateData_Statics::StateNode_eventSetStateData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UStateNode_SetStateData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UStateNode_SetStateData_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UStateNode_SetStateData_Statics::StateNode_eventSetStateData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UStateNode_SetStateData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UStateNode_SetStateData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UStateNode::execSetStateData)
{
	P_GET_STRUCT_REF(FState,Z_Param_Out_InStateData);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetStateData(Z_Param_Out_InStateData);
	P_NATIVE_END;
}
// End Class UStateNode Function SetStateData

// Begin Class UStateNode
void UStateNode::StaticRegisterNativesUStateNode()
{
	UClass* Class = UStateNode::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "AddChild", &UStateNode::execAddChild },
		{ "GetChildren", &UStateNode::execGetChildren },
		{ "GetChildrenMap", &UStateNode::execGetChildrenMap },
		{ "GetState", &UStateNode::execGetState },
		{ "GetStateData", &UStateNode::execGetStateData },
		{ "SetChildrenMap", &UStateNode::execSetChildrenMap },
		{ "SetStateData", &UStateNode::execSetStateData },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UStateNode);
UClass* Z_Construct_UClass_UStateNode_NoRegister()
{
	return UStateNode::StaticClass();
}
struct Z_Construct_UClass_UStateNode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Model/StateTree/StateNode.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Model/StateTree/StateNode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StateData_MetaData[] = {
		{ "BlueprintGetter", "GetStateData" },
		{ "BlueprintSetter", "SetStateData" },
		{ "Category", "StateNode" },
		{ "ModuleRelativePath", "Public/Model/StateTree/StateNode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Children_MetaData[] = {
		{ "BlueprintGetter", "GetChildrenMap" },
		{ "BlueprintSetter", "SetChildrenMap" },
		{ "Category", "StateNode" },
		{ "ModuleRelativePath", "Public/Model/StateTree/StateNode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_StateData;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Children_ValueProp;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Children_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_Children;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UStateNode_AddChild, "AddChild" }, // 2387471046
		{ &Z_Construct_UFunction_UStateNode_GetChildren, "GetChildren" }, // 2815656688
		{ &Z_Construct_UFunction_UStateNode_GetChildrenMap, "GetChildrenMap" }, // 3539743781
		{ &Z_Construct_UFunction_UStateNode_GetState, "GetState" }, // 2267441430
		{ &Z_Construct_UFunction_UStateNode_GetStateData, "GetStateData" }, // 3507421836
		{ &Z_Construct_UFunction_UStateNode_SetChildrenMap, "SetChildrenMap" }, // 1755829306
		{ &Z_Construct_UFunction_UStateNode_SetStateData, "SetStateData" }, // 1846465322
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UStateNode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UStateNode_Statics::NewProp_StateData = { "StateData", nullptr, (EPropertyFlags)0x0040000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UStateNode, StateData), Z_Construct_UScriptStruct_FState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StateData_MetaData), NewProp_StateData_MetaData) }; // 3986796206
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UStateNode_Statics::NewProp_Children_ValueProp = { "Children", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UStateNode_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UStateNode_Statics::NewProp_Children_Key_KeyProp = { "Children_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FActionsArray, METADATA_PARAMS(0, nullptr) }; // 668278770
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UStateNode_Statics::NewProp_Children = { "Children", nullptr, (EPropertyFlags)0x0040000000000004, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UStateNode, Children), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Children_MetaData), NewProp_Children_MetaData) }; // 668278770
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UStateNode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStateNode_Statics::NewProp_StateData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStateNode_Statics::NewProp_Children_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStateNode_Statics::NewProp_Children_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStateNode_Statics::NewProp_Children,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UStateNode_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UStateNode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_CTL_Labyrinth,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UStateNode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UStateNode_Statics::ClassParams = {
	&UStateNode::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UStateNode_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UStateNode_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UStateNode_Statics::Class_MetaDataParams), Z_Construct_UClass_UStateNode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UStateNode()
{
	if (!Z_Registration_Info_UClass_UStateNode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UStateNode.OuterSingleton, Z_Construct_UClass_UStateNode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UStateNode.OuterSingleton;
}
template<> CTL_LABYRINTH_API UClass* StaticClass<UStateNode>()
{
	return UStateNode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UStateNode);
UStateNode::~UStateNode() {}
// End Class UStateNode

// Begin Registration
struct Z_CompiledInDeferFile_FID_LogicFighters_Source_CTL_Labyrinth_Public_Model_StateTree_StateNode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UStateNode, UStateNode::StaticClass, TEXT("UStateNode"), &Z_Registration_Info_UClass_UStateNode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UStateNode), 3812666655U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LogicFighters_Source_CTL_Labyrinth_Public_Model_StateTree_StateNode_h_1912395024(TEXT("/Script/CTL_Labyrinth"),
	Z_CompiledInDeferFile_FID_LogicFighters_Source_CTL_Labyrinth_Public_Model_StateTree_StateNode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LogicFighters_Source_CTL_Labyrinth_Public_Model_StateTree_StateNode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
