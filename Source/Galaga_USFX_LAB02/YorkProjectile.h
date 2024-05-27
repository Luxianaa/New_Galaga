// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h" 
#include "YorkProjectile.generated.h"

UCLASS()
class GALAGA_USFX_LAB02_API AYorkProjectile : public AActor
{
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* YorkProjectile;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement; 
public:	
	// Sets default values for this actor's properties
	AYorkProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	class AFacadeShip* FacadeShip;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void FireInDirection(const FVector& ShootDirection);
	void Fire();
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
