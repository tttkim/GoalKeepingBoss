// Fill out your copyright notice in the Description page of Project Settings.


#include "BCPlayerController.h"

void ABCPlayerController::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	BCLOG_S(Warning);
}

void ABCPlayerController::OnPossess(APawn* aPawn)
{
	BCLOG_S(Warning);
	Super::OnPossess(aPawn);
}

void ABCPlayerController::BeginPlay()
{
	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);
}
