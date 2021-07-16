// Fill out your copyright notice in the Description page of Project Settings.


#include "BCPawn.h"
#include "Unreal20210716.h"

// Sets default values
ABCPawn::ABCPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Static Mesh"));
	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));

	RootComponent = Capsule;
	Mesh->SetupAttachment(Mesh);

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_THEBOSS(TEXT("/Game/Character/theboss.theboss"));
	if (SK_THEBOSS.Succeeded())
	{
		Mesh->SetSkeletalMesh(SK_THEBOSS.Object);
	}

	Mesh->SetAnimationMode(EAnimationMode::AnimationBlueprint);

	static ConstructorHelpers::FClassFinder<UAnimInstance> BOSS_ANIM(TEXT("/Game/Animation/BossAnimBlueprint.BossAnimBlueprint_C"));
	if (BOSS_ANIM.Succeeded())
	{
		Mesh->SetAnimInstanceClass(BOSS_ANIM.Class);
	}
}

// Called when the game starts or when spawned
void ABCPawn::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void ABCPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABCPawn::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	BCLOG_S(Warning);
}

void ABCPawn::PossessedBy(AController* NewController)
{
	BCLOG_S(Warning);
	Super::PossessedBy(NewController);
}

// Called to bind functionality to input
void ABCPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ABCPawn::MoveRight);
}

void ABCPawn::MoveRight(float NewAxisValue)
{
	BCLOG(Warning, TEXT("%f"), NewAxisValue);
	AddMovementInput(GetActorRightVector(), NewAxisValue);
}