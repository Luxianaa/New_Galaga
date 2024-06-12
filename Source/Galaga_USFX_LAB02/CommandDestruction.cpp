// Fill out your copyright notice in the Description page of Project Settings.


#include "CommandDestruction.h"
#include "ShipPatrol.h"

// Sets default values
ACommandDestruction::ACommandDestruction()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACommandDestruction::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACommandDestruction::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//void ACommandDestruction::SetReceptor(AShipPatrol* _Receptor)
//{
//	Receptor = _Receptor;
//}

//void ACommandDestruction::Execute()
//{
//	Receptor->Destruir();
//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Esta activando el CommandDestruction"));
//}
//
//void ACommandDestruction::Undo()
//{
//	Receptor->UndoCommand("Misiles");
//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Esta desactivando el CommandDestruction"));
//}

