// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "JuniorShip.generated.h"

UCLASS()
class GALAGA_USFX_LAB02_API AJuniorShip : public ACharacter
{
	GENERATED_BODY() 

public:
	// Sets default values for this character's properties
	AJuniorShip();  

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override; 

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override; 

};
