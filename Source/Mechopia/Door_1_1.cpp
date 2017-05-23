// Fill out your copyright notice in the Description page of Project Settings.

#include "Mechopia.h"
#include "Door_1_1.h"


// Sets default values
ADoor_1_1::ADoor_1_1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADoor_1_1::BeginPlay()
{
	Super::BeginPlay();
	
	CurrentVelocity.X = 0;
	CurrentVelocity.Y = 0;
	CurrentVelocity.Z = 0;
}

// Called every frame
void ADoor_1_1::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
	SetActorLocation(NewLocation);

}


void ADoor_1_1::Move()
{
	CurrentVelocity.Z = -100;
}