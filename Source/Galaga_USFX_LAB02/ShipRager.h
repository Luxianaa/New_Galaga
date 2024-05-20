// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ShipRager.generated.h"

UCLASS()
class GALAGA_USFX_LAB02_API AShipRager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AShipRager();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* RageMesh; // Malla de la nave enemiga	 
	UPROPERTY(VisibleAnywhere, Category = "fACADE") 
	class AFacadeShip* FacadeShip; // Referencia a la fachada de la nave enemiga

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Lógica interna para el movimiento y disparo de la nave
	void Move();

	// Lógica interna para despawnear la nave
	void Despawn();
	// Variables de control
	bool bIsActive;
	FVector InitialLocation;
	FVector FinalLocation; // Nueva variable para el punto final del movimiento
	bool bReachedMiddle; // Nueva bandera para indicar si la nave ha alcanzado el punto medio
	float TimeAlive;
	float MovementSpeed;
	float TimeAtMiddle; // Nu
	FTimerHandle MovementTimerHandle;

	void Shoot();

	float FireRate;
	FTimerHandle FireTimerHandle;
	FTimerHandle MoveTimerHandle;
};
