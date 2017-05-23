// Fill out your copyright notice in the Description page of Project Settings.

#include "Mechopia.h"
#include "Mushy_HBox.h"


// Sets default values
AMushy_HBox::AMushy_HBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMushy_HBox::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(HBoxTimerHandle, this, &AMushy_HBox::SelfDestruct, 0.5, true);


}

// Called every frame
void AMushy_HBox::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}


void AMushy_HBox::SelfDestruct()
{
	Destroy();
}
