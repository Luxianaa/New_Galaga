// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaTransporte.generated.h"

UCLASS()
class GALAGA_USFX_LAB02_API ANaveEnemigaTransporte : public ANaveEnemiga
{
	GENERATED_BODY()
public:

	ANaveEnemigaTransporte();
	// Called every frame
	
protected:
	int VelocidadVertical;
	float Radio = 500.0f; // Radio de la circunferencia
	float Angulo = 0.0f; // Ángulo inicial
	float Speed = 20.0f;
	// Called when the game starts or when spawned
	FString tipoNave = "Transporte";

	virtual void FireProjectile() override; 
	//void FireAliens();

private:
	int32 currentTargetIndex;

	// Velocidad de movimiento de la nave
	float speed = 1000.0f;
	TArray<FVector> targetLocations;
public:
	virtual void Tick(float DeltaTime) override;
	virtual void ReceiveDamage() override; 

};
