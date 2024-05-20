// Fill out your copyright notice in the Description page of Project Settings.


#include "Moon.h"

// Sets default values
AMoon::AMoon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Mallamoon(TEXT("StaticMesh'/Game/TwinStick/Meshes/ProyectilEnemigo.ProyectilEnemigo'"));
	mallamoon = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));//crea el objeto mallaProyectil
	mallamoon->SetStaticMesh(Mallamoon.Object);  //asigna la malla al objeto mallaProyectil
	mallamoon->SetupAttachment(RootComponent);//asigna el objeto mallaProyectil al componente raiz
	RootComponent = mallamoon; 
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

