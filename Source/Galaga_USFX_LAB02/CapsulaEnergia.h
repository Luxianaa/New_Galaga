// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Capsula.h"
#include "CapsulaEnergia.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_LAB02_API ACapsulaEnergia : public ACapsula
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ACapsulaEnergia();
	FString tipoCapsula = "Energia";
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit); 
protected: 
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	class AFacadeShip* FacadeShip;
	
};
