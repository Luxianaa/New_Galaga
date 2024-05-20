// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FacadeShip.generated.h"

UCLASS()
class GALAGA_USFX_LAB02_API AFacadeShip : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFacadeShip();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Ships")
	class AShipRager* ShipRager;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SpawnShipsLevel1();
	void SpawnShipsLevel2();
	void SpawnCapsules();
	void SpawnRagerShips(); 
	FTimerHandle SpawnTimerHandle;

};
