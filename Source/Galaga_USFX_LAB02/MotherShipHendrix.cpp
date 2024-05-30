// Fill out your copyright notice in the Description page of Project Settings.


#include "MotherShipHendrix.h"

// Sets default values
AMotherShipHendrix::AMotherShipHendrix()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshHendrix(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO_Nodriza.TwinStickUFO_Nodriza'"));
	HendrixMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshPrope"));
	HendrixMesh->SetupAttachment(RootComponent);
	HendrixMesh->SetStaticMesh(MeshHendrix.Object); 
	RootComponent = HendrixMesh; 
	SetActorScale3D(FVector(5.0f, 5.0f, 5.0f));
	vida = 5;
}

// Called when the game starts or when spawned
void AMotherShipHendrix::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMotherShipHendrix::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMotherShipHendrix::Initialize()
{

}

void AMotherShipHendrix::MoveHendrix()
{
}

void AMotherShipHendrix::ShootTripleHendrix()
{
}

void AMotherShipHendrix::ChangeMeshHendrix()
{
}

void AMotherShipHendrix::HideHendrix()
{
}

IIHendrixState* AMotherShipHendrix::GetCrazyState()
{
	return CrazyState;
}

IIHendrixState* AMotherShipHendrix::GetAgresiveState()
{
	return AgresiveState;
}

IIHendrixState* AMotherShipHendrix::GetHiddenState()
{
	return HiddenState;
}

IIHendrixState* AMotherShipHendrix::GetState()
{
	return State;
}

