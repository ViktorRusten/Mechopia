// Fill out your copyright notice in the Description page of Project Settings.

#include "Mechopia.h"
#include "Switch.h"
#include "Door.h"


// Sets default values
ASwitch::ASwitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Active = false;
}

// Called when the game starts or when spawned
void ASwitch::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASwitch::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

int ASwitch::OnHit()
{
	if (!Active) {
		//ADoor_1_1 * Door = nullptr;
		if (TargetActor) {
			UE_LOG(LogTemp, Warning, TEXT("Door is there"));
			ADoor* TheDoor = Cast<ADoor>(TargetActor);
			TheDoor->Move();
			Active = true;
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("Door is not there"));
		}
	}
	return 0;
}