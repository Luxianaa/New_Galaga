// Fill out your copyright notice in the Description page of Project Settings.

#include "ShieldMotherShip.h"
#include "MotherShip.h"	
#include "Motor.h"
#include "Propellants.h"
#include "Shield.h"
#include "Weapons.h"
#include "MeshMotherShip.h"

// Sets default values
AShieldMotherShip::AShieldMotherShip()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true; 



}

// Called when the game starts or when spawned
void AShieldMotherShip::BeginPlay()
{
	Super::BeginPlay(); 

	MotherShip = GetWorld()->SpawnActor<AMotherShip>(AMotherShip::StaticClass());  // Spawn the mother ship
	MotherShip -> AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform); // Attach the mother ship to the shield mother ship
}

// Called every frame
void AShieldMotherShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AShieldMotherShip::BuildMotherShipMesh()
{
	FVector Location = FVector(0, 0, 300);
	FRotator Rotation = FRotator(0.0f, 180.0f, 0.0f);
	Mesh = GetWorld()->SpawnActor<AMeshMotherShip>(AMeshMotherShip::StaticClass(), Location, Rotation); 
	MotherShip->SetMotherShipMesh(Mesh,"Shield MotherShip");
}

void AShieldMotherShip::BuildMotor()
{
	FVector Location = FVector(200, 0, 300);
	FRotator Rotation = FRotator(-90.0f, 0.0f, 0.0f);
	Motor = GetWorld()->SpawnActor<AMotor>(AMotor::StaticClass(), Location, Rotation); 
	MotherShip->SetMotor(Motor, "Motor Viejo");
}

void AShieldMotherShip::BuildShield()
{
	FVector Location = FVector(-100, -200, 90);
	FRotator Rotation = FRotator(0.0f, 90.0f, 0.0f); 
	Shield = GetWorld()->SpawnActor<AShield>(AShield::StaticClass(), Location, Rotation);
	MotherShip->SetShield(Shield, "Escudo 100%");
} 

void AShieldMotherShip::BuildPropellants()
{
	FVector Location = FVector(300,100 ,300);
	FVector Location2 = FVector(300,-100, 200); 
	FRotator Rotation = FRotator(-90.0f, 0.0f, 40.0f);
	Propellants = GetWorld()->SpawnActor<APropellants>(APropellants::StaticClass(), Location, Rotation);
	Propellants = GetWorld()->SpawnActor<APropellants>(APropellants::StaticClass(), Location2, Rotation);
	MotherShip->SetPropellants(Propellants,"2 Propulsores");
}

void AShieldMotherShip::BuildWeapons()
{
	FVector Location = FVector(0, 200, 300);
	FRotator Rotation = FRotator(0.0f, 180.0f, 0.0f);
	FVector Location2 = FVector(0, -200, 300);
	Weapons = GetWorld()->SpawnActor<AWeapons>(AWeapons::StaticClass(), Location, Rotation);
	Weapons = GetWorld()->SpawnActor<AWeapons>(AWeapons::StaticClass(), Location2, Rotation);
	MotherShip->SetWeapons(Weapons, "Dos Armas");
}

AMotherShip* AShieldMotherShip::GetMotherShip()
{
	return MotherShip;  
}






