// Fill out your copyright notice in the Description page of Project Settings.


#include "BallSpawnPoint.h"
#include "Unreal20210716GameMode.h"
#include "Ball.h"

// Sets default values
ABallSpawnPoint::ABallSpawnPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));

}

// Called when the game starts or when spawned
void ABallSpawnPoint::BeginPlay()
{
	Super::BeginPlay();
	

	// 타이머 맞추기
	// GetWorld()->GetTimerManager().SetTimer(createTimer, this, &ABallSpawnPoint::FireBall, createTime, true, 0);
}

// Called every frame
void ABallSpawnPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	currentTime += DeltaTime;
	if (currentTime > createTime)
	{
		FireBall();
		currentTime = 0;
	}

}

void ABallSpawnPoint::FireBall()
{
	if (ProjectileClass)
	{


		UE_LOG(LogTemp, Log, TEXT("FireBall()"));

		FVector MuzzleLocation = GetActorLocation() + FVector(200.0f, 0.0f, 0.0f);

		FRotator MuzzleRotation = FRotator(320.0f, 180.0f, 0.0f);
		UWorld* World = GetWorld();
		if (World)
		{
			UE_LOG(LogTemp, Log, TEXT("GetWorld()"));

			FActorSpawnParameters SpawnParams;
			SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

			SpawnParams.Owner = this;
			ABall* Projectile = World->SpawnActor<ABall>(ProjectileClass, MuzzleLocation, MuzzleRotation, SpawnParams);
			if (Projectile)
			{

				FVector LaunchDirection = FVector(1.0f, 0.0f, 0.0f);
				UE_LOG(LogTemp, Log, TEXT("%f, %f, %f"), LaunchDirection.X, LaunchDirection.Y, LaunchDirection.Z);

				Projectile->FireInDirection(LaunchDirection);
			}
		}
	}
}

