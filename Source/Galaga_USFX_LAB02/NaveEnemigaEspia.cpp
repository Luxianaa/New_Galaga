// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaEspia.h"
#include "AComponenteMovimiento.h"



ANaveEnemigaEspia::ANaveEnemigaEspia()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> malla(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO_Espia.TwinStickUFO_Espia'"));
	mallaNaveEnemiga->SetStaticMesh(malla.Object);
    VelocidadVertical = 1.0f;
    PrimaryActorTick.bCanEverTick = true;

    // Define los puntos del rombo
    TargetLocations.Add(FVector(0.0f, 0.0f, 200.0f));   // Punto A 
    TargetLocations.Add(FVector(1000.0f, 500.0f, 200.0f)); // Punto B
    TargetLocations.Add(FVector(0.0f, 1000.0f, 200.0f)); // Punto C 
    TargetLocations.Add(FVector(-1000.0f, 500.0f, 200.0f)); // Punto D 
    TargetLocations.Add(FVector(0.0f, 0.0f, 200.0f));   // De vuelta a Punto A 
    CurrentTargetIndex = 0; 
    Speed = 1000.0f; 
    Vida = 1;
}

void ANaveEnemigaEspia::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    FVector NewLocation = GetActorLocation();
    FVector TargetLocation = TargetLocations[CurrentTargetIndex];
    FVector Direction = (TargetLocation - NewLocation).GetSafeNormal();
    float Distance = FVector::Distance(TargetLocation, NewLocation);
    NewLocation += Direction * Speed * DeltaTime;

    SetActorLocation(NewLocation);

    // Verificar si la nave ha llegado a la ubicación de destino actual
    if (Distance < 10.0f)
    {
        // Mover a la siguiente ubicación de destino
        CurrentTargetIndex = (CurrentTargetIndex + 1) % TargetLocations.Num();
    }
    //float AlturaInicial = 200.0f;
    //float AlturaFinal = 350.0f;

    //// Definir la velocidad de movimiento vertical
    ////float VelocidadVertical = 50.0f; // Puedes ajustar esta velocidad según tu preferencia

    //// Calcular la nueva posición en Z
    //float NuevaAltura = FMath::Lerp(AlturaInicial, AlturaFinal, FMath::Abs(FMath::Sin(GetWorld()->TimeSeconds * VelocidadVertical)));

    ////
    //// Si ya hemos alcanzado la altura final, invertimos la dirección
    //if (FMath::IsNearlyEqual(NuevaAltura, AlturaFinal, 1.0f))
    //{
    //    VelocidadVertical *= -1.0f; // Cambiamos la dirección
    //}

    //// Establecer la nueva posición de la nave
    //SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, NuevaAltura));
}

void ANaveEnemigaEspia::ReceiveDamage()
{
    Vida--;
    if (Vida <= 0)
    {
		Destroy();
	}
}
