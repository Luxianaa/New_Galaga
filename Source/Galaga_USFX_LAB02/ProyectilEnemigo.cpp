// Fill out your copyright notice in the Description page of Project Settings.


#include "ProyectilEnemigo.h"
#include "Galaga_USFX_LAB02Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "FacadeShip.h"
#include "ShipYorke.h"


// Sets default values
AProyectilEnemigo::AProyectilEnemigo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> mallaSo(TEXT("StaticMesh'/Game/TwinStick/Meshes/ProyectilEnemigo.ProyectilEnemigo'"));
	mallaProyectil = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));//crea el objeto mallaProyectil
	mallaProyectil->SetStaticMesh(mallaSo.Object);  //asigna la malla al objeto mallaProyectil
	mallaProyectil->SetupAttachment(RootComponent);//asigna el objeto mallaProyectil al componente raiz
	RootComponent = mallaProyectil; //asigna el objeto mallaProyectil al componente raiz
	mallaProyectil->BodyInstance.SetCollisionProfileName("Projectile");
	mallaProyectil->OnComponentHit.AddDynamic(this, &AProyectilEnemigo::OnHit);

	

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->UpdatedComponent = mallaProyectil;
	ProjectileMovement->InitialSpeed = 3000.0f;
	ProjectileMovement->MaxSpeed = 3000.0f;
	ProjectileMovement->bRotationFollowsVelocity = true;//
	ProjectileMovement->bShouldBounce = false;//
	ProjectileMovement->ProjectileGravityScale = 0.0f; // No gravity


	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleSys(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Sparks.P_Sparks'"));
	ParticleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle"));
	ParticleSystemComponent->SetTemplate(ParticleSys.Object); //esto es para asignar la plantilla de particulas al componente
	ParticleSystemComponent->SetupAttachment(RootComponent); 


	// Set default damage
	Damage = 10.0f;
	InitialLifeSpan = 3.0f;
}

void AProyectilEnemigo::FireInDirection(const FVector& ShootDirection)
{
	ProjectileMovement->Velocity = GetActorForwardVector() * ProjectileMovement->InitialSpeed;
}

void AProyectilEnemigo::Fire()
{
	FVector NewLocation = GetActorLocation() + GetActorForwardVector() * 300.0f ;
	SetActorLocation(NewLocation);

}

void AProyectilEnemigo::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{ 
	FacadeShip->CollideEnemyProjectile(OtherActor);
	if (ParticleSystemComponent) 
	{ 
		ParticleSystemComponent->Activate(); 
	}
	 
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 20.0f, GetActorLocation());
	}
	Destroy();
	AShipYorke* ShipYorke = Cast<AShipYorke>(OtherActor);
	if (ShipYorke)
	{
		ShipYorke->Destroy();
	}
}

// Called when the game starts or when spawned
void AProyectilEnemigo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProyectilEnemigo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

