// Fill out your copyright notice in the Description page of Project Settings.


#include "Misil.h"
#include "FacadeShip.h"

// Sets default values
AMisil::AMisil()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> meshmisil(TEXT("StaticMesh'/Game/TwinStick/Meshes/EnergyCapsule_3.EnergyCapsule_3'"));
	Misil = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Misilhit"));
	Misil->SetStaticMesh(meshmisil.Object);
	Misil->SetupAttachment(RootComponent);
	RootComponent = Misil;
	Misil->BodyInstance.SetCollisionProfileName("Misil"); 
	Misil->OnComponentHit.AddDynamic(this, &AMisil::OnHit); 
	FRotator Rotation = FRotator(0.0f, 90.0f, 0.0f);

	MisilMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	MisilMovement->UpdatedComponent = Misil;
	MisilMovement->InitialSpeed = 3000.0f;
	MisilMovement->MaxSpeed = 3000.0f;
	MisilMovement->bRotationFollowsVelocity = true;//
	MisilMovement->bShouldBounce = false;//
	MisilMovement->ProjectileGravityScale = 0.0f; // No gravity
}

// Called when the game starts or when spawned
void AMisil::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMisil::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMisil::FireInDirection(const FVector& ShootDirection)
{
	MisilMovement->Velocity = GetActorForwardVector() * MisilMovement->InitialSpeed;
	//MisilMovement->AddImpulseAtLocation(GetVelocity() * 20.0f, GetActorLocation()); 
}

void AMisil::Fire()
{
	FVector NewLocation = GetActorLocation() + GetActorForwardVector() * 300.0f; 
	SetActorLocation(NewLocation); 
}

void AMisil::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//FacadeShip->CollideProjectile(OtherActor); 
	//FacadeShip->CollideAliens(OtherActor);
	//if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
	//{
	//	OtherComp->AddImpulseAtLocation(GetVelocity() * 20.0f, GetActorLocation());
	//}
	//Destroy();
}

