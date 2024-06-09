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

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	float LimiteDerecho;
	float LimiteIzquierdo;
	float VelocidadHorizontal;
	int32 DireccionMovimientoHorizontal;
	float Time; 
	//virtual void  Move(class ANavePruebas* Nave,float DeltaTime) override;  
	virtual void Move(class AShipYorke* Yorke) override;  


}; 
