// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_USFX_LAB02GameMode.h"
#include "Galaga_USFX_LAB02Pawn.h"
#include "MotherShip.h"
#include "ShieldMotherShip.h"
#include "DoomMotherShip.h"
#include "NasMotherShip.h"
#include "MotherDirector.h"
#include "FacadeShip.h" 
#include "Moon.h"
#include "Kismet/GameplayStatics.h"
#include "ShipYorke.h"
#include "Publisher.h"
#include "HendrixShip.h"


AGalaga_USFX_LAB02GameMode::AGalaga_USFX_LAB02GameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AGalaga_USFX_LAB02Pawn::StaticClass();

}

void AGalaga_USFX_LAB02GameMode::BeginPlay()
{
	Super::BeginPlay();
	//--------------------------------------------------FACADE-------------------------------------------------------------------------------//
	FVector SpawnLocation2 = FVector(320.0f, 1480.0f, 990.0f);
	FRotator SpawnRotation = FRotator(0.0f, 180.0f, 0.0f);
	FVector SpawnLocation = FVector(-2425.0f, -115.0f, 400.0f);

	ShipYorke = GetWorld()->SpawnActor<AShipYorke>(AShipYorke::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
	Moon = GetWorld()->SpawnActor<AMoon>(SpawnLocation2, SpawnRotation);  
	Publisher = GetWorld()->SpawnActor<APublisher>(APublisher::StaticClass());  
	ShipYorke->SetPublisher(Publisher); //suscrito al publisher agregar al publicador
	Publisher->ObserveMoon(Moon);//observa la luna

	FVector SpawnLocation3 = FVector(-700.0f, -115.0f, 200.0f);

	HendrixShip = GetWorld()->SpawnActor<AHendrixShip>(AHendrixShip::StaticClass(), SpawnLocation3, SpawnRotation); 

	FacadeShip = GetWorld()->SpawnActor<AFacadeShip>(AFacadeShip::StaticClass());
	
	//switch (FMath::RandRange(1, 2))
	//{
	//case 1:
		//FacadeShip->SpawnShipsLevel1();
	//	FacadeShip->SpawnCapsules(); 
	//	FacadeShip->SpawnMoon(); 

	//	break;
	//case 2:
	//FacadeShip->SpawnShipsLevel2();
	//	FacadeShip->SpawnRagerShips(); 
	//	FacadeShip->SpawnMoon();
	//	break;
	//}
//-----------------------------------------------------BUILDER----------------------------------------------------------------------------------//

	//UWorld* const World = GetWorld();
	//if (World != nullptr)//verificar si el mundo es diferente de nulo
	//{
	//	MotherDirector = GetWorld()->SpawnActor<AMotherDirector>(AMotherDirector::StaticClass()); 

	//	switch (FMath::RandRange(1, 3))
	//	{
	//	case 1:
	//		ShieldMotherShip = GetWorld()->SpawnActor<AShieldMotherShip>(AShieldMotherShip::StaticClass());//Spawning Concrete Builder
	//		MotherDirector->SetBuilder(ShieldMotherShip);//Setting Builder to Director 
	//		MotherDirector->ConstructShips();//Constructing Ships 
	//		break;

	//	case 2:
	//		NasMotherShip = GetWorld()->SpawnActor<ANasMotherShip>(ANasMotherShip::StaticClass());
	//		MotherDirector->SetBuilder(NasMotherShip);
	//		MotherDirector->ConstructShips();
	//		break;

	//	case 3:
	//		DoomMotherShip = GetWorld()->SpawnActor<ADoomMotherShip>(ADoomMotherShip::StaticClass());
	//		MotherDirector->SetBuilder(DoomMotherShip);
	//		MotherDirector->ConstructShips();

	//		break;
	//	}

	//	AMotherShip* MotherShip = MotherDirector->GetMotherShip();
	//	MotherShip->caracteristicas();
	//}
}

