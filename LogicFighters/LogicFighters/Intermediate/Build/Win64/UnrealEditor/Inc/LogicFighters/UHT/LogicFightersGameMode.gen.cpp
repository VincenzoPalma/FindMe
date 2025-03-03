// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LogicFighters/LogicFightersGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLogicFightersGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
LOGICFIGHTERS_API UClass* Z_Construct_UClass_ALogicFightersGameMode();
LOGICFIGHTERS_API UClass* Z_Construct_UClass_ALogicFightersGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_LogicFighters();
// End Cross Module References

// Begin Class ALogicFightersGameMode
void ALogicFightersGameMode::StaticRegisterNativesALogicFightersGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ALogicFightersGameMode);
UClass* Z_Construct_UClass_ALogicFightersGameMode_NoRegister()
{
	return ALogicFightersGameMode::StaticClass();
}
struct Z_Construct_UClass_ALogicFightersGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "LogicFightersGameMode.h" },
		{ "ModuleRelativePath", "LogicFightersGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ALogicFightersGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ALogicFightersGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_LogicFighters,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ALogicFightersGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ALogicFightersGameMode_Statics::ClassParams = {
	&ALogicFightersGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008802ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ALogicFightersGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ALogicFightersGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ALogicFightersGameMode()
{
	if (!Z_Registration_Info_UClass_ALogicFightersGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ALogicFightersGameMode.OuterSingleton, Z_Construct_UClass_ALogicFightersGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ALogicFightersGameMode.OuterSingleton;
}
template<> LOGICFIGHTERS_API UClass* StaticClass<ALogicFightersGameMode>()
{
	return ALogicFightersGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ALogicFightersGameMode);
ALogicFightersGameMode::~ALogicFightersGameMode() {}
// End Class ALogicFightersGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_LogicFighters_Source_LogicFighters_LogicFightersGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ALogicFightersGameMode, ALogicFightersGameMode::StaticClass, TEXT("ALogicFightersGameMode"), &Z_Registration_Info_UClass_ALogicFightersGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ALogicFightersGameMode), 241036853U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LogicFighters_Source_LogicFighters_LogicFightersGameMode_h_3843774482(TEXT("/Script/LogicFighters"),
	Z_CompiledInDeferFile_FID_LogicFighters_Source_LogicFighters_LogicFightersGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LogicFighters_Source_LogicFighters_LogicFightersGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
