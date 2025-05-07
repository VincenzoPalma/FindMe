// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Model/CTLModel.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
 class UCTLFormula;
 class UStateNode;
 struct FActionsToNode;
class UCTLFormula;
class UPredicateManager;
class UStateNode;
enum class ECharacterActions : uint8; 
#ifdef CTL_LABYRINTH_CTLModel_generated_h
#error "CTLModel.generated.h already included, missing '#pragma once' in CTLModel.h"
#endif
#define CTL_LABYRINTH_CTLModel_generated_h

#define FID_LogicFighters_Source_CTL_Labyrinth_Public_Model_CTLModel_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execEvaluateFormula); \
	DECLARE_FUNCTION(execDebugPrintModel); \
	DECLARE_FUNCTION(execGetReachableNodes); \
	DECLARE_FUNCTION(execGetPredicateManager); \
	DECLARE_FUNCTION(execGetFormulas); \
	DECLARE_FUNCTION(execGetStateNodes); \
	DECLARE_FUNCTION(execGetPlayerActionRates); \
	DECLARE_FUNCTION(execGetRootNode); \
	DECLARE_FUNCTION(execGetFormula); \
	DECLARE_FUNCTION(execInitializeModel);


#define FID_LogicFighters_Source_CTL_Labyrinth_Public_Model_CTLModel_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCTLModel(); \
	friend struct Z_Construct_UClass_UCTLModel_Statics; \
public: \
	DECLARE_CLASS(UCTLModel, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CTL_Labyrinth"), NO_API) \
	DECLARE_SERIALIZER(UCTLModel)


#define FID_LogicFighters_Source_CTL_Labyrinth_Public_Model_CTLModel_h_21_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UCTLModel(UCTLModel&&); \
	UCTLModel(const UCTLModel&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCTLModel); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCTLModel); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCTLModel) \
	NO_API virtual ~UCTLModel();


#define FID_LogicFighters_Source_CTL_Labyrinth_Public_Model_CTLModel_h_18_PROLOG
#define FID_LogicFighters_Source_CTL_Labyrinth_Public_Model_CTLModel_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_LogicFighters_Source_CTL_Labyrinth_Public_Model_CTLModel_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_LogicFighters_Source_CTL_Labyrinth_Public_Model_CTLModel_h_21_INCLASS_NO_PURE_DECLS \
	FID_LogicFighters_Source_CTL_Labyrinth_Public_Model_CTLModel_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CTL_LABYRINTH_API UClass* StaticClass<class UCTLModel>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_LogicFighters_Source_CTL_Labyrinth_Public_Model_CTLModel_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
