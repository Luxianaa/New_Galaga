// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulaVida.h"
#include "Galaga_USFX_LAB02Pawn.h"
#include "FacadeShip.h"

ACapsulaVida::ACapsulaVida()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> mallaC(TEXT("StaticMesh'/Game/TwinStick/Meshes/HealthCapsule.HealthCapsule'"));
	mallaCapsula->SetStaticMesh(mallaC.Object);
	mallaCapsula->BodyInstance.SetCollisionProfileName("Capsule");
	mallaCapsula->OnComponentHit.AddDynamic(this, &ACapsulaVida::OnHit);
}

void ACapsulaVida::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	FacadeShip->CollideLifeCapsule(OtherActor);
	Destroy();//Destruir la capsula
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 20.0f, GetActorLocation());
	}
}
