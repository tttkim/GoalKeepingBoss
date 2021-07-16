// Copyright Epic Games, Inc. All Rights Reserved.

#include "Unreal20210716GameMode.h"
#include "Unreal20210716Character.h"
#include "UObject/ConstructorHelpers.h"
#include "Unreal20210716.h"
#include "BCCharacter.h"
#include "BCPlayerController.h"

AUnreal20210716GameMode::AUnreal20210716GameMode()
{
	DefaultPawnClass = ABCCharacter::StaticClass();
	PlayerControllerClass = ABCPlayerController::StaticClass();
}

void AUnreal20210716GameMode::PostLogin(APlayerController* NewPlayer)
{
	BCLOG(Warning, TEXT("PostLogin Begin"));
	Super::PostLogin(NewPlayer);
	BCLOG(Warning, TEXT("PostLogin End"));
}

