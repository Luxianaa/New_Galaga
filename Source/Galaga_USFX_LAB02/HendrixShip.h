// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IHendrixState.h"
#include "HendrixShip.generated.h"

UCLASS()
class GALAGA_USFX_LAB02_API AHendrixShip : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true")) 
	UStaticMeshComponent* HendrixMesh; 
	AHendrixShip();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	int Vida;
public:
	void ReceiveDamageHendrix();//own of ship

	void InicializarEstados();
	IIHendrixState* CrazyState;
	IIHendrixState* AgresiveState;
	IIHendrixState* WeakState;
	IIHendrixState* State;


	void MoveHendrix(float DeltaTime);
	void DropHendrix();
	void HideHendrix();
	void SetState(IIHendrixState* _State);


	IIHendrixState* GetCrazyState();
	IIHendrixState* GetAgresiveState();
	IIHendrixState* GetWeakState();
	IIHendrixState* GetState();
};
