// Fill out your copyright notice in the Description page of Project Settings.

#include "Mechopia.h"
#include "Door_1_2.h"


// Sets default values
ADoor_1_2::ADoor_1_2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADoor_1_2::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADoor_1_2::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

