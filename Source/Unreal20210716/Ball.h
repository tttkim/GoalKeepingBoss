// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Unreal20210716.h"
#include "GameFramework/Actor.h"
#include "Ball.generated.h"

UCLASS()
class UNREAL20210716_API ABall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABall();

	UPROPERTY(VisibleAnywhere, Category = "Component")
		UStaticMeshComponent* meshComp;

	UPROPERTY(VisibleAnywhere, Category = "Component")
		USphereComponent* sphereComp;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
