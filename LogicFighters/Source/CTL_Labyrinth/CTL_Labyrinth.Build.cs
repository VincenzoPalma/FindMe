// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CTL_Labyrinth : ModuleRules
{
	public CTL_Labyrinth(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "Json", "JsonUtilities" });

		PrivateDependencyModuleNames.AddRange(new string[] {});

		PrivateIncludePaths.AddRange(new string[] { "CTL_Labyrinth/Private", });

        PublicIncludePaths.AddRange(new string[] { "CTL_Labyrinth/Public" });

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
