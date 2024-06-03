	// Fill out your copyright notice in the Description page of Project Settings.


#include "NavePruebas.h"
#include "IStrategy.h"
#include "StrategyStraight.h"
// Sets default values
ANavePruebas::ANavePruebas()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshPrueba(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Chair_2.SM_Chair_2'"));
	NaveMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("NavePrueba"));
	NaveMesh->SetupAttachment(RootComponent);
	NaveMesh->SetStaticMesh(MeshPrueba.Object);
	RootComponent = NaveMesh; 
	NaveMesh->SetRelativeScale3D(FVector(1.5f, 1.5f, 1.5f));
}

// Called when the game starts or when spawned
void ANavePruebas::BeginPlay()
{
	Super::BeginPlay();   
}

// Called every frame
void ANavePruebas::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); 
	//CrearMovimiento(DeltaTime); 
	//ActivarEstrategia(); 
}
//void ANavePruebas::SetStrategy(IIStrategy* NewStrategy)
//{
//	Strategy = NewStrategy; 
//}
//
//void ANavePruebas::ActivarEstrategia()
//{
//
//	if (Strategy)
//	{
//		Strategy->ExecuteStrategy(this); 
//
//		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Estrategia Activada"));
//	}
//	
//}





