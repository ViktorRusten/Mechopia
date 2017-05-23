// Fill out your copyright notice in the Description page of Project Settings.

#include "Mechopia.h"
#include "Switch_1_1.h"
#include "Door_1_1.h"



// Sets default values
ASwitch_1_1::ASwitch_1_1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ASwitch_1_1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASwitch_1_1::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ASwitch_1_1::OnHit()
{
	//ADoor_1_1 * Door = nullptr;
	if (targetActor) {
		UE_LOG(LogTemp, Warning, TEXT("Door is there"));
		ADoor_1_1* TheDoor = Cast<ADoor_1_1>(targetActor);
		TheDoor->Move();
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Dor is not there"));
	}

}

