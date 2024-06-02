// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaUwU.h"
#include "ProyectilEnemigo.h"
#include "Kismet/GameplayStatics.h"


ANaveEnemigaUwU::ANaveEnemigaUwU()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> malla(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO_UwU.TwinStickUFO_UwU'"));
	mallaNaveEnemiga->SetStaticMesh(malla.Object);	
	//targetXLocations[0] = 100.0f;
	//targetYLocations[0] = 1000.0f;
	//targetXLocations[1] = 1300.0f;
	//targetYLocations[1] = 1000.0f;
	//targetXLocations[2] = 1300.0f;
	//targetYLocations[2] = -1000.0f;
	//targetXLocations[3] = 100.0f;
	//targetYLocations[3] = -1000.0f;
	//currentTargetIndex = 0;
	Vida = 1;
}
void ANaveEnemigaUwU::BeginPlay()
{
	Super::BeginPlay();
}

void ANaveEnemigaUwU::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);	
				// Calculate the new position based on the current direction and speed
	//FVector newLocation = GetActorLocation();
	//float dx = targetXLocations[currentTargetIndex] - newLocation.X;
	//float dy = targetYLocations[currentTargetIndex] - newLocation.Y;
	//float distance = sqrt(dx * dx + dy * dy);
	//float direction = atan2(dy, dx);
	//newLocation.X += speed * DeltaTime * cos(direction);
	//newLocation.Y += speed * DeltaTime * sin(direction);
	//SetActorLocation(newLocation);

	//// Check if the ship has reached the current target location
	//if (distance < 10.0f)
	//{
	//	// Move to the next target location
	//	currentTargetIndex = (currentTargetIndex + 1) % 4;
	//}
}

void ANaveEnemigaUwU::ReceiveDamage()
{
	Vida--;
	if (Vida <= 0)
	{
		Destroy();
	}
}
