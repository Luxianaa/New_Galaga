// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons.h"
#include "MShipProjectile.h"
#include "Sound/SoundBase.h" 
#include "Kismet/GameplayStatics.h"

// Sets default values
AWeapons::AWeapons()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> meshWeapons(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Pipe_2.Shape_Pipe_2'"));
	MeshWeapons = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshMotor"));
	MeshWeapons->SetupAttachment(RootComponent);
	MeshWeapons->SetStaticMesh(meshWeapons.Object); 
	SetActorScale3D(FVector(5.0f, 5.0f, 5.0f));
	//MovimientoComponent = CreateDefaultSubobject<UAComponenteMovimiento>(TEXT("MovimientoNavesComponente"));
	//MovimientoNavesComponent = CreateDefaultSubobject<UAComponenteMovimiento>(TEXT("MovimientoNavesComponente"));
	RootComponent = MeshWeapons;
	FireRate = 1.0f;

	static ConstructorHelpers::FObjectFinder<USoundBase> FireAudio(TEXT("SoundWave'/Game/TwinStick/Audio/TwinStickFire.TwinStickFire'"));
	FireSound = FireAudio.Object;
}

// Called when the game starts or when spawned
void AWeapons::BeginPlay()
{
	Super::BeginPlay();
	 GetWorld()->GetTimerManager().SetTimer(FireTimerHandle, this, &AWeapons::FireProjectiles, FireRate, true);
}

// Called every frame
void AWeapons::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWeapons::FireProjectiles()
{
	AMShipProjectile* Projectile = GetWorld()->SpawnActor<AMShipProjectile>(AMShipProjectile::StaticClass(), GetActorLocation(), GetActorRotation());
	if (Projectile)
	{

		 //Obtén la dirección hacia adelante de la nave enemiga
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
		Projectile->Fires();
	}
}

