// Fill out your copyright notice in the Description page of Project Settings.


#include "MotherDirector.h"


// Sets default values
AMotherDirector::AMotherDirector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMotherDirector::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMotherDirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); 

}

void AMotherDirector::ConstructShips()
{
	if(ShipBuilder)
	{
		ShipBuilder->BuildMotherShipMesh();  
		ShipBuilder->BuildMotor(); 
		ShipBuilder->BuildShield();
		ShipBuilder->BuildPropellants(); 
		ShipBuilder->BuildWeapons();
	}

}


void AMotherDirector::SetBuilder(AActor* Builder)
{
	ShipBuilder = Cast<IIBuilderMotherShip>(Builder); //se esta casteando a ShipBuilder  
}

AMotherShip* AMotherDirector::GetMotherShip()
{
	return ShipBuilder->GetMotherShip();
}
