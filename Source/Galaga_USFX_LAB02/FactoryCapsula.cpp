// Fill out your copyright notice in the Description page of Project Settings.


#include "FactoryCapsula.h"
#include "CapsulaEnergia.h"
#include "CapsulaVida.h"
#include "CapsulaCrazy.h"

// Sets default values
AFactoryCapsula::AFactoryCapsula()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

ACapsula* AFactoryCapsula::GenerarCapsulas(FString tipoCapsula, UWorld* World, FVector SpawnLocation, FRotator SpawnRotation)
{
	FVector SpawnLocat = SpawnLocation; 
	if (tipoCapsula == "Energia")
	{
		ACapsulaEnergia* CapsulaEnergia = World->SpawnActor<ACapsulaEnergia>(SpawnLocat, SpawnRotation); 

		GEngine ->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("Capsula Energia"));
		return CapsulaEnergia; 
	}
	else if (tipoCapsula == "Vida")
	{
		ACapsulaVida* CapsulaVida = World->SpawnActor<ACapsulaVida>(SpawnLocat, SpawnRotation);

		GEngine ->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("Capsula Vida"));
		return CapsulaVida; 
	}
	else if (tipoCapsula == "Crazy")
	{
		ACapsulaCrazy* CapsulaCrazy = World->SpawnActor<ACapsulaCrazy>(SpawnLocat, SpawnRotation);

		GEngine ->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("Capsula Crazy"));
		return CapsulaCrazy; 
	}
	return nullptr;
}

// Called when the game starts or when spawned
void AFactoryCapsula::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFactoryCapsula::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

