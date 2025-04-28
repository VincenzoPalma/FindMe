// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Model/StateTree/StateNode.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UStateNode;
struct FActionsArray;
struct FActionsArray; class UStateNode;
struct FState;
#ifdef CTL_LABYRINTH_StateNode_generated_h
#error "StateNode.generated.h already included, missing '#pragma once' in StateNode.h"
#endif
#define CTL_LABYRINTH_StateNode_generated_h

#define FID_Progetti_Progetti_Unreal_FindMe_LogicFighters_Source_CTL_Labyrinth_Public_Model_StateTree_StateNode_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetChildrenMap); \
	DECLARE_FUNCTION(execGetChildrenMap); \
	DECLARE_FUNCTION(execSetStateData); \
	DECLARE_FUNCTION(execGetStateData); \
	DECLARE_FUNCTION(execGetState); \
	DECLARE_FUNCTION(execGetChildren); \
	DECLARE_FUNCTION(execGetParents); \
	DECLARE_FUNCTION(execAddParent); \
	DECLARE_FUNCTION(execAddChild);


#define FID_Progetti_Progetti_Unreal_FindMe_LogicFighters_Source_CTL_Labyrinth_Public_Model_StateTree_StateNode_h_10_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUStateNode(); \
	friend struct Z_Construct_UClass_UStateNode_Statics; \
public: \
	DECLARE_CLASS(UStateNode, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CTL_Labyrinth"), NO_API) \
	DECLARE_SERIALIZER(UStateNode)


#define FID_Progetti_Progetti_Unreal_FindMe_LogicFighters_Source_CTL_Labyrinth_Public_Model_StateTree_StateNode_h_10_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UStateNode(UStateNode&&); \
	UStateNode(const UStateNode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UStateNode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UStateNode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UStateNode) \
	NO_API virtual ~UStateNode();


#define FID_Progetti_Progetti_Unreal_FindMe_LogicFighters_Source_CTL_Labyrinth_Public_Model_StateTree_StateNode_h_7_PROLOG
#define FID_Progetti_Progetti_Unreal_FindMe_LogicFighters_Source_CTL_Labyrinth_Public_Model_StateTree_StateNode_h_10_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Progetti_Progetti_Unreal_FindMe_LogicFighters_Source_CTL_Labyrinth_Public_Model_StateTree_StateNode_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Progetti_Progetti_Unreal_FindMe_LogicFighters_Source_CTL_Labyrinth_Public_Model_StateTree_StateNode_h_10_INCLASS_NO_PURE_DECLS \
	FID_Progetti_Progetti_Unreal_FindMe_LogicFighters_Source_CTL_Labyrinth_Public_Model_StateTree_StateNode_h_10_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CTL_LABYRINTH_API UClass* StaticClass<class UStateNode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Progetti_Progetti_Unreal_FindMe_LogicFighters_Source_CTL_Labyrinth_Public_Model_StateTree_StateNode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
