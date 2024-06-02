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
	class ANaveEnemiga* NaveEnemiga;
	class StrategyStraight* StrategyStraight; 
	class ANavesPruebas* NavesPruebas; 


public:
	// Called every frame
	/*TArray<class ANaveEnemiga*> NavesEnemigasLv1; 
	TArray<class ANaveEnemiga*> NavesEnemigasLv2;*/

	virtual void Tick(float DeltaTime) override;
	void SpawnShipsLevel1();
	void SpawnShipsLevel2();
	void SpawnCapsules();
	void SpawnRagerShips();
	//void SpawnMoon();
	FTimerHandle SpawnTimerHandle; 
	void CollideProjectile(AActor* OtherActor);//pawn a NE
	void CollideShield(AActor* OtherActor);//MOthership
	void CollideCrazyCapsule(AActor* OtherActor); //pawn
	void CollideEnergyCapsule(AActor* OtherActor); //pawn	
	void CollideEnemyProjectile(AActor* OtherActor); //pawn
	void CollideLifeCapsule(AActor* OtherActor); //pawn
	void CollideAliens(AActor* OtherActor); 

};
