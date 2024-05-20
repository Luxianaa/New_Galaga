// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaHacker.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_LAB02_API ANaveEnemigaHacker : public ANaveEnemiga
{
	GENERATED_BODY()
public:

	ANaveEnemigaHacker();
protected:

	FString tipoNave="Hacker";

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
private:
	int32 currentTargetIndex;

	// Velocidad de movimiento de la nave
	float speed = 1000.0f;
	TArray<FVector> targetLocations;
};

