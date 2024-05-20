// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulaCrazy.h"
#include "Galaga_USFX_LAB02Pawn.h"

ACapsulaCrazy::ACapsulaCrazy()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> mallaC(TEXT("StaticMesh'/Game/TwinStick/Meshes/EnergyCapsule_2.EnergyCapsule_2'"));
	mallaCapsula->SetStaticMesh(mallaC.Object);
	mallaCapsula->SetupAttachment(RootComponent); 
	RootComponent = mallaCapsula;
	mallaCapsula->BodyInstance.SetCollisionProfileName("Capsule");
	mallaCapsula->OnComponentHit.AddDynamic(this, &ACapsulaCrazy::OnHit); 
	 
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Capsule"));
	ProjectileMovement->UpdatedComponent = mallaCapsula;
	ProjectileMovement->InitialSpeed = 3000.0f;
	ProjectileMovement->MaxSpeed = 3000.0f;
	ProjectileMovement->bRotationFollowsVelocity = true;//
	ProjectileMovement->bShouldBounce = false;//
	ProjectileMovement->ProjectileGravityScale = 1.0f; // No gravity
	InitialLifeSpan = 1.0f;
}

void ACapsulaCrazy::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	AGalaga_USFX_LAB02Pawn* Pawn = Cast<AGalaga_USFX_LAB02Pawn>(OtherActor); 
	if (Pawn)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("Capsula comida")); 

		Pawn->MoveCrazy(); 
		Pawn->SetPlayerInputEnabled(false); 
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("Sin Movimiento")); 
		Destroy();//Destruye la capsula
		return;
	}
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherComp->IsSimulatingPhysics()) 
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 20.0f, GetActorLocation()); //
	} 

}

void ACapsulaCrazy::FireCpasule()
{
	FVector NewLocation = GetActorLocation() + GetActorForwardVector() * 300.0f;
	SetActorLocation(NewLocation); 
}

void ACapsulaCrazy::FireInDirection(const FVector& ShootDirection)
{
	ProjectileMovement->Velocity = GetActorForwardVector() * ProjectileMovement->InitialSpeed; 
	//ProjectileMovement->Velocity = ShootDirection * ProjectileMovement->InitialSpeed;  
}



