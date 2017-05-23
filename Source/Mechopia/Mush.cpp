// Fill out your copyright notice in the Description page of Project Settings.

#include "Mechopia.h"
#include "Mush.h"


// Sets default values
AMush::AMush()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMush::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMush::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AMush::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

