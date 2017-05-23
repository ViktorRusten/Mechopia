// Fill out your copyright notice in the Description page of Project Settings.

#include "Mechopia.h"
#include "Crystal.h"
#include "MechopiaCharacter.h"


// Sets default values
ACrystal::ACrystal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Use a sphere as a simple collision representation.
	MeshComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	// Set the root component to be the collision component.
	RootComponent = MeshComponent;

	//generates overlap events
	Cast<UShapeComponent>(RootComponent)->bGenerateOverlapEvents = true;
	Cast<UShapeComponent>(RootComponent)->OnComponentBeginOverlap.AddDynamic(this,
		&ACrystal::OnOverlap);          
}

// Called when the game starts or when spawned
void ACrystal::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACrystal::Tick( float DeltaTime )
{
	//Timer that destroys the object after 20 seconds
	Super::Tick( DeltaTime );
	if (Timer > 0) {
		Timer -= DeltaTime;
	}
	else {
		Destroy();
	}
}

//Overlap event when coming into contact with the player
void ACrystal::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
	UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult &SweepResult)
{
	//checks if the other actor is a player and then calls GainHealth in player
	if (OtherActor->IsA(AMechopiaCharacter::StaticClass())) {

		AMechopiaCharacter* ThePlayer = Cast<AMechopiaCharacter>(OtherActor);
		ThePlayer->GainHealth();
		Destroy();			
	}
}