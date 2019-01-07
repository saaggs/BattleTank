// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurret.h"

void UTankTurret::TurretRotation(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, 2, 10);
	auto TurretRotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + TurretRotationChange;
	auto Rotation = FMath::Clamp<float>(RawNewRotation, 2, 10);
	SetRelativeRotation(FRotator(0, Rotation, 0));
}