// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Gun.h"

// Sets default values
AShooterCharacter::AShooterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AShooterCharacter::BeginPlay()
{
	Super::BeginPlay();
	Gun = GetWorld()->SpawnActor<AGun>(GunType);
	GetMesh()->HideBoneByName(TEXT("weapon_r"),EPhysBodyOp::PBO_None);
	Gun->AttachToComponent(GetMesh(),FAttachmentTransformRules::KeepRelativeTransform,TEXT("WeaponSocket"));
	Gun->SetOwner(this);
	// Health = MaxHealth;
}

// Called every frame
void AShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AShooterCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AShooterCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AShooterCharacter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("LookSides"), this, &AShooterCharacter::LookSides);
	PlayerInputComponent->BindAxis(TEXT("LookUpController"), this, &AShooterCharacter::LookUpController);
	PlayerInputComponent->BindAxis(TEXT("LookSidesController"), this, &AShooterCharacter::LookSidesController);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &AShooterCharacter::DoJump);
	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &AShooterCharacter::Shoot);
}

void AShooterCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(),Value);
}

void AShooterCharacter::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector(),Value);
}

void AShooterCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

void AShooterCharacter::LookSides(float Value)
{
	AddControllerYawInput(Value);
}

void AShooterCharacter::LookUpController(float Value)
{	
	AddControllerPitchInput(Value*UGameplayStatics::GetWorldDeltaSeconds(this)*RotationRate);
}

void AShooterCharacter::LookSidesController(float Value)
{
	AddControllerYawInput(Value*UGameplayStatics::GetWorldDeltaSeconds(this)*RotationRate);
}

void AShooterCharacter::DoJump()
{
	Jump();
}

void AShooterCharacter::Shoot()
{
	Gun->PullTrigger();
}


float AShooterCharacter::TakeDamage(float DamageAmount, struct FDamageEvent const &DamageEvent, class AController *EventInstigator, AActor *DamageCauser) 
{
	float DamageToApply = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	DamageToApply = FMath::Min(Health, DamageToApply);
	Health -= DamageToApply;
	UE_LOG(LogTemp, Warning, TEXT("Health left %f"), Health);

	return DamageToApply;
}

bool AShooterCharacter::IsDead() const
{
	return Health <= 0;
}
