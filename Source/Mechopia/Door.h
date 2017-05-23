// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Door.generated.h"

UCLASS()
class MECHOPIA_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	void Move();
	FVector Direction;
	FVector CurrentVelocity;

	UPROPERTY(EditAnywhere, Category = "Switches")       //Category gir en overskrift i Editoren
		int SwitchAmount;
	
};
