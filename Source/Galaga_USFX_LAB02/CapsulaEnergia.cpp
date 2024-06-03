// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulaEnergia.h"
#include "Galaga_USFX_LAB02Pawn.h"
#include "FacadeShip.h"

ACapsulaEnergia::ACapsulaEnergia()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> mallaC(TEXT("StaticMesh'/Game/TwinStick/Meshes/EnergyCapsule.EnergyCapsule'"));
	mallaCapsula->SetStaticMesh(mallaC.Object);
	mallaCapsula->BodyInstance.SetCollisionProfileName("Capsule"); //StaticMesh'/Game/TwinStick/Meshes/EnergyCapsule.EnergyCapsule'
	mallaCapsula->OnComponentHit.AddDynamic(this, &ACapsulaEnergia::OnHit);
}

void ACapsulaEnergia::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	FacadeShip->CollideEnergyCapsule(OtherActor) ; 
	Destroy();//Destruir la capsula
}

void ACapsulaEnergia::BeginPlay()
{
	Super::BeginPlay();
}

void ACapsulaEnergia::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACapsulaEnergia::Drop()
{
	FVector NewLocation = GetActorLocation() + GetActorForwardVector() *300;
	SetActorLocation(NewLocation);
}
