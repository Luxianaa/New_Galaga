// Fill out your copyright notice in the Description page of Project Settings.


#include "CrazyState.h"
#include "HendrixShip.h"

// Sets default values
ACrazyState::ACrazyState()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Radio = 1500.0f; 
	Angulo = 0.0f;
	Speed = 2.0f;
}

// Called when the game starts or when spawned
void ACrazyState::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACrazyState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACrazyState::Move(float DeltaTime)
{
	Angulo += Speed * DeltaTime;

	//// Calcula las nuevas posiciones en x y y
	float NuevaX = Hendrix->GetActorLocation().X + Radio * FMath::Cos(Angulo) * DeltaTime; 
	float NuevaY = Hendrix->GetActorLocation().Y + Radio * FMath::Sin(Angulo) * DeltaTime;

	//// Establece la nueva posición
	FVector NewLocation = FVector(NuevaX, NuevaY, Hendrix->GetActorLocation().Z); 
	Hendrix->SetActorLocation(NewLocation); 
}

void ACrazyState::Drop()
{
}

void ACrazyState::Hide()
{
}

void ACrazyState::SetHendrix(AHendrixShip* _Hendrix)
{
	Hendrix = Cast<AHendrixShip>(_Hendrix);
	Hendrix->SetState(Hendrix->GetCrazyState());
}

