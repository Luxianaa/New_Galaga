// Fill out your copyright notice in the Description page of Project Settings.


#include "CommandTeleport.h"
#include "ShipPatrol.h"


// Sets default values
ACommandTeleport::ACommandTeleport()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACommandTeleport::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void ACommandTeleport::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACommandTeleport::SetReceptor(AShipPatrol* _Receptor)
{
	Receptor = _Receptor;
}

void ACommandTeleport::Execute()
{
	Receptor->FollowPawn();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, TEXT("Activado, siguiendo Pawn"));
}

void ACommandTeleport::Undo()
{
	Receptor->UndoCommand("FollowPawn");
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Esta desactivando el CommandTeleport")); 
} 



