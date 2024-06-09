// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ICommand.h"
#include "CommandTeleport.generated.h"

UCLASS()
class GALAGA_USFX_LAB02_API ACommandTeleport : public AActor, public IICommand
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACommandTeleport();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
public:
	virtual void Execute() override;
	virtual void Undo() override;

	//virtual void Redo() override;
private:
	class AGalaga_USFX_LAB02Pawn* Pawn;
};
