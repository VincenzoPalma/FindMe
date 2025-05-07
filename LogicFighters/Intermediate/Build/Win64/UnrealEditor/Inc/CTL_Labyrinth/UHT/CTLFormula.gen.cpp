// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CTL_Labyrinth/Public/Model/CTL_ModelChecking/CTLFormula.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCTLFormula() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
CTL_LABYRINTH_API UClass* Z_Construct_UClass_UAtomicBoolFormula();
CTL_LABYRINTH_API UClass* Z_Construct_UClass_UAtomicBoolFormula_NoRegister();
CTL_LABYRINTH_API UClass* Z_Construct_UClass_UAtomicDoubleFormula();
CTL_LABYRINTH_API UClass* Z_Construct_UClass_UAtomicDoubleFormula_NoRegister();
CTL_LABYRINTH_API UClass* Z_Construct_UClass_UAtomicIntFormula();
CTL_LABYRINTH_API UClass* Z_Construct_UClass_UAtomicIntFormula_NoRegister();
CTL_LABYRINTH_API UClass* Z_Construct_UClass_UAtomicStringFormula();
CTL_LABYRINTH_API UClass* Z_Construct_UClass_UAtomicStringFormula_NoRegister();
CTL_LABYRINTH_API UClass* Z_Construct_UClass_UBinaryFormula();
CTL_LABYRINTH_API UClass* Z_Construct_UClass_UBinaryFormula_NoRegister();
CTL_LABYRINTH_API UClass* Z_Construct_UClass_UCTLFormula();
CTL_LABYRINTH_API UClass* Z_Construct_UClass_UCTLFormula_NoRegister();
CTL_LABYRINTH_API UClass* Z_Construct_UClass_UCTLModel_NoRegister();
CTL_LABYRINTH_API UClass* Z_Construct_UClass_UStateNode_NoRegister();
CTL_LABYRINTH_API UClass* Z_Construct_UClass_UUnaryFormula();
CTL_LABYRINTH_API UClass* Z_Construct_UClass_UUnaryFormula_NoRegister();
CTL_LABYRINTH_API UEnum* Z_Construct_UEnum_CTL_Labyrinth_ECTLOperator();
UPackage* Z_Construct_UPackage__Script_CTL_Labyrinth();
// End Cross Module References

// Begin Enum ECTLOperator
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ECTLOperator;
static UEnum* ECTLOperator_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ECTLOperator.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ECTLOperator.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_CTL_Labyrinth_ECTLOperator, (UObject*)Z_Construct_UPackage__Script_CTL_Labyrinth(), TEXT("ECTLOperator"));
	}
	return Z_Registration_Info_UEnum_ECTLOperator.OuterSingleton;
}
template<> CTL_LABYRINTH_API UEnum* StaticEnum<ECTLOperator>()
{
	return ECTLOperator_StaticEnum();
}
struct Z_Construct_UEnum_CTL_Labyrinth_ECTLOperator_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "AF.Name", "ECTLOperator::AF" },
		{ "AG.Name", "ECTLOperator::AG" },
		{ "AND.Name", "ECTLOperator::AND" },
		{ "AU.Name", "ECTLOperator::AU" },
		{ "AX.Name", "ECTLOperator::AX" },
		{ "BlueprintType", "true" },
		{ "EF.Name", "ECTLOperator::EF" },
		{ "EG.Name", "ECTLOperator::EG" },
		{ "EU.Name", "ECTLOperator::EU" },
		{ "EX.Name", "ECTLOperator::EX" },
		{ "ModuleRelativePath", "Public/Model/CTL_ModelChecking/CTLFormula.h" },
		{ "NOT.Name", "ECTLOperator::NOT" },
		{ "null.Name", "ECTLOperator::null" },
		{ "OR.Name", "ECTLOperator::OR" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ECTLOperator::AND", (int64)ECTLOperator::AND },
		{ "ECTLOperator::OR", (int64)ECTLOperator::OR },
		{ "ECTLOperator::NOT", (int64)ECTLOperator::NOT },
		{ "ECTLOperator::EX", (int64)ECTLOperator::EX },
		{ "ECTLOperator::AX", (int64)ECTLOperator::AX },
		{ "ECTLOperator::EF", (int64)ECTLOperator::EF },
		{ "ECTLOperator::AF", (int64)ECTLOperator::AF },
		{ "ECTLOperator::EG", (int64)ECTLOperator::EG },
		{ "ECTLOperator::AG", (int64)ECTLOperator::AG },
		{ "ECTLOperator::EU", (int64)ECTLOperator::EU },
		{ "ECTLOperator::AU", (int64)ECTLOperator::AU },
		{ "ECTLOperator::null", (int64)ECTLOperator::null },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_CTL_Labyrinth_ECTLOperator_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_CTL_Labyrinth,
	nullptr,
	"ECTLOperator",
	"ECTLOperator",
	Z_Construct_UEnum_CTL_Labyrinth_ECTLOperator_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_CTL_Labyrinth_ECTLOperator_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_CTL_Labyrinth_ECTLOperator_Statics::Enum_MetaDataParams), Z_Construct_UEnum_CTL_Labyrinth_ECTLOperator_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_CTL_Labyrinth_ECTLOperator()
{
	if (!Z_Registration_Info_UEnum_ECTLOperator.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ECTLOperator.InnerSingleton, Z_Construct_UEnum_CTL_Labyrinth_ECTLOperator_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ECTLOperator.InnerSingleton;
}
// End Enum ECTLOperator

// Begin Class UCTLFormula Function Evaluate
struct Z_Construct_UFunction_UCTLFormula_Evaluate_Statics
{
	struct CTLFormula_eventEvaluate_Parms
	{
		const UCTLModel* model;
		UStateNode* node;
		TMap<FString,int32> unsatScores;
		int32 subFormulaWeight;
		TArray<UStateNode*> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "CTLFormula" },
		{ "ModuleRelativePath", "Public/Model/CTL_ModelChecking/CTLFormula.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_model_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_model;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_node;
	static const UECodeGen_Private::FIntPropertyParams NewProp_unsatScores_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_unsatScores_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_unsatScores;
	static const UECodeGen_Private::FIntPropertyParams NewProp_subFormulaWeight;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCTLFormula_Evaluate_Statics::NewProp_model = { "model", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CTLFormula_eventEvaluate_Parms, model), Z_Construct_UClass_UCTLModel_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_model_MetaData), NewProp_model_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCTLFormula_Evaluate_Statics::NewProp_node = { "node", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CTLFormula_eventEvaluate_Parms, node), Z_Construct_UClass_UStateNode_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UCTLFormula_Evaluate_Statics::NewProp_unsatScores_ValueProp = { "unsatScores", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCTLFormula_Evaluate_Statics::NewProp_unsatScores_Key_KeyProp = { "unsatScores_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UCTLFormula_Evaluate_Statics::NewProp_unsatScores = { "unsatScores", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CTLFormula_eventEvaluate_Parms, unsatScores), EMapPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UCTLFormula_Evaluate_Statics::NewProp_subFormulaWeight = { "subFormulaWeight", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CTLFormula_eventEvaluate_Parms, subFormulaWeight), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCTLFormula_Evaluate_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UStateNode_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCTLFormula_Evaluate_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CTLFormula_eventEvaluate_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCTLFormula_Evaluate_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCTLFormula_Evaluate_Statics::NewProp_model,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCTLFormula_Evaluate_Statics::NewProp_node,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCTLFormula_Evaluate_Statics::NewProp_unsatScores_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCTLFormula_Evaluate_Statics::NewProp_unsatScores_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCTLFormula_Evaluate_Statics::NewProp_unsatScores,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCTLFormula_Evaluate_Statics::NewProp_subFormulaWeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCTLFormula_Evaluate_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCTLFormula_Evaluate_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCTLFormula_Evaluate_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCTLFormula_Evaluate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCTLFormula, nullptr, "Evaluate", nullptr, nullptr, Z_Construct_UFunction_UCTLFormula_Evaluate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCTLFormula_Evaluate_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCTLFormula_Evaluate_Statics::CTLFormula_eventEvaluate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCTLFormula_Evaluate_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCTLFormula_Evaluate_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCTLFormula_Evaluate_Statics::CTLFormula_eventEvaluate_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCTLFormula_Evaluate()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCTLFormula_Evaluate_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCTLFormula::execEvaluate)
{
	P_GET_OBJECT(UCTLModel,Z_Param_model);
	P_GET_OBJECT(UStateNode,Z_Param_node);
	P_GET_TMAP_REF(FString,int32,Z_Param_Out_unsatScores);
	P_GET_PROPERTY(FIntProperty,Z_Param_subFormulaWeight);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<UStateNode*>*)Z_Param__Result=P_THIS->Evaluate(Z_Param_model,Z_Param_node,Z_Param_Out_unsatScores,Z_Param_subFormulaWeight);
	P_NATIVE_END;
}
// End Class UCTLFormula Function Evaluate

// Begin Class UCTLFormula
void UCTLFormula::StaticRegisterNativesUCTLFormula()
{
	UClass* Class = UCTLFormula::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "Evaluate", &UCTLFormula::execEvaluate },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCTLFormula);
UClass* Z_Construct_UClass_UCTLFormula_NoRegister()
{
	return UCTLFormula::StaticClass();
}
struct Z_Construct_UClass_UCTLFormula_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Model/CTL_ModelChecking/CTLFormula.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Model/CTL_ModelChecking/CTLFormula.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCTLFormula_Evaluate, "Evaluate" }, // 2412848565
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCTLFormula>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UCTLFormula_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_CTL_Labyrinth,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCTLFormula_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCTLFormula_Statics::ClassParams = {
	&UCTLFormula::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCTLFormula_Statics::Class_MetaDataParams), Z_Construct_UClass_UCTLFormula_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCTLFormula()
{
	if (!Z_Registration_Info_UClass_UCTLFormula.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCTLFormula.OuterSingleton, Z_Construct_UClass_UCTLFormula_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCTLFormula.OuterSingleton;
}
template<> CTL_LABYRINTH_API UClass* StaticClass<UCTLFormula>()
{
	return UCTLFormula::StaticClass();
}
UCTLFormula::UCTLFormula(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCTLFormula);
// End Class UCTLFormula

// Begin Class UAtomicBoolFormula
void UAtomicBoolFormula::StaticRegisterNativesUAtomicBoolFormula()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UAtomicBoolFormula);
UClass* Z_Construct_UClass_UAtomicBoolFormula_NoRegister()
{
	return UAtomicBoolFormula::StaticClass();
}
struct Z_Construct_UClass_UAtomicBoolFormula_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Model/CTL_ModelChecking/CTLFormula.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Model/CTL_ModelChecking/CTLFormula.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAtomicBoolFormula>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UAtomicBoolFormula_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UCTLFormula,
	(UObject* (*)())Z_Construct_UPackage__Script_CTL_Labyrinth,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAtomicBoolFormula_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAtomicBoolFormula_Statics::ClassParams = {
	&UAtomicBoolFormula::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAtomicBoolFormula_Statics::Class_MetaDataParams), Z_Construct_UClass_UAtomicBoolFormula_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UAtomicBoolFormula()
{
	if (!Z_Registration_Info_UClass_UAtomicBoolFormula.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAtomicBoolFormula.OuterSingleton, Z_Construct_UClass_UAtomicBoolFormula_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAtomicBoolFormula.OuterSingleton;
}
template<> CTL_LABYRINTH_API UClass* StaticClass<UAtomicBoolFormula>()
{
	return UAtomicBoolFormula::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UAtomicBoolFormula);
UAtomicBoolFormula::~UAtomicBoolFormula() {}
// End Class UAtomicBoolFormula

// Begin Class UAtomicIntFormula
void UAtomicIntFormula::StaticRegisterNativesUAtomicIntFormula()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UAtomicIntFormula);
UClass* Z_Construct_UClass_UAtomicIntFormula_NoRegister()
{
	return UAtomicIntFormula::StaticClass();
}
struct Z_Construct_UClass_UAtomicIntFormula_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Model/CTL_ModelChecking/CTLFormula.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Model/CTL_ModelChecking/CTLFormula.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAtomicIntFormula>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UAtomicIntFormula_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UCTLFormula,
	(UObject* (*)())Z_Construct_UPackage__Script_CTL_Labyrinth,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAtomicIntFormula_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAtomicIntFormula_Statics::ClassParams = {
	&UAtomicIntFormula::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAtomicIntFormula_Statics::Class_MetaDataParams), Z_Construct_UClass_UAtomicIntFormula_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UAtomicIntFormula()
{
	if (!Z_Registration_Info_UClass_UAtomicIntFormula.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAtomicIntFormula.OuterSingleton, Z_Construct_UClass_UAtomicIntFormula_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAtomicIntFormula.OuterSingleton;
}
template<> CTL_LABYRINTH_API UClass* StaticClass<UAtomicIntFormula>()
{
	return UAtomicIntFormula::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UAtomicIntFormula);
UAtomicIntFormula::~UAtomicIntFormula() {}
// End Class UAtomicIntFormula

// Begin Class UAtomicDoubleFormula
void UAtomicDoubleFormula::StaticRegisterNativesUAtomicDoubleFormula()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UAtomicDoubleFormula);
UClass* Z_Construct_UClass_UAtomicDoubleFormula_NoRegister()
{
	return UAtomicDoubleFormula::StaticClass();
}
struct Z_Construct_UClass_UAtomicDoubleFormula_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Model/CTL_ModelChecking/CTLFormula.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Model/CTL_ModelChecking/CTLFormula.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAtomicDoubleFormula>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UAtomicDoubleFormula_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UCTLFormula,
	(UObject* (*)())Z_Construct_UPackage__Script_CTL_Labyrinth,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAtomicDoubleFormula_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAtomicDoubleFormula_Statics::ClassParams = {
	&UAtomicDoubleFormula::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAtomicDoubleFormula_Statics::Class_MetaDataParams), Z_Construct_UClass_UAtomicDoubleFormula_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UAtomicDoubleFormula()
{
	if (!Z_Registration_Info_UClass_UAtomicDoubleFormula.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAtomicDoubleFormula.OuterSingleton, Z_Construct_UClass_UAtomicDoubleFormula_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAtomicDoubleFormula.OuterSingleton;
}
template<> CTL_LABYRINTH_API UClass* StaticClass<UAtomicDoubleFormula>()
{
	return UAtomicDoubleFormula::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UAtomicDoubleFormula);
UAtomicDoubleFormula::~UAtomicDoubleFormula() {}
// End Class UAtomicDoubleFormula

// Begin Class UAtomicStringFormula
void UAtomicStringFormula::StaticRegisterNativesUAtomicStringFormula()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UAtomicStringFormula);
UClass* Z_Construct_UClass_UAtomicStringFormula_NoRegister()
{
	return UAtomicStringFormula::StaticClass();
}
struct Z_Construct_UClass_UAtomicStringFormula_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Model/CTL_ModelChecking/CTLFormula.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Model/CTL_ModelChecking/CTLFormula.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAtomicStringFormula>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UAtomicStringFormula_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UCTLFormula,
	(UObject* (*)())Z_Construct_UPackage__Script_CTL_Labyrinth,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAtomicStringFormula_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAtomicStringFormula_Statics::ClassParams = {
	&UAtomicStringFormula::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAtomicStringFormula_Statics::Class_MetaDataParams), Z_Construct_UClass_UAtomicStringFormula_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UAtomicStringFormula()
{
	if (!Z_Registration_Info_UClass_UAtomicStringFormula.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAtomicStringFormula.OuterSingleton, Z_Construct_UClass_UAtomicStringFormula_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAtomicStringFormula.OuterSingleton;
}
template<> CTL_LABYRINTH_API UClass* StaticClass<UAtomicStringFormula>()
{
	return UAtomicStringFormula::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UAtomicStringFormula);
UAtomicStringFormula::~UAtomicStringFormula() {}
// End Class UAtomicStringFormula

// Begin Class UUnaryFormula
void UUnaryFormula::StaticRegisterNativesUUnaryFormula()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UUnaryFormula);
UClass* Z_Construct_UClass_UUnaryFormula_NoRegister()
{
	return UUnaryFormula::StaticClass();
}
struct Z_Construct_UClass_UUnaryFormula_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Model/CTL_ModelChecking/CTLFormula.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Model/CTL_ModelChecking/CTLFormula.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUnaryFormula>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UUnaryFormula_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UCTLFormula,
	(UObject* (*)())Z_Construct_UPackage__Script_CTL_Labyrinth,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UUnaryFormula_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UUnaryFormula_Statics::ClassParams = {
	&UUnaryFormula::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUnaryFormula_Statics::Class_MetaDataParams), Z_Construct_UClass_UUnaryFormula_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UUnaryFormula()
{
	if (!Z_Registration_Info_UClass_UUnaryFormula.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UUnaryFormula.OuterSingleton, Z_Construct_UClass_UUnaryFormula_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UUnaryFormula.OuterSingleton;
}
template<> CTL_LABYRINTH_API UClass* StaticClass<UUnaryFormula>()
{
	return UUnaryFormula::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UUnaryFormula);
UUnaryFormula::~UUnaryFormula() {}
// End Class UUnaryFormula

// Begin Class UBinaryFormula
void UBinaryFormula::StaticRegisterNativesUBinaryFormula()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBinaryFormula);
UClass* Z_Construct_UClass_UBinaryFormula_NoRegister()
{
	return UBinaryFormula::StaticClass();
}
struct Z_Construct_UClass_UBinaryFormula_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Model/CTL_ModelChecking/CTLFormula.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Model/CTL_ModelChecking/CTLFormula.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBinaryFormula>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UBinaryFormula_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UCTLFormula,
	(UObject* (*)())Z_Construct_UPackage__Script_CTL_Labyrinth,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBinaryFormula_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UBinaryFormula_Statics::ClassParams = {
	&UBinaryFormula::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBinaryFormula_Statics::Class_MetaDataParams), Z_Construct_UClass_UBinaryFormula_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UBinaryFormula()
{
	if (!Z_Registration_Info_UClass_UBinaryFormula.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBinaryFormula.OuterSingleton, Z_Construct_UClass_UBinaryFormula_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UBinaryFormula.OuterSingleton;
}
template<> CTL_LABYRINTH_API UClass* StaticClass<UBinaryFormula>()
{
	return UBinaryFormula::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UBinaryFormula);
UBinaryFormula::~UBinaryFormula() {}
// End Class UBinaryFormula

// Begin Registration
struct Z_CompiledInDeferFile_FID_LogicFighters_Source_CTL_Labyrinth_Public_Model_CTL_ModelChecking_CTLFormula_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ ECTLOperator_StaticEnum, TEXT("ECTLOperator"), &Z_Registration_Info_UEnum_ECTLOperator, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3792651690U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCTLFormula, UCTLFormula::StaticClass, TEXT("UCTLFormula"), &Z_Registration_Info_UClass_UCTLFormula, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCTLFormula), 3884231916U) },
		{ Z_Construct_UClass_UAtomicBoolFormula, UAtomicBoolFormula::StaticClass, TEXT("UAtomicBoolFormula"), &Z_Registration_Info_UClass_UAtomicBoolFormula, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAtomicBoolFormula), 1934280304U) },
		{ Z_Construct_UClass_UAtomicIntFormula, UAtomicIntFormula::StaticClass, TEXT("UAtomicIntFormula"), &Z_Registration_Info_UClass_UAtomicIntFormula, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAtomicIntFormula), 1766880805U) },
		{ Z_Construct_UClass_UAtomicDoubleFormula, UAtomicDoubleFormula::StaticClass, TEXT("UAtomicDoubleFormula"), &Z_Registration_Info_UClass_UAtomicDoubleFormula, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAtomicDoubleFormula), 68767771U) },
		{ Z_Construct_UClass_UAtomicStringFormula, UAtomicStringFormula::StaticClass, TEXT("UAtomicStringFormula"), &Z_Registration_Info_UClass_UAtomicStringFormula, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAtomicStringFormula), 972379762U) },
		{ Z_Construct_UClass_UUnaryFormula, UUnaryFormula::StaticClass, TEXT("UUnaryFormula"), &Z_Registration_Info_UClass_UUnaryFormula, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UUnaryFormula), 4058853549U) },
		{ Z_Construct_UClass_UBinaryFormula, UBinaryFormula::StaticClass, TEXT("UBinaryFormula"), &Z_Registration_Info_UClass_UBinaryFormula, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBinaryFormula), 3321732429U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LogicFighters_Source_CTL_Labyrinth_Public_Model_CTL_ModelChecking_CTLFormula_h_3265150907(TEXT("/Script/CTL_Labyrinth"),
	Z_CompiledInDeferFile_FID_LogicFighters_Source_CTL_Labyrinth_Public_Model_CTL_ModelChecking_CTLFormula_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LogicFighters_Source_CTL_Labyrinth_Public_Model_CTL_ModelChecking_CTLFormula_h_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_LogicFighters_Source_CTL_Labyrinth_Public_Model_CTL_ModelChecking_CTLFormula_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LogicFighters_Source_CTL_Labyrinth_Public_Model_CTL_ModelChecking_CTLFormula_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
