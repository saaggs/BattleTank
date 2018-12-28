// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"




void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto AIControlledTank = GetAIControlledTank();
	
	if (!AIControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("AIController IS NOT possessing a tank"));
	}
	if (GetAIControlledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController is possessing: %s"), *(AIControlledTank->GetName()));
	}

	UE_LOG(LogTemp, Warning, TEXT("AIController Begin Play"));
}


ATank* ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
