// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Model/ModelParser/JsonDataManager.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CTL_LABYRINTH_JsonDataManager_generated_h
#error "JsonDataManager.generated.h already included, missing '#pragma once' in JsonDataManager.h"
#endif
#define CTL_LABYRINTH_JsonDataManager_generated_h

#define FID_CTL_Labyrinth_Source_CTL_Labyrinth_Public_Model_ModelParser_JsonDataManager_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execShutdown);


#define FID_CTL_Labyrinth_Source_CTL_Labyrinth_Public_Model_ModelParser_JsonDataManager_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJsonDataManager(); \
	friend struct Z_Construct_UClass_UJsonDataManager_Statics; \
public: \
	DECLARE_CLASS(UJsonDataManager, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CTL_Labyrinth"), NO_API) \
	DECLARE_SERIALIZER(UJsonDataManager)


#define FID_CTL_Labyrinth_Source_CTL_Labyrinth_Public_Model_ModelParser_JsonDataManager_h_11_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UJsonDataManager(UJsonDataManager&&); \
	UJsonDataManager(const UJsonDataManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJsonDataManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJsonDataManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UJsonDataManager) \
	NO_API virtual ~UJsonDataManager();


#define FID_CTL_Labyrinth_Source_CTL_Labyrinth_Public_Model_ModelParser_JsonDataManager_h_8_PROLOG
#define FID_CTL_Labyrinth_Source_CTL_Labyrinth_Public_Model_ModelParser_JsonDataManager_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_CTL_Labyrinth_Source_CTL_Labyrinth_Public_Model_ModelParser_JsonDataManager_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_CTL_Labyrinth_Source_CTL_Labyrinth_Public_Model_ModelParser_JsonDataManager_h_11_INCLASS_NO_PURE_DECLS \
	FID_CTL_Labyrinth_Source_CTL_Labyrinth_Public_Model_ModelParser_JsonDataManager_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CTL_LABYRINTH_API UClass* StaticClass<class UJsonDataManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_CTL_Labyrinth_Source_CTL_Labyrinth_Public_Model_ModelParser_JsonDataManager_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
