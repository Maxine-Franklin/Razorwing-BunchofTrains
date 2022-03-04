// Copyright Epic Games, Inc. All Rights Reserved.

#include "Bunch_of_TrainsGameMode.h"
#include "Bunch_of_TrainsHUD.h"
#include "Bunch_of_TrainsCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABunch_of_TrainsGameMode::ABunch_of_TrainsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ABunch_of_TrainsHUD::StaticClass();
}
