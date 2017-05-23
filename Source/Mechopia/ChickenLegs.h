// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "ChickenLegs.generated.h"

UCLASS()
class MECHOPIA_API AChickenLegs : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AChickenLegs();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UFUNCTION(BlueprintPure, Category = "Damage")
		int DealDamage();

	UFUNCTION(BlueprintPure, Category = "Damage")
		int OnHit();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")       //Category gir en overskrift i Editoren
		AActor* ThePlayerActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Attacking = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
		int Damage = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
		float Health = 2.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Active = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Close = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Dead = false;

	UPROPERTY(EditAnywhere)
		USoundBase* HitSound;

	UPROPERTY(EditAnywhere, Category = "Spawning")   
		TSubclassOf<class ACrystal> CrystalBlueprint;

	FVector ToPlayer;
	FVector Direction;
	FRotator Rotation;

	float Counter = 1.f;
	float Length;
	void Move();
	void Attack();
	void Death();

	FTimerHandle AttackTimerHandle;
	FTimerHandle DeathTimerHandle;
	
};
