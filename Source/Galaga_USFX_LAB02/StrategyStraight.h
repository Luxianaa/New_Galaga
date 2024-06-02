// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IStrategy.h"
#include "StrategyStraight.generated.h"

UCLASS()
class GALAGA_USFX_LAB02_API AStrategyStraight : public AActor, public IIStrategy 
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStrategyStraight();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//class AShipYorke* Yorke;

public:	
	float MovimientoNaves = 4; 
	float limiteInferiorY = 1600.0f; 
	int DireccionMovimientoHorizontal = 1; 
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:
	virtual void MoverNave(class AShipYorke* Yorke) override; 
};
