// Fill out your copyright notice in the Description page of Project Settings.

#include "Mechopia.h"
#include "Switch.h"
#include "Door.h"


// Sets default values
ASwitch::ASwitch()
{
	Active = false;
}

//When hit by bullet run this code that check if the switch has a door conected to it and then play the doors move
int ASwitch::OnHit()
{
	if (!Active) {
		if (TargetActor) {
			//UE_LOG(LogTemp, Warning, TEXT("Door is there"));
			ADoor* TheDoor = Cast<ADoor>(TargetActor);
			TheDoor->Move();
			Active = true;
		}
	}
	return 0;
}