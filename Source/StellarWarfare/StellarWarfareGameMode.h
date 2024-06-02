// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "StellarWarfareGameMode.generated.h"

/**
 * 
 */
UCLASS()
class STELLARWARFARE_API AStellarWarfareGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	void PawnKilled(APawn* PawnKilled, AController* Killer);
private:
	void EndGame(bool bIsPlayerWinner, AController* Killer);
};
