// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "IHendrixState.h"
#include "MotherShipHendrix.generated.h"

UCLASS()
class GALAGA_USFX_LAB02_API AMotherShipHendrix : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true")) 
	UStaticMeshComponent* HendrixMesh;
	AMotherShipHendrix();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	int vida;
private:
	IIHendrixState* CrazyState;
	IIHendrixState* AgresiveState;
	IIHendrixState* HiddenState;
	IIHendrixState* State;
public:
	void Initialize();
	void MoveHendrix();
	void ShootTripleHendrix() ;
	void ChangeMeshHendrix();
	void HideHendrix();


	IIHendrixState* GetCrazyState();
	IIHendrixState* GetAgresiveState();
	IIHendrixState* GetHiddenState();
	IIHendrixState* GetState();

};
