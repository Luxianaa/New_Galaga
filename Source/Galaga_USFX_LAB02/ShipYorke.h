// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ShipYorke.generated.h"

UCLASS()
class GALAGA_USFX_LAB02_API AShipYorke : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* ShipYorke;
	// Sets default values for this actor's properties
	AShipYorke();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void FireProjectile();
	FTimerHandle FireTimerHandle;
	float FireRate;

};
