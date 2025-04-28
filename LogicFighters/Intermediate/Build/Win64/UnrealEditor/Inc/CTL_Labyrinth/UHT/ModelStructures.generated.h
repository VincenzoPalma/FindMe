// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Model/ModelStructures.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CTL_LABYRINTH_ModelStructures_generated_h
#error "ModelStructures.generated.h already included, missing '#pragma once' in ModelStructures.h"
#endif
#define CTL_LABYRINTH_ModelStructures_generated_h

#define FID_Progetti_Progetti_Unreal_FindMe_LogicFighters_Source_CTL_Labyrinth_Public_Model_ModelStructures_h_21_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FVariantValue_Statics; \
	CTL_LABYRINTH_API static class UScriptStruct* StaticStruct();


template<> CTL_LABYRINTH_API UScriptStruct* StaticStruct<struct FVariantValue>();

#define FID_Progetti_Progetti_Unreal_FindMe_LogicFighters_Source_CTL_Labyrinth_Public_Model_ModelStructures_h_90_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FState_Statics; \
	CTL_LABYRINTH_API static class UScriptStruct* StaticStruct();


template<> CTL_LABYRINTH_API UScriptStruct* StaticStruct<struct FState>();

#define FID_Progetti_Progetti_Unreal_FindMe_LogicFighters_Source_CTL_Labyrinth_Public_Model_ModelStructures_h_103_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FTransition_Statics; \
	CTL_LABYRINTH_API static class UScriptStruct* StaticStruct();


template<> CTL_LABYRINTH_API UScriptStruct* StaticStruct<struct FTransition>();

#define FID_Progetti_Progetti_Unreal_FindMe_LogicFighters_Source_CTL_Labyrinth_Public_Model_ModelStructures_h_115_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FActionsArray_Statics; \
	CTL_LABYRINTH_API static class UScriptStruct* StaticStruct();


template<> CTL_LABYRINTH_API UScriptStruct* StaticStruct<struct FActionsArray>();

#define FID_Progetti_Progetti_Unreal_FindMe_LogicFighters_Source_CTL_Labyrinth_Public_Model_ModelStructures_h_139_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FActionsToNode_Statics; \
	CTL_LABYRINTH_API static class UScriptStruct* StaticStruct();


template<> CTL_LABYRINTH_API UScriptStruct* StaticStruct<struct FActionsToNode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Progetti_Progetti_Unreal_FindMe_LogicFighters_Source_CTL_Labyrinth_Public_Model_ModelStructures_h


#define FOREACH_ENUM_ECHARACTERACTIONS(op) \
	op(ECharacterActions::Attack) \
	op(ECharacterActions::Defense) \
	op(ECharacterActions::CounterAttack) \
	op(ECharacterActions::Buff) \
	op(ECharacterActions::SpecialAttack) \
	op(ECharacterActions::Null) 

enum class ECharacterActions : uint8;
template<> struct TIsUEnumClass<ECharacterActions> { enum { Value = true }; };
template<> CTL_LABYRINTH_API UEnum* StaticEnum<ECharacterActions>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
