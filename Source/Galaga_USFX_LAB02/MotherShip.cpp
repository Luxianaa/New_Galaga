// Fill out your copyright notice in the Description page of Project Settings.


#include "MotherShip.h"
#include "Motor.h"
#include "Shield.h"
#include "Propellants.h"
#include "Weapons.h"




// Sets default values
AMotherShip::AMotherShip()
{
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMotherShip::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMotherShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMotherShip::SetMotor(AMotor* motor, FString motors)
{
	Motor = motor;//AActor 
	Motors = motors;//String
}

void AMotherShip::SetShield(AShield* shield, FString escudo)
{
	Shield = shield;
	Escudo = escudo;
}

void AMotherShip::SetPropellants(APropellants* propellants, FString prope)
{
	Propellants = propellants;
	Prope = prope;
}

void AMotherShip::SetWeapons(AWeapons* weapons, FString weapon)
{
	Weapons = weapons;
	Weapon = weapon;
}

void AMotherShip::SetMotherShipMesh(AMeshMotherShip* mesh, FString malla)
{
	Mesh = mesh;
	Malla = malla;
}

void AMotherShip::caracteristicas()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,	FString::Printf(TEXT("%s"),*Malla));
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,	FString::Printf(TEXT("%s"),*Escudo));
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,	FString::Printf(TEXT("%s"),*Prope));
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,	FString::Printf(TEXT("%s"),*Weapon));
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,	FString::Printf(TEXT("%s"),*Motors));

}









