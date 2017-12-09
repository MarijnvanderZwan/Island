// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class IslandTarget : TargetRules
{
	public IslandTarget(TargetInfo Target) : base (Target)
	{
		Type = TargetType.Game;
		ExtraModuleNames.Add("Island");
	}

}
