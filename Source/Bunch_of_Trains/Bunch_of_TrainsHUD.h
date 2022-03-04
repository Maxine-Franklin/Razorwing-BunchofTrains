// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Bunch_of_TrainsHUD.generated.h"

UCLASS()
class ABunch_of_TrainsHUD : public AHUD
{
	GENERATED_BODY()

public:
	ABunch_of_TrainsHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

