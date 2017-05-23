// Fill out your copyright notice in the Description page of Project Settings.

#include "Mechopia.h"
#include "PlayerBullet.h"
#include "Mr_Mushy.h"
#include "ChickenLegs.h"
#include "MechopiaCharacter.h"
#include "Switch.h"
#include "Door.h"


// Sets default values
APlayerBullet::APlayerBullet()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Use a sphere as a simple collision representation.
	MeshComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	// Set the root component to be the collision component.
	RootComponent = MeshComponent;

	//genererer overlapp
	Cast<UShapeComponent>(RootComponent)->bGenerateOverlapEvents = true;
	Cast<UShapeComponent>(RootComponent)->OnComponentBeginOverlap.AddDynamic(this,
		&APlayerBullet::OnOverlap);          //Her er ABullet navnet på klassen vi er inne i.

	Speed = 500;
}

// Called when the game starts or when spawned
void APlayerBullet::BeginPlay()
{
	Super::BeginPlay();
	Forward = GetActorForwardVector();

	//UE_LOG(LogTemp, Warning, TEXT("Bullet was spawned"));

	Timer = 5;
}

// Called every frame and moves the bullet forward
void APlayerBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Location = GetActorLocation();

	SetActorLocation(Location + (Forward * DeltaTime * Speed));

	Timer -= (1 * DeltaTime);

	if (Timer < 0) {
		//UE_LOG(LogTemp, Warning, TEXT("Bullet was destroyed"));
		Destroy();
	}
}

//Overlapping events dependent on what gets overlapped
void APlayerBullet::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
	UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult &SweepResult)
{
	//UE_LOG(LogTemp, Warning, TEXT("Bullet has hit"));

	if (OtherActor->IsA(AMr_Mushy::StaticClass())) {
		//UE_LOG(LogTemp, Warning, TEXT("Bullet hit mr mushy"));
		//UE_LOG(LogTemp, Warning, TEXT("Bullet was destroyed"));
		AMr_Mushy* Enemy = Cast<AMr_Mushy>(OtherActor);
		Enemy->OnHit();
		Destroy();			//Slett kule
	}

	else if (OtherActor->IsA(AChickenLegs::StaticClass())) {
		//UE_LOG(LogTemp, Warning, TEXT("Bullet hit mr mushy"));
		//UE_LOG(LogTemp, Warning, TEXT("Bullet was destroyed"));
		AChickenLegs* Enemy = Cast<AChickenLegs>(OtherActor);
		Enemy->OnHit();
		Destroy();			//Slett kule
	}

	else if (OtherActor->IsA(ASwitch::StaticClass())) {
		//UE_LOG(LogTemp, Warning, TEXT("Bullet hit the switch"));
		ASwitch* Switch = Cast<ASwitch>(OtherActor);
		Switch->OnHit();
		Destroy();
	}

	else if (OtherActor->IsA(ADoor::StaticClass())){
	//UE_LOG(LogTemp, Warning, TEXT("Bullet hit the door"));
	Destroy();
	}

}