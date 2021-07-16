// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Unreal20210716.h"
#include "GameFramework/Actor.h"
#include "Ball.h"
#include "BallSpawnPoint.generated.h"

UCLASS()
class UNREAL20210716_API ABallSpawnPoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABallSpawnPoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	void FireBall();

	UPROPERTY()
	FTimerHandle createTimer;
public:
	// 필요속성 : 생성시간, 경과시간, 적공장
	UPROPERTY(EditAnywhere, Category = "Setting")
	float createTime = 2;

	UPROPERTY()
	float currentTime = 0;

	// 공장
	UPROPERTY(EditDefaultsOnly, Category = "EnemyClass")
	TSubclassOf<class ABall> ballFactory;
};
