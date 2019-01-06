// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true; // TODO should this tick

	// ...
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::AimAt(FVector OutHitLocation, float LaunchSpeed)
{
	//auto OurTankName = GetOwner()->GetName();
	//auto BarrelLocation = Barrel->GetComponentLocation().ToString();
	// UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s from %s"), *OurTankName, *OutHitLocation.ToString(), *BarrelLocation);
	if (!Barrel)
	{ 
		UE_LOG(LogTemp, Error, TEXT("Aiming component was unable to find barrel"));
		return;
	}
	
	FVector OutLaunchVelocity;  // Parentheses (0), like FVector OutLaunchVelocity(0), since this FVector is a vector of 3 parameters it sets all parameters to zero i.e. FVector (x, y, z) (0, 0, 0)  
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	//FVector EndLocation = OutHitLocation.GetSafeNormal();

	bool bHaveAimSolution =  UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		OutHitLocation,
		LaunchSpeed,
		false, // default, don't need to put if default
		0, // default, don't need to put if default
		0, // default, don't need to put if default
		ESuggestProjVelocityTraceOption::DoNotTrace
	); // Calculate the OutLaunchVelocity
	
	if (bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		auto TankName = GetOwner()->GetName();
		//UE_LOG(LogTemp, Warning, TEXT("%s is aiming at %s"), *TankName, *AimDirection.ToString());
		MoveBarrelTowards(AimDirection);
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: Aim solution found"), Time);
	}
	else
	{
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: No aim solve found"), Time);
	}
	// if no solution found do nothing

}


void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{

	// My pseudo code ... 
	// Get Barrel Position
	// Get Aim solution
	// Turn Z axis into Pitch Position
	
	// Ben's pseudo code
	// Work-out difference between current barrel rotation and AimDirection 
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	//UE_LOG(LogTemp, Warning, TEXT("AimAsRotator: %s"), *AimAsRotator.ToString());

	Barrel->Elevate(5);  // TODO replace magic number
}
