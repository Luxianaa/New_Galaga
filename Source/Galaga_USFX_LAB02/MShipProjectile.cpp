// Fill out your copyright notice in the Description page of Project Settings.


#include "MShipProjectile.h"
#include "Galaga_USFX_LAB02Pawn.h"

// Sets default values
AMShipProjectile::AMShipProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> mallaPM(TEXT("StaticMesh'/Game/TwinStick/Meshes/ShipMotherPorjectile.ShipMotherPorjectile'"));
	meshProyectil = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));//crea el objeto mallaProyectil
	meshProyectil->SetStaticMesh(mallaPM.Object);  //asigna la malla al objeto mallaProyectil
	meshProyectil->SetupAttachment(RootComponent);//asigna el objeto mallaProyectil al componente raiz
	RootComponent = meshProyectil; //asigna el objeto mallaProyectil al componente raiz
	meshProyectil->BodyInstance.SetCollisionProfileName("Projectile");
	meshProyectil->OnComponentHit.AddDynamic(this, &AMShipProjectile::OnHit);
	SetActorScale3D(FVector(1.5f, 1.5f, 1.5f));

	//ProjectileMesh->OnComponentHit.AddDynamic(this, &AEnemyProjectile::OnHit);  // set up a notification for when this component hits something
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->UpdatedComponent = meshProyectil;
	ProjectileMovement->InitialSpeed = 3000.0f;
	ProjectileMovement->MaxSpeed = 3000.0f;
	ProjectileMovement->bRotationFollowsVelocity = true;//
	ProjectileMovement->bShouldBounce = false;//
	ProjectileMovement->ProjectileGravityScale = 0.50f; // No gravity
	InitialLifeSpan = 3.0f;
}

// Called when the game starts or when spawned
void AMShipProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMShipProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMShipProjectile::FireInDirections(const FVector& ShootDirection)
{
	ProjectileMovement->Velocity = GetActorForwardVector() * ProjectileMovement->InitialSpeed;
}

void AMShipProjectile::Fires()
{
	FVector NewLocation = GetActorLocation() + GetActorForwardVector() * 300.0f;
	SetActorLocation(NewLocation);
}

void AMShipProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	AGalaga_USFX_LAB02Pawn* Pawn = Cast<AGalaga_USFX_LAB02Pawn>(OtherActor);
	if (Pawn)
	{


		// Mostrar un mensaje informando al jugador sobre la pérdida de vida
		FString Message = FString::Printf(TEXT(" Destruido "));
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, Message);
		//PawnScore += ScorePorEnemigo;


		// Llamar a la función destruir de la nave enemiga
		Pawn->Destroy();  
	}
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 20.0f, GetActorLocation());
	}
	 
	Destroy();
}

