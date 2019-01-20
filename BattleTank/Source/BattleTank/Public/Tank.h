// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
//#include "TankAimingComponent.h"  // This include is a forward declaration below
#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Put new includes above this

// Forward Declarations
class UTankBarrel; // Forward Declaration to import class
class UTankTurret;
class UTankAimingComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret* TurretToSet);

	void AimAt(FVector OutHitLocation);

	UFUNCTION(BlueprintCallable, Category = Firing)
	void Fire();

protected:
	UTankAimingComponent* TankAimingComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	// This component doesn't need to tick
	//virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(Editanywhere, Category = Firing)
	float LaunchSpeed = 4000.0; // Find sensible default

	UPROPERTY(Editanywhere, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint; // UClass* or pointer to anything.  Alternative http://docs.unrealengine.com/latest/INT/Programming/UnrealArchitecture/TSubclassOf/ 

	// Local barrel reference for spawning projectile
	UTankBarrel* Barrel = nullptr;
		
};
