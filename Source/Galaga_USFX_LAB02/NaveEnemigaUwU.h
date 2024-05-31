
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaUwU.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_LAB02_API ANaveEnemigaUwU : public ANaveEnemiga
{
	GENERATED_BODY()
public:

	ANaveEnemigaUwU();
	FString tipoNave = "UwU";
	float FireRate = 1.0f;
	FTimerHandle FireRateTimerHandle; 

	virtual void BeginPlay() override; 

public:
	virtual void Tick(float DeltaTime) override;

	
};




//float speed = 1000.0f;

//float targetXLocations[4]; // Array of x-coordinates of target locations
//float targetYLocations[4]; // Array of y-coordinates of target locations
//int currentTargetIndex = 0; // Index of the current target location
