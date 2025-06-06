// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class LogicFighters : ModuleRules
{
	public LogicFighters(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "NavigationSystem", "AIModule", "Niagara", "EnhancedInput" });

        PublicIncludePaths.Add("../../CTL_Labyrinth/Public");

        PrivateDependencyModuleNames.AddRange(new string[] { "CTL_Labyrinth" });

    }
}
