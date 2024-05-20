// Fill out your copyright notice in the Description page of Project Settings.


#include "Propellants.h"

// Sets default values
APropellants::APropellants()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> mallaS(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Bush_2.SM_Bush_2'")); 
	MeshPrope = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshPrope"));
	MeshPrope->SetupAttachment(RootComponent); 
	MeshPrope->SetStaticMesh(mallaS.Object); 
	//MovimientoComponent = CreateDefaultSubobject<UAComponenteMovimiento>(TEXT("MovimientoNavesComponente"));
	//MovimientoNavesComponent = CreateDefaultSubobject<UAComponenteMovimiento>(TEXT("MovimientoNavesComponente"));
	RootComponent = MeshPrope; 

}

// Called when the game starts or when spawned
void APropellants::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APropellants::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

