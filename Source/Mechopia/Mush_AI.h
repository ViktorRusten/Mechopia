// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "Mush_AI.generated.h"

/**
 * 
 */
UCLASS()
class MECHOPIA_API AMush_AI : public AAIController
{
	GENERATED_BODY()

		UPROPERTY(transient)
		class UBlackboardComponent *BlackboardComp;
	
	
//	UPROPERTY(transient)
//		class UBehaviourTreeComponent *BehaviourComp;

public:

	AMush_AI();

	virtual void Possess(APawn *InPawn) override;

	uint8 EnemyKeyID;
};
