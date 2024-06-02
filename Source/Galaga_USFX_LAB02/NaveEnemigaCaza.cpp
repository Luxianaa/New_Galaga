// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaCaza.h"
#include "Aliens.h"
//#include "ProyectilEnemigo.h"

ANaveEnemigaCaza::ANaveEnemigaCaza()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> malla(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO_Caza.TwinStickUFO_Caza'"));
	mallaNaveEnemiga->SetStaticMesh(malla.Object);// Cargamos la malla de la nave enemiga
	 Radio = 20.0f;// dio de la circunferencia
	 Angulo = 0.0f; // Ángulo inicial
	 Speed = 2.0f;
	 Vida = 1;
}

void ANaveEnemigaCaza::BeginPlay()
{
	Super::BeginPlay();
}

void ANaveEnemigaCaza::Drops()
{
	/*FVector NewLocation = GetActorLocation() + GetActorForwardVector() * 300.0f;
	SetActorLocation(NewLocation);*/
}



void ANaveEnemigaCaza::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Angulo += Speed * DeltaTime; 
	float PosicionX = GetActorLocation().X + Radio * FMath::Cos(Angulo);
	float PosicionY = GetActorLocation().Y + Radio * FMath::Sin(Angulo);
	FVector NuevaPosicion = FVector(PosicionX, PosicionY, GetActorLocation().Z);
	SetActorLocation(NuevaPosicion); 


	//// Calcula las nuevas posiciones en x y y
	float NuevaX = GetActorLocation().X + Radio * FMath::Cos(Angulo) * DeltaTime;
	float NuevaY = GetActorLocation().Y + Radio * FMath::Sin(Angulo) * DeltaTime;

	//// Establece la nueva posición
	FVector NewLocation = FVector(NuevaX, NuevaY, GetActorLocation().Z);
	SetActorLocation(NewLocation);

	
}

void ANaveEnemigaCaza::ReceiveDamage()
{
	Vida--;
	if (Vida <= 0)
	{
		Destroy();
	}
}
