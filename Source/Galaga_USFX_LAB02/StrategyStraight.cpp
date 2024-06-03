// Fill out your copyright notice in the Description page of Project Settings.


#include "StrategyStraight.h"
#include "NaveEnemiga.h"
#include "ShipYorke.h"
#include "YorkProjectile.h"
#include "NavePruebas.h"

// Sets default values
AStrategyStraight::AStrategyStraight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


    Time = 0.0f;
    LimiteDerecho = 1528.0f;
    LimiteIzquierdo = -1600.0f;
    VelocidadHorizontal = 800.0f;
    DireccionMovimientoHorizontal = 1;
}

// Called when the game starts or when spawned
void AStrategyStraight::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStrategyStraight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Time += DeltaTime;
   // ExecuteStrategy(nullptr);
}

void AStrategyStraight::ExecuteStrategy(AShipYorke* Yorke) 
{
    FVector PosicionActual = Yorke->GetActorLocation();
    float DesplazamientoHorizontal = VelocidadHorizontal * Yorke->GetWorld()->DeltaTimeSeconds;

    // Verificar si la nave está moviéndose hacia derecha o izquierda
    if (DireccionMovimientoHorizontal == 1) // Movimiento hacia derecha
    {
        // Mover la nave hacia derecha en el eje X
        FVector NuevaPosicion = PosicionActual + FVector(DesplazamientoHorizontal, 0.0f, 0.0f);
        if (NuevaPosicion.X <= LimiteDerecho)
        {
            Yorke->SetActorLocation(NuevaPosicion);
        }
        else
        {
            // Si alcanza el límite derecho, cambiar la dirección de movimiento a hacia izquierda
            DireccionMovimientoHorizontal = -1;
        }
    }
    else // Movimiento hacia izquierda
    {
        // Mover la nave hacia izquierda en el eje X
        FVector NuevaPosicion = PosicionActual - FVector(DesplazamientoHorizontal, 0.0f, 0.0f);
        if (NuevaPosicion.X >= LimiteIzquierdo)
        {
            Yorke->SetActorLocation(NuevaPosicion);
        }
        else
        {
            // Si alcanza el límite izquierdo, cambiar la dirección de movimiento a hacia la derecha
            DireccionMovimientoHorizontal = 1;
        }
    }
}






