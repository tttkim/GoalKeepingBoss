// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Unreal20210716.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
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
		USphereComponent* CollisionComponent;

	UPROPERTY(VisibleAnywhere, Category = Movement)
		UProjectileMovementComponent* ProjectileMovementComponent;

	void FireInDirection(const FVector& ShootDirection);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
};
