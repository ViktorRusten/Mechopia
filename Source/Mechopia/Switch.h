// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Switch.generated.h"

UCLASS()
class MECHOPIA_API ASwitch : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASwitch();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Active;

	UPROPERTY(EditAnywhere, Category = "Door")       //Category gir en overskrift i Editoren
		AActor* TargetActor;

	UFUNCTION(BlueprintPure, Category = "Damage")
		int OnHit();
	
};
