// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AComponenteMovimiento.h"	
#include "Shield.generated.h"

UCLASS()
class GALAGA_USFX_LAB02_API AShield : public AActor
{
	GENERATED_BODY()
	
public:	

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* ShieldMesh; // Malla de la nave enemiga	
	UAComponenteMovimiento* MovimientoComponent;

public:

	AShield();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetVisibility();
	FTimerHandle TiempoVisibilidad2;
	
	
};
