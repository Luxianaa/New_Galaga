// Fill out your copyright notice in the Description page of Project Settings.


#include "Moon.h"
#include "Galaga_USFX_LAB02Pawn.h"

// Sets default values
AMoon::AMoon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Mallamoon(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickProjectile_2.TwinStickProjectile_2'"));
	mallamoon = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MoonMesh"));//crea el objeto mallaProyectil
	mallamoon->SetStaticMesh(Mallamoon.Object);  //asigna la malla al objeto mallaProyectil
	mallamoon->SetupAttachment(RootComponent);//asigna el objeto mallaProyectil al componente raiz
	RootComponent = mallamoon; 
	SetActorScale3D(FVector(10.0f, 10.0f, 10.0f));
}

// Called when the game starts or when spawned
void AMoon::BeginPlay()
{
	Super::BeginPlay();	
	
}

// Called every frame
void AMoon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



