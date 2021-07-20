// Fill out your copyright notice in the Description page of Project Settings.


#include "BCCharacter.h"

// Sets default values
ABCCharacter::ABCCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	//SpringArm->SetupAttachment(GetCapsuleComponent());
	Camera->SetupAttachment(GetCapsuleComponent());
	Camera->SetRelativeLocationAndRotation(FVector(-800.0f, 0.0f, 0.0f), FRotator(10.0f, 0.0f, 0.0f));

	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -88.0f), FRotator(0.0f, -90.0f, 0.0f));
	//SpringArm->TargetArmLength = 800.0f;
	//SpringArm->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_THEBOSS(TEXT("/Game/Character/theboss.theboss"));
	if (SK_THEBOSS.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SK_THEBOSS.Object);
	}

	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);

	static ConstructorHelpers::FClassFinder<UAnimInstance> BOSS_ANIM(TEXT("/Game/Animation/BossAnimBlueprint.BossAnimBlueprint_C"));
	if (BOSS_ANIM.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(BOSS_ANIM.Class);
	}
	GetCharacterMovement()->JumpZVelocity = 500.0f;
}

// Called when the game starts or when spawned
void ABCCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABCCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABCCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ABCCharacter::MoveRight);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ABCCharacter::Jump);
}

void ABCCharacter::MoveRight(float NewAxisValue)
{
	// BCLOG(Warning, TEXT("%f"), NewAxisValue);
	AddMovementInput(GetActorRightVector(), NewAxisValue);
}

