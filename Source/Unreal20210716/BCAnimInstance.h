// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Unreal20210716.h"
#include "Animation/AnimInstance.h"
#include "BCAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL20210716_API UBCAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	

public:
	UBCAnimInstance();
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
		float CurrentPawnSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
		bool IsInAir;
};
