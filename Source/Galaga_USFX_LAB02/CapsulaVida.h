// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Capsula.h"
#include "CapsulaVida.generated.h"

/**
 *
 */
UCLASS()
class GALAGA_USFX_LAB02_API ACapsulaVida : public ACapsula
{
	GENERATED_BODY()
protected:
	ACapsulaVida();
	FString tipoCapsula = "Vida";
	class AFacadeShip* FacadeShip;
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
