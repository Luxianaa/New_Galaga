// Fill out your copyright notice in the Description page of Project Settings.


#include "ShipYorke.h"
#include "AComponenteMovimiento.h"
#include "YorkProjectile.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"
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

	Vida = 5;
	Vida= VidaMaxima;
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
		//Obtén la dirección hacia adelante de la nave enemiga
		FVector ForwardDirection = GetActorForwardVector();

		// Calcula la rotación basada en la dirección hacia adelante
		FRotator SpawnRotation = ForwardDirection.Rotation();

		// Configura la posición y dirección del proyectil
		FVector SpawnLocation = GetActorLocation();
		Projectile->SetActorLocationAndRotation(SpawnLocation, SpawnRotation);
		Projectile->Fire(); 
	}
}

//void AShipYorke::Subscribe(IISubscriber* subscriber)
//{
//	Subscribers.Add(subscriber);
//}
//void AShipYorke::Unsubscribe(IISubscriber* subscriber)
//{
//	Subscribers.Remove(subscriber);
//}
//void AShipYorke::Notify()
//{
//	for (IISubscriber* subscriber : Subscribers) 
//	{
//		subscriber->Auxiliar(this);
//	}
//}
//
//void AShipYorke::GetDamage(int Damage)
//{
//	Vida -= Damage;
//	if(Vida<=1)
//	{
//		Notify();
//	}
//}
