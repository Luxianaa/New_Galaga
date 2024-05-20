// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulaVida.h"
#include "Galaga_USFX_LAB02Pawn.h"

ACapsulaVida::ACapsulaVida()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> mallaC(TEXT("StaticMesh'/Game/TwinStick/Meshes/HealthCapsule.HealthCapsule'"));
	mallaCapsula->SetStaticMesh(mallaC.Object);	
	mallaCapsula->BodyInstance.SetCollisionProfileName("Capsule");
	mallaCapsula->OnComponentHit.AddDynamic(this, &ACapsulaVida::OnHit);
}

void ACapsulaVida::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	AGalaga_USFX_LAB02Pawn* Pawn = Cast<AGalaga_USFX_LAB02Pawn>(OtherActor); 
	if (Pawn)
	{
		Pawn->AumentarVida(); 
		FString Message = FString::Printf(TEXT("Vidas restantes: %d "), Pawn->GetVidasRestantes()); 
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, Message);
	
		Destroy();//Destruir la capsula
	}
}
