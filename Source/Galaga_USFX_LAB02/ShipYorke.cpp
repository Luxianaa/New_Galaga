// Fill out your copyright notice in the Description page of Project Settings.


#include "ShipYorke.h"
#include "AComponenteMovimiento.h"
#include "YorkProjectile.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"
#include "Publisher.h"
//#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AShipYorke::AShipYorke()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> meshYorke(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO_4.TwinStickUFO_4'"));
	ShipYorke = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshPrope"));
	ShipYorke->SetupAttachment(RootComponent);
	ShipYorke->SetStaticMesh(meshYorke.Object);
	RootComponent = ShipYorke;
	//SetActorScale3D(FVector(1.0f, 1.0f, 1.0f));
	ComponenteMovimiento = CreateDefaultSubobject<UAComponenteMovimiento>(TEXT("MovimientoNavesComponente"));
	FireRate = 1.0f;
	Vida = 3;
	bIsDoubleFiring = false;

}

// Called when the game starts or when spawned
void AShipYorke::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(FireTimerHandle, this, &AShipYorke::FireProjectile, FireRate, true); 
}

// Called every frame
void AShipYorke::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AShipYorke::FireProjectile()
{
	FVector Offset1 = FVector(50.0f, -30.0f, 0.0f); // Offset para el primer proyectil
	  // Offset para el segundo proyectil

	// Obtén la dirección hacia adelante de la nave
	FVector ForwardDirection = GetActorForwardVector();

	// Calcula la rotación basada en la dirección hacia adelante
	FRotator SpawnRotation = ForwardDirection.Rotation();

	// Configura la posición y dirección del primer proyectil
	FVector SpawnLocation1 = GetActorLocation() + GetActorForwardVector() * Offset1.X + GetActorRightVector() * Offset1.Y + GetActorUpVector() * Offset1.Z;
	AYorkProjectile* Projectile1 = GetWorld()->SpawnActor<AYorkProjectile>(AYorkProjectile::StaticClass(), SpawnLocation1, SpawnRotation);
	if (Projectile1)
	{
		Projectile1->Fire();
	}
}

void AShipYorke::GetDamage()
{
	if (Vida <= 0) 
	{
		Destroy(); 
	} 
}

void AShipYorke::Update()
{
	if (!bIsDoubleFiring) //verifica que no esta disparando doble
	{
		DoubleFire(); 
		bIsDoubleFiring = true;//hace que dispare doble
	}
	else if (bIsDoubleFiring) //si esta disparando doble
	{
		bIsDoubleFiring = false; 
	}
}

void AShipYorke::DestroySubs()
{
	Publisher->RemoveObserver(this);
	Destroy(); 
}

void AShipYorke::DoubleFire()
{
	FVector Offset1 = FVector(50.0f, -30.0f, 0.0f); 
	FVector Offset2 = FVector(50.0f, 30.0f, 0.0f); 
	FVector ForwardDirection = GetActorForwardVector();
	FRotator SpawnRotation = ForwardDirection.Rotation();


	FVector SpawnLocation1 = GetActorLocation() + GetActorForwardVector() * Offset1.X + GetActorRightVector() * Offset1.Y + GetActorUpVector() * Offset1.Z;
	AYorkProjectile* Projectile1 = GetWorld()->SpawnActor<AYorkProjectile>(AYorkProjectile::StaticClass(), SpawnLocation1, SpawnRotation);
	if (Projectile1)
	{
		Projectile1->Fire();
	}
	FVector SpawnLocation2 = GetActorLocation() + GetActorForwardVector() * Offset2.X + GetActorRightVector() * Offset2.Y + GetActorUpVector() * Offset2.Z;
	AYorkProjectile* Projectile2 = GetWorld()->SpawnActor<AYorkProjectile>(AYorkProjectile::StaticClass(), SpawnLocation2, SpawnRotation);
	if (Projectile2)
	{
		Projectile2->Fire();
	}
}

void AShipYorke::SetPublisher(APublisher* _Publisher)
{
		Publisher = _Publisher; 
		Publisher->AddObserver(this); //recibe publi y se suscribe
}