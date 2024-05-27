// Fill out your copyright notice in the Description page of Project Settings.


#include "ShipYorke.h"
#include "Galaga_USFX_LAB02Projectile.h"

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
}

// Called when the game starts or when spawned
void AShipYorke::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShipYorke::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AShipYorke::Fire()
{
	AGalaga_USFX_LAB02Projectile* Projectile = GetWorld()->SpawnActor<AGalaga_USFX_LAB02Projectile>(AGalaga_USFX_LAB02Projectile::StaticClass(), GetActorLocation(), GetActorRotation());
	if (Projectile)
	{
		//Obtén la dirección hacia adelante de la nave enemiga
		FVector ForwardDirection = GetActorForwardVector(); 

		// Calcula la rotación basada en la dirección hacia adelante 
		FRotator SpawnRotation = ForwardDirection.Rotation(); 

		// Configura la posición y dirección del proyectil
		FVector SpawnLocation = GetActorLocation(); 
		Projectile->SetActorLocationAndRotation(SpawnLocation, SpawnRotation); 
		
	}
}

