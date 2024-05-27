// Fill out your copyright notice in the Description page of Project Settings.


#include "ShipYorke.h"
#include "YorkProjectile.h"

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
	FireRate = 1.0f;
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
	AYorkProjectile* Projectile = GetWorld()->SpawnActor<AYorkProjectile>(AYorkProjectile::StaticClass(), GetActorLocation(), GetActorRotation());
	if (Projectile)
	{
		//Obt�n la direcci�n hacia adelante de la nave enemiga
		FVector ForwardDirection = GetActorForwardVector();

		// Calcula la rotaci�n basada en la direcci�n hacia adelante
		FRotator SpawnRotation = ForwardDirection.Rotation();

		// Configura la posici�n y direcci�n del proyectil
		FVector SpawnLocation = GetActorLocation();
		Projectile->SetActorLocationAndRotation(SpawnLocation, SpawnRotation);
		Projectile->Fire(); 
	}
}


