// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

UCLASS()
class STELLARWARFARE_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called on taking damage
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const &DamageEvent, class AController *EventInstigator, AActor *DamageCauser) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION(BlueprintPure)
	bool IsDead() const;

private:
	void MoveForward(float Value);
	void MoveRight(float Value);
	void LookUp(float Value);
	void LookSides(float Value);
	void LookUpController(float Value);
	void LookSidesController(float Value);
	void DoJump();
	void Shoot();
	UPROPERTY(EditAnywhere)
	float RotationRate=70;
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AGun> GunType;
	UPROPERTY()
	AGun* Gun;
	UPROPERTY(EditAnywhere)
	float MaxHealth = 100;
	UPROPERTY(VisibleAnywhere)
	float Health;
};
