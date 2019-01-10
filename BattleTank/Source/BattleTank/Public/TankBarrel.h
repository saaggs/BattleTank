// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
// ClassGroup=(Custom) isn't needed
// To hide UPROPERTY editable fields in Unreal Editor, use after meta=(placeholder), hidecategories = ("category to hide')
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent)/*, hidecategories = ("collision")*/ )
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max downward movement and +1 is max up movement
	void Elevate(float RelativeSpeed);

private:
	// UPROPERTY() makes the varibale below show up in the Unreal Editor Blueprint
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 5;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegrees = 35;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegrees = 0;
	
};
 