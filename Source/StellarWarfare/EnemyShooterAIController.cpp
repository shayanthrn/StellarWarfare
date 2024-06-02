// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ShooterCharacter.h"

void AEnemyShooterAIController::BeginPlay(){

    Super::BeginPlay();
    if(AIBehavior){
        RunBehaviorTree(AIBehavior);
        GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
    }
}
void AEnemyShooterAIController::Tick(float DeltaSeconds) 
{
    Super::Tick(DeltaSeconds);
}

bool AEnemyShooterAIController::IsDead() const
{
    AShooterCharacter* ControlledCharacter = Cast<AShooterCharacter>(GetPawn());
    if (ControlledCharacter)
    {
        return ControlledCharacter->IsDead();
    }

    return true;
}
