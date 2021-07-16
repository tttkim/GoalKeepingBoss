// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Unreal20210716.h"
#include "GameFramework/Character.h"
#include "BCCharacter.generated.h"

UCLASS()
class UNREAL20210716_API ABCCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABCCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, Category = Camera)
		USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = Camera)
		UCameraComponent* Camera;

private:
	void MoveRight(float NewAxisValue);
};
