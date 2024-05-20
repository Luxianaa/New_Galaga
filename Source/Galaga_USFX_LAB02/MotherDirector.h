// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IBuilderMotherShip.h"
#include "MotherDirector.generated.h"

UCLASS()
class GALAGA_USFX_LAB02_API AMotherDirector : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMotherDirector();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	 IIBuilderMotherShip* ShipBuilder;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	void ConstructShips();
	

	void SetBuilder(AActor* Builder); //Set the builder


	class AMotherShip* GetMotherShip();

};
