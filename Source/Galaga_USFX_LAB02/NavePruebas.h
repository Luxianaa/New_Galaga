// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NaveEnemiga.h"
#include "IStrategy.h"
#include "NavePruebas.generated.h"

UCLASS()
class GALAGA_USFX_LAB02_API ANavePruebas : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANavePruebas();
	UStaticMeshComponent* NaveMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
//private:
//	 class IIStrategy* Strategy; 
//
//public:
//	void SetStrategy(IIStrategy* NewStrategy);
//	void ActivarEstrategia();
//	//
	//void SetMovementStrategy(AActor* NewStrategy); 
	//void CrearMovimiento(float DeltaTime); 


};
