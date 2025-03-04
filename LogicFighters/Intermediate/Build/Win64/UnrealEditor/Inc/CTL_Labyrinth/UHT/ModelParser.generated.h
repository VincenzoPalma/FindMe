// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Model/ModelParser/ModelParser.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
 struct FVariantValue;
class UCTLModel;
class UStateNode;
#ifdef CTL_LABYRINTH_ModelParser_generated_h
#error "ModelParser.generated.h already included, missing '#pragma once' in ModelParser.h"
#endif
#define CTL_LABYRINTH_ModelParser_generated_h

#define FID_LogicFighters_Source_CTL_Labyrinth_Public_Model_ModelParser_ModelParser_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execFindAndParseState); \
	DECLARE_FUNCTION(execFindStateWithProperties); \
	DECLARE_FUNCTION(execUpdateModelFromNode); \
	DECLARE_FUNCTION(execLoadPartialModelFromJson); \
	DECLARE_FUNCTION(execParseStartingState); \
	DECLARE_FUNCTION(execLoadModelFromJson);


#define FID_LogicFighters_Source_CTL_Labyrinth_Public_Model_ModelParser_ModelParser_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUModelParser(); \
	friend struct Z_Construct_UClass_UModelParser_Statics; \
public: \
	DECLARE_CLASS(UModelParser, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CTL_Labyrinth"), NO_API) \
	DECLARE_SERIALIZER(UModelParser)


#define FID_LogicFighters_Source_CTL_Labyrinth_Public_Model_ModelParser_ModelParser_h_12_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UModelParser(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UModelParser(UModelParser&&); \
	UModelParser(const UModelParser&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UModelParser); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UModelParser); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UModelParser) \
	NO_API virtual ~UModelParser();


#define FID_LogicFighters_Source_CTL_Labyrinth_Public_Model_ModelParser_ModelParser_h_9_PROLOG
#define FID_LogicFighters_Source_CTL_Labyrinth_Public_Model_ModelParser_ModelParser_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_LogicFighters_Source_CTL_Labyrinth_Public_Model_ModelParser_ModelParser_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_LogicFighters_Source_CTL_Labyrinth_Public_Model_ModelParser_ModelParser_h_12_INCLASS_NO_PURE_DECLS \
	FID_LogicFighters_Source_CTL_Labyrinth_Public_Model_ModelParser_ModelParser_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CTL_LABYRINTH_API UClass* StaticClass<class UModelParser>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_LogicFighters_Source_CTL_Labyrinth_Public_Model_ModelParser_ModelParser_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
