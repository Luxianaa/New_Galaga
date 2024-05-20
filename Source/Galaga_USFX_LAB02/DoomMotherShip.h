// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IBuilderMotherShip.h"
#include "DoomMotherShip.generated.h"

UCLASS()
class GALAGA_USFX_LAB02_API ADoomMotherShip : public AActor, public IIBuilderMotherShip
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoomMotherShip();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	UPROPERTY(VisibleAnywhere, Category = "MotherShip") 
	class AMotherShip* MotherShip; 

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void BuildMotherShipMesh() override;
	virtual void BuildMotor() override;
	virtual void BuildShield() override;
	virtual void BuildPropellants() override;
	virtual void BuildWeapons() override;
	virtual class AMotherShip* GetMotherShip() override; 

};
