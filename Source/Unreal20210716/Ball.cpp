// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include <Kismet/GameplayStatics.h>
#include "BCCharacter.h"

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	
	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	CollisionComponent->InitSphereRadius(50.0f);
	RootComponent = meshComp;

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjetileMovementComponent"));

	
	ProjectileMovementComponent->SetUpdatedComponent(meshComp);
	ProjectileMovementComponent->InitialSpeed = 4000.0f;
	ProjectileMovementComponent->MaxSpeed = 4000.0f;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	ProjectileMovementComponent->bShouldBounce = true;
	ProjectileMovementComponent->Bounciness = 0.3f;
	
	InitialLifeSpan = 3.0f;
}

void ABall::FireInDirection(const FVector& ShootDirection)
{
	UE_LOG(LogTemp, Log, TEXT("%f, %f, %f"), ShootDirection.X, ShootDirection.Y, ShootDirection.Z);

	UE_LOG(LogTemp, Log, TEXT("FireInDirection()"));
	ProjectileMovementComponent->Velocity = ShootDirection * ProjectileMovementComponent->InitialSpeed;
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABall::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	
}

