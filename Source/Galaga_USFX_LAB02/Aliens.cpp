// Fill out your copyright notice in the Description page of Project Settings.


#include "Aliens.h"
#include "ProyectilEnemigo.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AAliens::AAliens()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	VelocidadVertical = 1.0f; 
	static ConstructorHelpers::FObjectFinder<UStaticMesh> meshA(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone_2.Shape_Cone_2'"));
	meshAlien = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshAlien")); 
	meshAlien->SetupAttachment(RootComponent); 
	meshAlien->SetStaticMesh(meshA.Object); 
	RootComponent = meshAlien;  
	SetActorScale3D(FVector(1.0f, 1.0f, 1.0f));
	FireRate = 2.0f;
	InitialLifeSpan = 6.0f;

}

// Called when the game starts or when spawned
void AAliens::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AAliens::FireProjectile, FireRate, true);
}

// Called every frame
void AAliens::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	float AlturaInicial = 200.0f;
	float AlturaFinal = 350.0f;
	// Calcular la nueva posición en Z
	float NuevaAltura = FMath::Lerp(AlturaInicial, AlturaFinal, FMath::Abs(FMath::Sin(GetWorld()->TimeSeconds * VelocidadVertical)));
	// Si ya hemos alcanzado la altura final, invertimos la dirección
	if (FMath::IsNearlyEqual(NuevaAltura, AlturaFinal, 1.0f))
	{
		VelocidadVertical *= -1.0f; // Cambiamos la dirección
	}

	// Establecer la nueva posición de la nave
	SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, NuevaAltura)); 
}

void AAliens::FireProjectile()
{
	AProyectilEnemigo* Projectile = GetWorld()->SpawnActor<AProyectilEnemigo>(AProyectilEnemigo::StaticClass(), GetActorLocation(), GetActorRotation());
	if (Projectile)
	{
		// Obtén la dirección hacia adelante de la nave enemiga
		FVector ForwardDirection = GetActorForwardVector();

		// Calcula la rotación basada en la dirección hacia adelante
		FRotator SpawnRotation = ForwardDirection.Rotation();

		// Configura la posición y dirección del proyectil
		FVector SpawnLocation = GetActorLocation();
		Projectile->SetActorLocationAndRotation(SpawnLocation, SpawnRotation);

		/*if (FireSound != nullptr)
		{
			UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
		}*/

		// Dispara el proyectil
		Projectile->Fire();
	}
}

void AAliens::Drop()
{
	FVector NewLocation = GetActorLocation() + GetActorForwardVector() * 300.0f; 
	SetActorLocation(NewLocation);  
}
