// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Bunch_of_Trains : ModuleRules
{
	public Bunch_of_Trains(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
