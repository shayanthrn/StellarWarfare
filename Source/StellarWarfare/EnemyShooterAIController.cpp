// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyShooterAIController.h"
#include "Kismet/GameplayStatics.h"

void AEnemyShooterAIController::BeginPlay(){

    Super::BeginPlay();
    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
    SetFocus(PlayerPawn);
}