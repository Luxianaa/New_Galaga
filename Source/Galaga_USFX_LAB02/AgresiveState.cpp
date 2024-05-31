// Fill out your copyright notice in the Description page of Project Settings.


#include "AgresiveState.h"
#include "HendrixShip.h"
#include "Aliens.h"

// Sets default values
AAgresiveState::AAgresiveState()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    targetLocations.Add(FVector(-300, 1600, 200));    // Coordenada 1
    targetLocations.Add(FVector(-880, 1000, 200));  // Coordenada 2
    targetLocations.Add(FVector(-510, 560, 200));  // Coordenada 3
    targetLocations.Add(FVector(-880, 40, 200));  // Coordenada 4
    targetLocations.Add(FVector(-510, -480, 200));  // Coordenada 5
    targetLocations.Add(FVector(-880, -950, 200));    // Coordenada 6
    targetLocations.Add(FVector(-300, -1600, 200));    // Coordenada 7
    currentTargetIndex = 0;
    Speed = 1500.0f;
    NumShotsFired = 0; 
    MaxShots = 3; 
}

// Called when the game starts or when spawned
void AAgresiveState::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAgresiveState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAgresiveState::Move(float DeltaTime)
{
	FVector newLocation = Hendrix->GetActorLocation();
	FVector targetLocation = targetLocations[currentTargetIndex];
	FVector direction = (targetLocation - newLocation).GetSafeNormal();
	float distance = FVector::Distance(targetLocation, newLocation);
	newLocation += direction * Speed * DeltaTime;

	Hendrix->SetActorLocation(newLocation);

	// Verificar si la nave ha llegado a la ubicación de destino actual
	if (distance < 10.0f)
	{
		// Mover a la siguiente ubicación de destino
		currentTargetIndex = (currentTargetIndex + 1) % targetLocations.Num();
	}

}

void AAgresiveState::Drop()
{
	if (NumShotsFired >= MaxShots)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Límite de disparos alcanzado"));
		return;
	}

	AAliens* Alien = GetWorld()->SpawnActor<AAliens>(AAliens::StaticClass(), GetActorLocation(), GetActorRotation());
	if (Alien)
	{
		FVector ForwardDirection = Hendrix->GetActorForwardVector();
		FRotator SpawnRotation = ForwardDirection.Rotation();
		FVector SpawnLocation = Hendrix->GetActorLocation();
		Alien->SetActorLocationAndRotation(SpawnLocation, SpawnRotation);
		Alien->Drop();
		NumShotsFired++;
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Disparos realizados: %d"), NumShotsFired));
	}
}

void AAgresiveState::Hide()
{
}

void AAgresiveState::SetHendrix(AHendrixShip* _Hendrix)
{
	Hendrix = Cast<AHendrixShip>(_Hendrix);
	Hendrix->SetState(Hendrix->GetAgresiveState());
}

