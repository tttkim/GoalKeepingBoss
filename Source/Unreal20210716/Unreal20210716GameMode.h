// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Unreal20210716.h"
#include "GameFramework/GameModeBase.h"
#include "Unreal20210716GameMode.generated.h"

UCLASS(minimalapi)
class AUnreal20210716GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AUnreal20210716GameMode();

	virtual void PostLogin(APlayerController* NewPlayer) override;
};



