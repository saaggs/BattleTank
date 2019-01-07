// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"
/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{

	GENERATED_BODY()

public:
	// -1 is max downward movement and +1 is max up movement
	void TurretRotation(float RelativeSpeed);

private:
	// UPROPERTY() makes the varibale below show up in the Unreal Editor Blueprint
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 5;

};
