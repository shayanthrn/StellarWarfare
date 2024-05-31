// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyShooterAIController.generated.h"

/**
 * 
 */
UCLASS()
class STELLARWARFARE_API AEnemyShooterAIController : public AAIController
{
	GENERATED_BODY()

public:
	void virtual Tick(float DeltaSeconds) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* AIBehavior;
};
