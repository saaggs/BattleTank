// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

#define OUT


//called at the beginning
void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerController IS NOT possessing a tank"));
	}
	if	(GetControlledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController is possessing: %s"), *(ControlledTank->GetName()));
	}

	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
}


// Tick
//called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	// Super
	Super::Tick(DeltaTime);
	// UE_LOG(LogTemp, Warning, TEXT("Player controller ticking"));
	
	AimTowardsCrosshair();
}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector OutHitLocation;  // Out parameter
	if (GetSightRayHitLocation(OutHitLocation)) // Has "side-effect, is going to line trace"
	{
		UE_LOG(LogTemp, Warning, TEXT("OutHitLocation: %s"), *OutHitLocation.ToString());

		// Get world location of linetrace through crosshair

		// If it hits the landscape
		// Tell controlled tank to aim at this point
	}

}

// Get world location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	OutHitLocation = FVector(1.0);
	return true;
}