// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CTL_Labyrinth/Public/Model/ModelParser/JsonDataManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeJsonDataManager() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
CTL_LABYRINTH_API UClass* Z_Construct_UClass_UJsonDataManager();
CTL_LABYRINTH_API UClass* Z_Construct_UClass_UJsonDataManager_NoRegister();
UPackage* Z_Construct_UPackage__Script_CTL_Labyrinth();
// End Cross Module References

// Begin Class UJsonDataManager Function Shutdown
struct Z_Construct_UFunction_UJsonDataManager_Shutdown_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JsonData" },
		{ "ModuleRelativePath", "Public/Model/ModelParser/JsonDataManager.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJsonDataManager_Shutdown_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UJsonDataManager, nullptr, "Shutdown", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJsonDataManager_Shutdown_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJsonDataManager_Shutdown_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UJsonDataManager_Shutdown()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJsonDataManager_Shutdown_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJsonDataManager::execShutdown)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	UJsonDataManager::Shutdown();
	P_NATIVE_END;
}
// End Class UJsonDataManager Function Shutdown

// Begin Class UJsonDataManager
void UJsonDataManager::StaticRegisterNativesUJsonDataManager()
{
	UClass* Class = UJsonDataManager::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "Shutdown", &UJsonDataManager::execShutdown },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UJsonDataManager);
UClass* Z_Construct_UClass_UJsonDataManager_NoRegister()
{
	return UJsonDataManager::StaticClass();
}
struct Z_Construct_UClass_UJsonDataManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Model/ModelParser/JsonDataManager.h" },
		{ "ModuleRelativePath", "Public/Model/ModelParser/JsonDataManager.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJsonDataManager_Shutdown, "Shutdown" }, // 3744946798
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJsonDataManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UJsonDataManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_CTL_Labyrinth,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJsonDataManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJsonDataManager_Statics::ClassParams = {
	&UJsonDataManager::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJsonDataManager_Statics::Class_MetaDataParams), Z_Construct_UClass_UJsonDataManager_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UJsonDataManager()
{
	if (!Z_Registration_Info_UClass_UJsonDataManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJsonDataManager.OuterSingleton, Z_Construct_UClass_UJsonDataManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJsonDataManager.OuterSingleton;
}
template<> CTL_LABYRINTH_API UClass* StaticClass<UJsonDataManager>()
{
	return UJsonDataManager::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UJsonDataManager);
UJsonDataManager::~UJsonDataManager() {}
// End Class UJsonDataManager

// Begin Registration
struct Z_CompiledInDeferFile_FID_Progetti_Progetti_Unreal_FindMe_LogicFighters_Source_CTL_Labyrinth_Public_Model_ModelParser_JsonDataManager_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJsonDataManager, UJsonDataManager::StaticClass, TEXT("UJsonDataManager"), &Z_Registration_Info_UClass_UJsonDataManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJsonDataManager), 1772032275U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Progetti_Progetti_Unreal_FindMe_LogicFighters_Source_CTL_Labyrinth_Public_Model_ModelParser_JsonDataManager_h_4187109990(TEXT("/Script/CTL_Labyrinth"),
	Z_CompiledInDeferFile_FID_Progetti_Progetti_Unreal_FindMe_LogicFighters_Source_CTL_Labyrinth_Public_Model_ModelParser_JsonDataManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Progetti_Progetti_Unreal_FindMe_LogicFighters_Source_CTL_Labyrinth_Public_Model_ModelParser_JsonDataManager_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
