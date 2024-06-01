// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTS_PlayerLocationUpdateIfSeen.generated.h"

/**
 * 
 */
UCLASS()
class STELLARWARFARE_API UBTS_PlayerLocationUpdateIfSeen : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTS_PlayerLocationUpdateIfSeen();

protected:
	virtual void TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds) override;
	
};
