// Fill out your copyright notice in the Description page of Project Settings.


#include "FacadeScore.h"
#include "NaveEnemiga.h"
#include "Galaga_USFX_LAB02Projectile.h" 
#include "Shield.h"

// Sets default values
AFacadeScore::AFacadeScore()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ScorePorEnemigo = 10;
}

// Called when the game starts or when spawned
void AFacadeScore::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFacadeScore::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFacadeScore::Colisionar(AActor* OtherActor)
{
	ANaveEnemiga* NaveEnemiga = Cast<ANaveEnemiga>( OtherActor);
	if (NaveEnemiga)
	{
    //	ScorePorEnemigo++;
		//// Mostrar un mensaje en pantalla informando al jugador sobre la destrucción de la nave enemiga
		FString Message = FString::Printf(TEXT("¡Nave enemiga destruida! Puntuacion:%c"));
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, Message); 

		// Llamar a la función destruir de la nave enemiga
		NaveEnemiga->Destroy();
	}
	
}

void AFacadeScore::ColisionarEscudo(AActor* OtherActor)
{
	AShield* Shield = Cast<AShield>(OtherActor); 
	if (Shield)
	{
		//contadorPawn += 2000;
		// Mostrar un mensaje en pantalla informando al jugador sobre la destrucción de la nave enemiga
		FString Message = FString::Printf(TEXT("¡Escudo destruido destruida! Puntuacion:%c"));
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, Message);

		// Llamar a la función destruir de la nave enemiga
		Shield->Destroy();
	}
}

