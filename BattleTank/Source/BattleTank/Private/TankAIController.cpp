// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"
#include "TankAIController.h"




void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto AIControlledTank = GetAIControlledTank();
	auto PlayerControlledTank = GetPlayerTank();

	if (!AIControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("AIController IS NOT possessing a tank"));
	}
	if (GetAIControlledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController is possessing: %s"), *(AIControlledTank->GetName()));
	}

	UE_LOG(LogTemp, Warning, TEXT("AIController Begin Play"));

	if (!PlayerControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("Cannot find Player Tank"));
	}
	if (GetPlayerTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("The PlayerControlledTank is: %s"), *(PlayerControlledTank->GetName()));
	}

}


ATank* ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}