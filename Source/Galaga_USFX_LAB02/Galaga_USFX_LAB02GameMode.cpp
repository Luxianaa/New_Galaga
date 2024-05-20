// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_USFX_LAB02GameMode.h"
#include "Galaga_USFX_LAB02Pawn.h"
#include "MotherShip.h"
#include "ShieldMotherShip.h"
#include "DoomMotherShip.h"
#include "NasMotherShip.h"
#include "MotherDirector.h"
#include "FacadeShip.h" 

AGalaga_USFX_LAB02GameMode::AGalaga_USFX_LAB02GameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AGalaga_USFX_LAB02Pawn::StaticClass();

}

void AGalaga_USFX_LAB02GameMode::BeginPlay()
{
	Super::BeginPlay();
	//--------------------------------------------------FACADE-------------------------------------------------------------------------------//

	FacadeShip = GetWorld()->SpawnActor<AFacadeShip>(AFacadeShip::StaticClass());
	
	switch (FMath::RandRange(1, 2))
	{
	case 1:
		FacadeShip->SpawnShipsLevel1();
		FacadeShip->SpawnCapsules();

		break;
	case 2:
		FacadeShip->SpawnShipsLevel2();
		FacadeShip->SpawnRagerShips(); 
		break;
	}
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

