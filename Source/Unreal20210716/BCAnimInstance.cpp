// Fill out your copyright notice in the Description page of Project Settings.


#include "BCAnimInstance.h"
#include "BCCharacter.h"

UBCAnimInstance::UBCAnimInstance()
{
	CurrentPawnSpeed = 0.0f;
	IsInAir = false;
}

void UBCAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto Pawn = TryGetPawnOwner();
	if (::IsValid(Pawn))
	{
		CurrentPawnSpeed = Pawn->GetVelocity().Size();
		auto Character = Cast<ABCCharacter>(Pawn);
		if (Character)
		{
			IsInAir = Character->GetMovementComponent()->IsFalling();
		}
	}
}
