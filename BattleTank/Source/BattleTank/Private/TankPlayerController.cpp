// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"




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

	// Get world location if linetrace through crosshair
	// If it hits the landscape
		// Tell controlled tank to aim at this point
}