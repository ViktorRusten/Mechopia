// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/Character.h"
#include "MechopiaCharacter.generated.h"

UCLASS(config = Game)
class AMechopiaCharacter : public ACharacter
{
	GENERATED_BODY()

		/** Camera boom positioning the camera behind the character */
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;
public:
	AMechopiaCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;

protected:

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/**
	* Called via input to turn at a given rate.
	* @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	*/
	void TurnAtRate(float Rate);

	/**
	* Called via input to turn look up/down at a given rate.
	* @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	*/
	void LookUpAtRate(float Rate);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

	void RotateWithMouse();

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION()
		void GainHealth();

	UFUNCTION()
		void Fire();

	UFUNCTION()
		void Punch();

	UFUNCTION()
		void StopPunch();

	UFUNCTION()
		void Shoot();

	UFUNCTION()
		void StopShoot();

	UFUNCTION(BlueprintPure, Category = "Damage")
		int TakingDamage(int Damage);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
		float PlayerHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
		float CurrentHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
		float PlayerHealthHUD;

	UPROPERTY(EditAnywhere, Category = "Spawning")       //Category gir en overskrift i Editoren
		TSubclassOf<class APlayerBullet> BulletBlueprint;

	UPROPERTY(EditAnywhere, Category = "Spawning")
		float SpawnDistance;

	UPROPERTY(EditAnywhere, Category = "Spawning")
		float InvincibleTimer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
		bool Moving;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
		bool Shooting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
		bool Punching;

	UFUNCTION(BlueprintPure, Category = "Damage")
		int MeleeDamage(AActor* Enemy);


	/*UFUNCTION()
		void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
			UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex,
			bool bFromSweep, const FHitResult &SweepResult);
			*/

	UPROPERTY(EditAnywhere, Category = "Melee")
		float DeathTimer; 

private:

	float DamageTimer;

	bool GoingToShoot;

	bool Fired;

	bool Dead;

	FVector MovingVector;

	FTimerHandle ShootTimerHandle;

	FTimerHandle PunchTimerHandle;
};

