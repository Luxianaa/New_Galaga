// Fill out your copyright notice in the Description page of Project Settings.


#include "FacadeShip.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaBigPoppa.h"
#include "NaveEnemigaBigPoppaLv1.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaCazaLv1.h"
#include "NaveEnemigaCurandera.h"
#include "NaveEnemigaEspia.h"
#include "NaveEnemigaEspiaLv1.h"
#include "NaveEnemigaHacker.h"
#include "NaveEnemigaHackerLv1.h"
#include "NaveEnemigaTransporte.h"
#include "NaveEnemigaTransporteLv1.h"
#include "NaveEnemigaUwU.h"
#include "IAbsFactory.h"
#include "FactoryShipLv1.h"
#include "FactoryShip.h"
#include "FactoryCapsula.h"
#include "Kismet/GameplayStatics.h"
#include "ShipRager.h"
#include "Motor.h"
#include "CapsulaCrazy.h"


// Sets default values
AFacadeShip::AFacadeShip()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AFacadeShip::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void AFacadeShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFacadeShip::SpawnShipsLevel1()
{
	IIAbsFactory* factory = NewObject<AFactoryShip>(); //Crea una nueva fabrica de naves 

	UWorld* const World = GetWorld();
	if (World != nullptr)//verificar si el mundo es diferente de nulo
	{
		FVector ubicacionInicialNaves = FVector(1000.0f, -1600.0f, 200.0f);
		FVector ubicacionInicialNaves2 = FVector(1000.0f, -2000.0f, 200.0f);
		FRotator rotacionNave = FRotator(0.0f, 180.0f, 0.0f);
		FVector ubicacionActual = ubicacionInicialNaves;
		for (int i = 0; i < 2; i++)
		{
			ubicacionActual.Y = ubicacionInicialNaves.Y + 1000.0f ;
			ubicacionActual = FVector(ubicacionInicialNaves.X, ubicacionInicialNaves.Y + 300.0f * i , ubicacionInicialNaves.Z);
			factory->CreateShips("Caza", World, ubicacionActual, rotacionNave);
		}
		for (int i = 0; i < 6; i++)
		{
			ubicacionActual = FVector(ubicacionInicialNaves.X, ubicacionInicialNaves.Y + 300.0f * i, ubicacionInicialNaves.Z);
			factory->CreateShips("Transporte", World, ubicacionActual, rotacionNave);
		}
		ubicacionActual.X = ubicacionInicialNaves.X - 250.0f;

		for (int j = 0; j < 10; j++)
		{
			ubicacionActual.Y = ubicacionInicialNaves.Y + 300.0f * j;
			factory->CreateShips("UwU", World, ubicacionActual, rotacionNave);
		}

		ubicacionActual.X = ubicacionInicialNaves.X - 500.0f;
		for (int i = 0; i < 5; i++)
		{
			ubicacionActual.Y = ubicacionInicialNaves.Y + 300.0f * i;
			factory->CreateShips("Hacker", World, ubicacionActual, rotacionNave);
		}
		ubicacionActual.X = ubicacionInicialNaves.X - 750.0f;

		for (int j = 0; j < 4; j++)
		{
			ubicacionActual.Y = ubicacionInicialNaves.Y + 300.0f * j;
			factory->CreateShips("Espia", World, ubicacionActual, rotacionNave);
		}
	}
}

void AFacadeShip::SpawnShipsLevel2()
{
	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		IIAbsFactory* factory = NewObject<AFactoryShipLv1>(); //Crea una instancia fabrica de naves 

		FVector ubicacionInicialNaves = FVector(1000.0f, -1600.0f, 200.0f);
		FVector ubicacionInicialNaves2 = FVector(1000.0f, -2000.0f, 200.0f);
		FRotator rotacionNave = FRotator(0.0f, 180.0f, 0.0f);
		FVector ubicacionActual = ubicacionInicialNaves;

		ubicacionActual.X = ubicacionInicialNaves2.X - 250.0f;
		for (int i = 0; i < 1; i++)
		{
			ubicacionActual.Y = ubicacionInicialNaves2.Y + 300.0f * i;
			factory->CreateShips("CazaLv1", World, ubicacionActual, rotacionNave);
		}
		ubicacionActual.X = ubicacionInicialNaves2.X - 500.0f;
		for (int j = 0; j < 6; j++)
		{
			ubicacionActual.Y = ubicacionInicialNaves2.Y + 300.0f * j;
			factory->CreateShips("HackerLv1", World, ubicacionActual, rotacionNave);
		}
		ubicacionActual.X = ubicacionInicialNaves2.X - 750.0f;
		for (int i = 0; i < 3; i++)
		{
			ubicacionActual.Y = ubicacionInicialNaves2.Y + 300.0f * i;
			factory->CreateShips("EspiaLv1", World, ubicacionActual, rotacionNave);
		}
		ubicacionActual.X = ubicacionInicialNaves2.X - 1000.0f;
		for (int j = 0; j < 4; j++)
		{
			ubicacionActual.Y = ubicacionInicialNaves2.Y + 300.0f * j;
			factory->CreateShips("BigPoppaLv1", World, ubicacionActual, rotacionNave);
		}
		ubicacionActual.X = ubicacionInicialNaves2.X - 1250.0f;
		for (int i = 0; i < 5; i++)
		{
			ubicacionActual.Y = ubicacionInicialNaves2.Y + 300.0f * i;
			factory->CreateShips("TransporteLv1", World, ubicacionActual, rotacionNave);
		}
	}
}

void AFacadeShip::SpawnCapsules()
{
	FVector SpawnLocation = FVector(FMath::RandRange(-1000.0f, 120.0f), FMath::RandRange(-1000.0f, 120.0f), 200.0f);
	FVector SpawnLocation2 = FVector(FMath::RandRange(-1000.0f, 120.0f), FMath::RandRange(-1000.0f, 120.0f), 200.0f);
	FVector SpawnLocation3 = FVector(FMath::RandRange(-1000.0f, 120.0f), FMath::RandRange(-1000.0f, 120.0f), 200.0f);
	FRotator SpawnRotation = FRotator(0.0f, 0.0f, .0f);
	// Genera cápsulas

	if (FMath::RandBool())
	{
		AFactoryCapsula::GenerarCapsulas("Energia", GetWorld(), SpawnLocation, SpawnRotation);
	}
	else if (FMath::RandBool()) 
	{
		AFactoryCapsula::GenerarCapsulas("Crazy", GetWorld(), SpawnLocation3, SpawnRotation); 
	}
	else
	{
		AFactoryCapsula::GenerarCapsulas("Vida", GetWorld(), SpawnLocation2, SpawnRotation); 
	}	

	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &AFacadeShip::SpawnCapsules, 3.0f, true);
}

//-------------------------------------------------------------------------------------------------------------------------------------//

void AFacadeShip::SpawnRagerShips()
{
	FVector SpawnLocation = FVector(-700.0f, -3400.0f, 400.0f);
	FRotator SpawnRotation = FRotator(0.0f, 180.0f, 0.0f);
	ShipRager = GetWorld()->SpawnActor<AShipRager>(SpawnLocation, SpawnRotation);
}


