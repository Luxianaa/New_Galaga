// Fill out your copyright notice in the Description page of Project Settings.


#include "CommadDrop.h"
#include "ShipPatrol.h"


// Sets default values
ACommadDrop::ACommadDrop()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

// Called when the game starts or when spawned
void ACommadDrop::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACommadDrop::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACommadDrop::SetReceptor(AShipPatrol* _Receptor)
{
	Receptor = _Receptor;
}

void ACommadDrop::Execute()
{
	Receptor->DropCapsule();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Activado, tirando Capsulas"));
}

void ACommadDrop::Undo()
{
	Receptor->UndoCommand("Drop");
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Esta desactivando el CommandDrop")); 
}

