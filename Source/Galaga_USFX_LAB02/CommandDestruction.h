// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ICommand.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CommandDestruction.generated.h"

UCLASS()
class GALAGA_USFX_LAB02_API ACommandDestruction : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACommandDestruction();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	class AShipPatrol* Receptor;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
