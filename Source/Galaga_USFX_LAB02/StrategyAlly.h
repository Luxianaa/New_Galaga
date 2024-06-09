// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IStrategy.h"
#include "StrategyAlly.generated.h"

UCLASS()
class GALAGA_USFX_LAB02_API AStrategyAlly : public AActor, public IIStrategy
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStrategyAlly();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Move(class AShipYorke* Yorke) override;
private:
	float Radio;// dio de la circunferencia
	float Angulo; // Ángulo inicial
	float Speed; // Velocidad de rotación
	float Time;	
	int32 NumShotsFired; 
	int32 MaxShots; 
};
