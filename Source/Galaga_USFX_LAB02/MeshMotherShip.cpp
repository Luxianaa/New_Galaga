// Fill out your copyright notice in the Description page of Project Settings.


#include "MeshMotherShip.h"

// Sets default values
AMeshMotherShip::AMeshMotherShip()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> mallaS(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO_2.TwinStickUFO_2'"));
	MotherMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MotherMesh"));
	MotherMesh->SetupAttachment(RootComponent);
	MotherMesh->SetStaticMesh(mallaS.Object);
	RootComponent = MotherMesh;
	//MovimientoNavesComponent = CreateDefaultSubobject<UAComponenteMovimiento>(TEXT("MovimientoNavesComponente"));
	//MovimientoComponent = CreateDefaultSubobject<UAComponenteMovimiento>(TEXT("MovimientoNavesComponente"));
	SetActorScale3D(FVector(3.0f, 3.0f, 3.0f)); 
	//Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
}

// Called when the game starts or when spawned
void AMeshMotherShip::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMeshMotherShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

