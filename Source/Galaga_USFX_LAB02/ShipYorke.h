// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ISubscriber.h"
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
	class UAComponenteMovimiento* ComponenteMovimiento;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void FireProjectile();
	FTimerHandle FireTimerHandle;
	float FireRate;
public: 
	//vida de la nave Yorke

	int Vida;
	int VidaMaxima;

////gestionar observadores
//	void Subscribe(IISubscriber* subscriber);
//	void Unsubscribe(IISubscriber* subscriber);
//	void Notify();
////Metodo Recibir daño
//	void GetDamage(int Damage);
//
//private: 
//	TArray<IISubscriber*> Subscribers;


};
