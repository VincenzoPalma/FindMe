// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CTL_Labyrinth/Public/Model/ModelStructures.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeModelStructures() {}

// Begin Cross Module References
CTL_LABYRINTH_API UScriptStruct* Z_Construct_UScriptStruct_FActionsArray();
CTL_LABYRINTH_API UScriptStruct* Z_Construct_UScriptStruct_FState();
CTL_LABYRINTH_API UScriptStruct* Z_Construct_UScriptStruct_FTransition();
CTL_LABYRINTH_API UScriptStruct* Z_Construct_UScriptStruct_FVariantValue();
UPackage* Z_Construct_UPackage__Script_CTL_Labyrinth();
// End Cross Module References

// Begin ScriptStruct FVariantValue
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_VariantValue;
class UScriptStruct* FVariantValue::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_VariantValue.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_VariantValue.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FVariantValue, (UObject*)Z_Construct_UPackage__Script_CTL_Labyrinth(), TEXT("VariantValue"));
	}
	return Z_Registration_Info_UScriptStruct_VariantValue.OuterSingleton;
}
template<> CTL_LABYRINTH_API UScriptStruct* StaticStruct<FVariantValue>()
{
	return FVariantValue::StaticStruct();
}
struct Z_Construct_UScriptStruct_FVariantValue_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Model/ModelStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Type_MetaData[] = {
		{ "Category", "Variant" },
		{ "ModuleRelativePath", "Public/Model/ModelStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StringValue_MetaData[] = {
		{ "Category", "Variant" },
		{ "ModuleRelativePath", "Public/Model/ModelStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IntValue_MetaData[] = {
		{ "Category", "Variant" },
		{ "ModuleRelativePath", "Public/Model/ModelStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DoubleValue_MetaData[] = {
		{ "Category", "Variant" },
		{ "ModuleRelativePath", "Public/Model/ModelStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoolValue_MetaData[] = {
		{ "Category", "Variant" },
		{ "ModuleRelativePath", "Public/Model/ModelStructures.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_Type;
	static const UECodeGen_Private::FStrPropertyParams NewProp_StringValue;
	static const UECodeGen_Private::FIntPropertyParams NewProp_IntValue;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_DoubleValue;
	static void NewProp_BoolValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_BoolValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVariantValue>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FVariantValue_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FVariantValue, Type), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Type_MetaData), NewProp_Type_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FVariantValue_Statics::NewProp_StringValue = { "StringValue", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FVariantValue, StringValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StringValue_MetaData), NewProp_StringValue_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FVariantValue_Statics::NewProp_IntValue = { "IntValue", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FVariantValue, IntValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IntValue_MetaData), NewProp_IntValue_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FVariantValue_Statics::NewProp_DoubleValue = { "DoubleValue", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FVariantValue, DoubleValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DoubleValue_MetaData), NewProp_DoubleValue_MetaData) };
void Z_Construct_UScriptStruct_FVariantValue_Statics::NewProp_BoolValue_SetBit(void* Obj)
{
	((FVariantValue*)Obj)->BoolValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FVariantValue_Statics::NewProp_BoolValue = { "BoolValue", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FVariantValue), &Z_Construct_UScriptStruct_FVariantValue_Statics::NewProp_BoolValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoolValue_MetaData), NewProp_BoolValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FVariantValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVariantValue_Statics::NewProp_Type,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVariantValue_Statics::NewProp_StringValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVariantValue_Statics::NewProp_IntValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVariantValue_Statics::NewProp_DoubleValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVariantValue_Statics::NewProp_BoolValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVariantValue_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVariantValue_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_CTL_Labyrinth,
	nullptr,
	&NewStructOps,
	"VariantValue",
	Z_Construct_UScriptStruct_FVariantValue_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVariantValue_Statics::PropPointers),
	sizeof(FVariantValue),
	alignof(FVariantValue),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVariantValue_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FVariantValue_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FVariantValue()
{
	if (!Z_Registration_Info_UScriptStruct_VariantValue.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_VariantValue.InnerSingleton, Z_Construct_UScriptStruct_FVariantValue_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_VariantValue.InnerSingleton;
}
// End ScriptStruct FVariantValue

// Begin ScriptStruct FState
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_State;
class UScriptStruct* FState::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_State.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_State.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FState, (UObject*)Z_Construct_UPackage__Script_CTL_Labyrinth(), TEXT("State"));
	}
	return Z_Registration_Info_UScriptStruct_State.OuterSingleton;
}
template<> CTL_LABYRINTH_API UScriptStruct* StaticStruct<FState>()
{
	return FState::StaticStruct();
}
struct Z_Construct_UScriptStruct_FState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Model/ModelStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Id_MetaData[] = {
		{ "Category", "State" },
		{ "ModuleRelativePath", "Public/Model/ModelStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Properties_MetaData[] = {
		{ "Category", "State" },
		{ "ModuleRelativePath", "Public/Model/ModelStructures.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_Id;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Properties_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Properties_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_Properties;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FState>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FState_Statics::NewProp_Id = { "Id", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FState, Id), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Id_MetaData), NewProp_Id_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FState_Statics::NewProp_Properties_ValueProp = { "Properties", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FVariantValue, METADATA_PARAMS(0, nullptr) }; // 249394340
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FState_Statics::NewProp_Properties_Key_KeyProp = { "Properties_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FState_Statics::NewProp_Properties = { "Properties", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FState, Properties), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Properties_MetaData), NewProp_Properties_MetaData) }; // 249394340
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FState_Statics::NewProp_Id,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FState_Statics::NewProp_Properties_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FState_Statics::NewProp_Properties_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FState_Statics::NewProp_Properties,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FState_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FState_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_CTL_Labyrinth,
	nullptr,
	&NewStructOps,
	"State",
	Z_Construct_UScriptStruct_FState_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FState_Statics::PropPointers),
	sizeof(FState),
	alignof(FState),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FState_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FState_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FState()
{
	if (!Z_Registration_Info_UScriptStruct_State.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_State.InnerSingleton, Z_Construct_UScriptStruct_FState_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_State.InnerSingleton;
}
// End ScriptStruct FState

// Begin ScriptStruct FTransition
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_Transition;
class UScriptStruct* FTransition::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_Transition.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_Transition.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FTransition, (UObject*)Z_Construct_UPackage__Script_CTL_Labyrinth(), TEXT("Transition"));
	}
	return Z_Registration_Info_UScriptStruct_Transition.OuterSingleton;
}
template<> CTL_LABYRINTH_API UScriptStruct* StaticStruct<FTransition>()
{
	return FTransition::StaticStruct();
}
struct Z_Construct_UScriptStruct_FTransition_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Model/ModelStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_From_MetaData[] = {
		{ "Category", "Transition" },
		{ "ModuleRelativePath", "Public/Model/ModelStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_To_MetaData[] = {
		{ "Category", "Transition" },
		{ "ModuleRelativePath", "Public/Model/ModelStructures.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_From;
	static const UECodeGen_Private::FStructPropertyParams NewProp_To;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FTransition>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FTransition_Statics::NewProp_From = { "From", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FTransition, From), Z_Construct_UScriptStruct_FState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_From_MetaData), NewProp_From_MetaData) }; // 4185286744
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FTransition_Statics::NewProp_To = { "To", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FTransition, To), Z_Construct_UScriptStruct_FState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_To_MetaData), NewProp_To_MetaData) }; // 4185286744
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FTransition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTransition_Statics::NewProp_From,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTransition_Statics::NewProp_To,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTransition_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FTransition_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_CTL_Labyrinth,
	nullptr,
	&NewStructOps,
	"Transition",
	Z_Construct_UScriptStruct_FTransition_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTransition_Statics::PropPointers),
	sizeof(FTransition),
	alignof(FTransition),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTransition_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FTransition_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FTransition()
{
	if (!Z_Registration_Info_UScriptStruct_Transition.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_Transition.InnerSingleton, Z_Construct_UScriptStruct_FTransition_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_Transition.InnerSingleton;
}
// End ScriptStruct FTransition

// Begin ScriptStruct FActionsArray
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ActionsArray;
class UScriptStruct* FActionsArray::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ActionsArray.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ActionsArray.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FActionsArray, (UObject*)Z_Construct_UPackage__Script_CTL_Labyrinth(), TEXT("ActionsArray"));
	}
	return Z_Registration_Info_UScriptStruct_ActionsArray.OuterSingleton;
}
template<> CTL_LABYRINTH_API UScriptStruct* StaticStruct<FActionsArray>()
{
	return FActionsArray::StaticStruct();
}
struct Z_Construct_UScriptStruct_FActionsArray_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Model/ModelStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Keys_MetaData[] = {
		{ "ModuleRelativePath", "Public/Model/ModelStructures.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Keys_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Keys;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FActionsArray>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FActionsArray_Statics::NewProp_Keys_Inner = { "Keys", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FActionsArray_Statics::NewProp_Keys = { "Keys", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FActionsArray, Keys), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Keys_MetaData), NewProp_Keys_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FActionsArray_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActionsArray_Statics::NewProp_Keys_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActionsArray_Statics::NewProp_Keys,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActionsArray_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FActionsArray_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_CTL_Labyrinth,
	nullptr,
	&NewStructOps,
	"ActionsArray",
	Z_Construct_UScriptStruct_FActionsArray_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActionsArray_Statics::PropPointers),
	sizeof(FActionsArray),
	alignof(FActionsArray),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActionsArray_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FActionsArray_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FActionsArray()
{
	if (!Z_Registration_Info_UScriptStruct_ActionsArray.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ActionsArray.InnerSingleton, Z_Construct_UScriptStruct_FActionsArray_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_ActionsArray.InnerSingleton;
}
// End ScriptStruct FActionsArray

// Begin Registration
struct Z_CompiledInDeferFile_FID_LogicFighters_Source_CTL_Labyrinth_Public_Model_ModelStructures_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FVariantValue::StaticStruct, Z_Construct_UScriptStruct_FVariantValue_Statics::NewStructOps, TEXT("VariantValue"), &Z_Registration_Info_UScriptStruct_VariantValue, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FVariantValue), 249394340U) },
		{ FState::StaticStruct, Z_Construct_UScriptStruct_FState_Statics::NewStructOps, TEXT("State"), &Z_Registration_Info_UScriptStruct_State, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FState), 4185286744U) },
		{ FTransition::StaticStruct, Z_Construct_UScriptStruct_FTransition_Statics::NewStructOps, TEXT("Transition"), &Z_Registration_Info_UScriptStruct_Transition, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FTransition), 3906078826U) },
		{ FActionsArray::StaticStruct, Z_Construct_UScriptStruct_FActionsArray_Statics::NewStructOps, TEXT("ActionsArray"), &Z_Registration_Info_UScriptStruct_ActionsArray, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FActionsArray), 2461348248U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LogicFighters_Source_CTL_Labyrinth_Public_Model_ModelStructures_h_2753366825(TEXT("/Script/CTL_Labyrinth"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_LogicFighters_Source_CTL_Labyrinth_Public_Model_ModelStructures_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LogicFighters_Source_CTL_Labyrinth_Public_Model_ModelStructures_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
