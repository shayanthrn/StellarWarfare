// Fill out your copyright notice in the Description page of Project Settings.


#include "StellarWarfareGameMode.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "EnemyShooterAIController.h"

void AStellarWarfareGameMode::PawnKilled(APawn* PawnKilled, AController* Killer) 
{
    UE_LOG(LogTemp, Warning, TEXT("A pawn was killed!"));
    APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());
    if (PlayerController)
    {
        EndGame(false,Killer);
    }

    for (AEnemyShooterAIController* Controller : TActorRange<AEnemyShooterAIController>(GetWorld()))
    {
        if (!Controller->IsDead())
        {
            return;
        }
    }
    
    EndGame(true, Killer);

}

void AStellarWarfareGameMode::EndGame(bool bIsPlayerWinner, AController* Killer) 
{
    for (AController* Controller : TActorRange<AController>(GetWorld()))
    {
        if(Controller->IsPlayerController()){
            Controller->GameHasEnded(Killer->GetPawn(), bIsPlayerWinner);
        }
        else{
            Controller->GameHasEnded(Controller->GetPawn(), !bIsPlayerWinner);
        }
    }
}
