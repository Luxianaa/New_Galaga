// Fill out your copyright notice in the Description page of Project Settings.


#include "FactoryShip.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaCurandera.h"
#include "NaveEnemigaBigPoppa.h"
#include "NaveEnemigaEspia.h"
#include "NaveEnemigaHacker.h"
#include "NaveEnemigaTransporte.h"
#include "NaveEnemigaUwU.h"


// Sets default values
AFactoryShip::AFactoryShip()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFactoryShip::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFactoryShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

ANaveEnemiga* AFactoryShip::CreateShips(FString tipoNave, UWorld* World, FVector SpawnLocation, FRotator ZeroRotator)
{
	NaveEnemiga = nullptr; 

	if (tipoNave == "Caza")
	{
		NaveEnemiga = World->SpawnActor<ANaveEnemigaCaza>(SpawnLocation, ZeroRotator);
	}
	else if (tipoNave == "Curandera")
	{
		NaveEnemiga = World->SpawnActor<ANaveEnemigaCurandera>(SpawnLocation, ZeroRotator);

	}
	else if (tipoNave == "BigPoppa")
	{
		NaveEnemiga = World->SpawnActor<ANaveEnemigaBigPoppa>(SpawnLocation, ZeroRotator);
	
	}
	else if (tipoNave == "Espia")
	{
		NaveEnemiga = World->SpawnActor<ANaveEnemigaEspia>(SpawnLocation, ZeroRotator);
		 
	}
	else if (tipoNave == "Hacker")
	{
		NaveEnemiga = World->SpawnActor<ANaveEnemigaHacker>(SpawnLocation, ZeroRotator);
		
	}
	else if (tipoNave == "Transporte")
	{
		NaveEnemiga = World->SpawnActor<ANaveEnemigaTransporte>(SpawnLocation, ZeroRotator);
		
	}
	else if (tipoNave == "UwU")
	{
		NaveEnemiga = World->SpawnActor<ANaveEnemigaUwU>(SpawnLocation, ZeroRotator); 
	
	}

	return NaveEnemiga; 
}


