// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NaveEnemiga.h"
#include "IAbsFactory.h"	
#include "FactoryShipLv1.generated.h"

UCLASS()
class GALAGA_USFX_LAB02_API AFactoryShipLv1 : public AActor, public IIAbsFactory
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFactoryShipLv1();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual ANaveEnemiga* CreateShips(FString tipoNave, UWorld* World, FVector SpawnLocation, FRotator ZeroRotator) override;


};
