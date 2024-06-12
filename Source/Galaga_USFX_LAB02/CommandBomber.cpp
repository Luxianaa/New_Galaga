// Fill out your copyright notice in the Description page of Project Settings.


#include "CommandBomber.h"
#include "ShipPatrol.h"

// Sets default values
ACommandBomber::ACommandBomber()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACommandBomber::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACommandBomber::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACommandBomber::SetReceptor(AShipPatrol* _Receptor)
{
		Receptor = _Receptor;
}

void ACommandBomber::Execute()
{
	Receptor->ThrowBomb();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("Activado, Bombardear")); 
}

void ACommandBomber::Undo()
{
	Receptor->UndoCommand("Bomber");
	/*GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Esta desactivando el CommandBomber")); */
}

