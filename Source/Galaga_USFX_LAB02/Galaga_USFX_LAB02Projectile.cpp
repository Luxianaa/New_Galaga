// Copyright Epic Games, Inc. All Rights Reserve

#include "Galaga_USFX_LAB02Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Engine/StaticMesh.h"
#include "NaveEnemiga.h"
#include "Shield.h"
#include "MeshMotherShip.h"
#include "ShieldMotherShip.h"
#include "Kismet/GameplayStatics.h"
#include "FacadeScore.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

AGalaga_USFX_LAB02Projectile::AGalaga_USFX_LAB02Projectile() 
{
	// Static reference to the mesh to use for the projectile
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMeshAsset(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickProjectile.TwinStickProjectile'"));

	// Create mesh component for the projectile sphere
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh0"));
	ProjectileMesh->SetStaticMesh(ProjectileMeshAsset.Object);
	ProjectileMesh->SetupAttachment(RootComponent);
	ProjectileMesh->BodyInstance.SetCollisionProfileName("Projectile");
	ProjectileMesh->OnComponentHit.AddDynamic(this, &AGalaga_USFX_LAB02Projectile::OnHit);		// set up a notification for when this component hits something
	RootComponent = ProjectileMesh;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement0"));
	ProjectileMovement->UpdatedComponent = ProjectileMesh;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = false;
	ProjectileMovement->ProjectileGravityScale = 0.f; // No gravity


	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleSys(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));
	ParticleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle"));
	ParticleSystemComponent->SetTemplate(ParticleSys.Object); //esto es para asignar la plantilla de particulas al componente
	ParticleSystemComponent->SetupAttachment(RootComponent);
	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;
}

void AGalaga_USFX_LAB02Projectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	FacadeScore->Colisionar(OtherActor);  //Facade
	FacadeScore->ColisionarEscudo(OtherActor);//Facade 
	
	// Only add impulse and destroy projectile if we hit a physics
	if(ParticleSystemComponent)
	{
		ParticleSystemComponent->Activate();
		//ParticleSystemComponent->SetWorldLocation(GetActorLocation());
		//ParticleSystemComponent->OnSystemFinished.AddDynamic(this, &AGalaga_USFX_LAB02Projectile::OnParticleSystemFinished);
	 }
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 20.0f, GetActorLocation());
	}

	Destroy();//PARA QUE DESAPAREZCA EL PROYECTIL CUANDO CHOCA CON ALGO
}


//ANaveEnemiga* NaveEnemiga = Cast<ANaveEnemiga>(OtherActor);
	//if (NaveEnemiga)
	//{
	//	contadorPawn++;

	//	

	//	// Mostrar un mensaje en pantalla informando al jugador sobre la destrucción de la nave enemiga
	//	FString Message = FString::Printf(TEXT("¡Nave enemiga destruida! Puntuacion:%d"), contadorPawn); 
	//	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, Message);

	//	// Llamar a la función destruir de la nave enemiga
	//	NaveEnemiga->Destroy();
	//}
	//AShield* Shield = Cast<AShield>(OtherActor);
	//if (Shield)
	//{
	//	contadorPawn += 2000;
	//	// Mostrar un mensaje en pantalla informando al jugador sobre la destrucción de la nave enemiga
	//	FString Message = FString::Printf(TEXT("¡Nave enemiga destruida! Puntuacion:%d"), contadorPawn);
	//	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, Message);

	//	// Llamar a la función destruir de la nave enemiga
	//	Shield->Destroy(); 
	//}