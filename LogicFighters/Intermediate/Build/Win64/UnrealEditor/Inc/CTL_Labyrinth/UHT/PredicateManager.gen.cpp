// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CTL_Labyrinth/Public/PredicateManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePredicateManager() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
CTL_LABYRINTH_API UClass* Z_Construct_UClass_UPredicateManager();
CTL_LABYRINTH_API UClass* Z_Construct_UClass_UPredicateManager_NoRegister();
UPackage* Z_Construct_UPackage__Script_CTL_Labyrinth();
// End Cross Module References

// Begin Class UPredicateManager
void UPredicateManager::StaticRegisterNativesUPredicateManager()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPredicateManager);
UClass* Z_Construct_UClass_UPredicateManager_NoRegister()
{
	return UPredicateManager::StaticClass();
}
struct Z_Construct_UClass_UPredicateManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "PredicateManager.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/PredicateManager.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPredicateManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UPredicateManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_CTL_Labyrinth,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPredicateManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPredicateManager_Statics::ClassParams = {
	&UPredicateManager::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPredicateManager_Statics::Class_MetaDataParams), Z_Construct_UClass_UPredicateManager_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UPredicateManager()
{
	if (!Z_Registration_Info_UClass_UPredicateManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPredicateManager.OuterSingleton, Z_Construct_UClass_UPredicateManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPredicateManager.OuterSingleton;
}
template<> CTL_LABYRINTH_API UClass* StaticClass<UPredicateManager>()
{
	return UPredicateManager::StaticClass();
}
UPredicateManager::UPredicateManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UPredicateManager);
UPredicateManager::~UPredicateManager() {}
// End Class UPredicateManager

// Begin Registration
struct Z_CompiledInDeferFile_FID_LogicFighters_Source_CTL_Labyrinth_Public_PredicateManager_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPredicateManager, UPredicateManager::StaticClass, TEXT("UPredicateManager"), &Z_Registration_Info_UClass_UPredicateManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPredicateManager), 3678295539U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LogicFighters_Source_CTL_Labyrinth_Public_PredicateManager_h_1138550656(TEXT("/Script/CTL_Labyrinth"),
	Z_CompiledInDeferFile_FID_LogicFighters_Source_CTL_Labyrinth_Public_PredicateManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LogicFighters_Source_CTL_Labyrinth_Public_PredicateManager_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
