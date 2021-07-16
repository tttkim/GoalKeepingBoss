// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Unreal20210716 : ModuleRules
{
	public Unreal20210716(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
	}
}
