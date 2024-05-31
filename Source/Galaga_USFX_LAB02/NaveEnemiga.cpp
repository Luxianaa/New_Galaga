// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemiga.h"
#include "ProyectilEnemigo.h"
#include "Sound/SoundBase.h" 
#include "Kismet/GameplayStatics.h"
#include "StrategyStraight.h"

// Sets default values
ANaveEnemiga::ANaveEnemiga()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mallaNaveEnemiga = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	mallaNaveEnemiga->SetupAttachment(RootComponent);
	RootComponent = mallaNaveEnemiga; 

    Radio = 300.0f; // Radio de la circunferencia
    Angulo = 0.0f; // Ángulo inicial
    Speed = 5.0f;

	//MovimientoNavesComponent = CreateDefaultSubobject<UAComponenteMovimiento>(TEXT("MovimientoNavesComponente"));

	FireRate = 3.0f;//Cadencia Balas
	static ConstructorHelpers::FObjectFinder<USoundBase> FireAudio(TEXT("SoundWave'/Game/StarterContent/Assets/shoot02wav-14562.shoot02wav-14562'"));
	FireSound = FireAudio.Object;
}

// Called when the game starts or when spawned
void ANaveEnemiga::BeginPlay()
{
	Super::BeginPlay(); 
	
	GetWorld()->GetTimerManager().SetTimer(FireTimerHandle, this, &ANaveEnemiga::FireProjectile, FireRate, true);
}

void ANaveEnemiga::FireProjectile()
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
		 
		if (FireSound != nullptr)
		{
			UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
		}

		// Dispara el proyectil
		Projectile->Fire();
	}
}
// Called every frame
void ANaveEnemiga::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); 

	//Angulo += Speed * DeltaTime;

	////// Calcula las nuevas posiciones en x y y
	//float NuevaX = GetActorLocation().X + Radio * FMath::Cos(Angulo) * DeltaTime; 
	//float NuevaY = GetActorLocation().Y + Radio * FMath::Sin(Angulo) * DeltaTime; 

	////// Establece la nueva posición
	//FVector NewLocation = FVector(NuevaX, NuevaY, GetActorLocation().Z); 
	//SetActorLocation(NewLocation); 

	//MovimientoNavesComponent->TickComponent(DeltaTime, ELevelTick::LEVELTICK_TimeOnly, nullptr); 

}

