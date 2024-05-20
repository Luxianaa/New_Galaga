// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulaEnergia.h"
#include "Galaga_USFX_LAB02Pawn.h"

ACapsulaEnergia::ACapsulaEnergia()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> mallaC(TEXT("StaticMesh'/Game/TwinStick/Meshes/EnergyCapsule.EnergyCapsule'"));
	mallaCapsula->SetStaticMesh(mallaC.Object);
	mallaCapsula->BodyInstance.SetCollisionProfileName("Capsule"); //StaticMesh'/Game/TwinStick/Meshes/EnergyCapsule.EnergyCapsule'
	mallaCapsula->OnComponentHit.AddDynamic(this, &ACapsulaEnergia::OnHit);  
}

void ACapsulaEnergia::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	AGalaga_USFX_LAB02Pawn* Pawn = Cast<AGalaga_USFX_LAB02Pawn>(OtherActor);
	if (Pawn)
	{
		Pawn->Energia();
		FString Message = FString::Printf(TEXT("Energia consumida %d "));
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, Message);

		Destroy();//Destruir la capsula
	}
}

void ACapsulaEnergia::BeginPlay()
{
	Super::BeginPlay();	
}

void ACapsulaEnergia::Tick(float DeltaTime)
{		
	Super::Tick(DeltaTime);	
}
