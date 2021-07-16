// Fill out your copyright notice in the Description page of Project Settings.


#include "BallSpawnPoint.h"
#include "Unreal20210716GameMode.h"

// Sets default values
ABallSpawnPoint::ABallSpawnPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABallSpawnPoint::BeginPlay()
{
	Super::BeginPlay();
	

	// 타이머 맞추기
	GetWorld()->GetTimerManager().SetTimer(createTimer, this, &ABallSpawnPoint::FireBall, createTime, true, 0);
}

// Called every frame
void ABallSpawnPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABallSpawnPoint::FireBall()
{
	
}

