// Fill out your copyright notice in the Description page of Project Settings.

#include "Mechopia.h"
#include "Door.h"


// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	
	CurrentVelocity.X = 0;
	CurrentVelocity.Y = 0;
	CurrentVelocity.Z = 0;
}

// Called every frame
void ADoor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
	SetActorLocation(NewLocation);
}

void ADoor::Move()
{
	SwitchAmount -= 1;

	if (SwitchAmount < 1) {
		CurrentVelocity.Z = -100;
	}
}

