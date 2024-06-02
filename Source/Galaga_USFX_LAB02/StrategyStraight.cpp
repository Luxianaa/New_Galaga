// Fill out your copyright notice in the Description page of Project Settings.


#include "StrategyStraight.h"
#include "NaveEnemiga.h"
#include "ShipYorke.h"
#include "YorkProjectile.h"
#include "NavePruebas.h"

// Sets default values
AStrategyStraight::AStrategyStraight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Radio = 1500.0f;
	Angulo = 0.0f;
	Speed = 2.0f;
}

// Called when the game starts or when spawned
void AStrategyStraight::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStrategyStraight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AStrategyStraight::Move(ANavePruebas* Nave, float DeltaTime)
{
	FVector NewPosition = Nave->GetActorLocation();  
	NewPosition.X -= DeltaTime * Speed;  
	Nave->SetActorLocation(NewPosition);  
}






