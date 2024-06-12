// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ShipPatrol.generated.h"

UCLASS()
class GALAGA_USFX_LAB02_API AShipPatrol : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AShipPatrol();
	UStaticMeshComponent* PatrolMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:

	class AGalaga_USFX_LAB02Pawn* Pawn;
private:

	TArray<FVector> TargetLocations; 
	int32 CurrentTargetIndex; 
	float Speed;  
	float Time;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:

	void FollowPawn();
	void Move();
	void DropCapsule();   
	void ThrowBomb();
	void UndoCommand(FString _Command);

	int32 NumShotsFired; 
	int32 MaxShots; 
	int32 MaxBombs;
	int32 NumShotsFired1;  

	
};  