// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IStrategyPawn.h"
#include "StrategyOffensive.generated.h"

UCLASS()
class GALAGA_USFX_LAB02_API AStrategyOffensive : public AActor, public IIStrategyPawn
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStrategyOffensive();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	class AGalaga_USFX_LAB02Pawn* Pawn;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void ExecuteStrategy() override;

};
