// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaTransporte.h"
#include "Aliens.h"


ANaveEnemigaTransporte::ANaveEnemigaTransporte()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> malla(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO_Transporte.TwinStickUFO_Transporte'"));
	mallaNaveEnemiga->SetStaticMesh(malla.Object);
     VelocidadVertical = 1.0f;
     // Asignar coordenadas de destino
     targetLocations.Add(FVector(-300, 1600, 200));    // Coordenada 1
     targetLocations.Add(FVector(-880, 1000, 200));  // Coordenada 2
     targetLocations.Add(FVector(-510, 560, 200));  // Coordenada 3
     targetLocations.Add(FVector(-880, 40, 200));  // Coordenada 4
     targetLocations.Add(FVector(-510, -480, 200));  // Coordenada 5
     targetLocations.Add(FVector(-880, -950, 200));    // Coordenada 6
     targetLocations.Add(FVector(-300, -1600, 200));    // Coordenada 7

     // Set the initial target location index

     currentTargetIndex = 0;

}


void ANaveEnemigaTransporte::FireProjectile()
{ 
    AAliens* Alien = GetWorld()->SpawnActor<AAliens>(AAliens::StaticClass(), GetActorLocation(), GetActorRotation());
    if (Alien)
	{
        FVector ForwardDirection = GetActorForwardVector();

        // Calcula la rotación basada en la dirección hacia adelante
        FRotator SpawnRotation = ForwardDirection.Rotation();

        // Configura la posición y dirección del proyectil
        FVector SpawnLocation = GetActorLocation();
        Alien->SetActorLocationAndRotation(SpawnLocation, SpawnRotation);

       /* if (FireSound != nullptr)
        {
            UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
        }*/

        // Dispara el proyectil
        Alien->Drop(); 
	
	}

}

void ANaveEnemigaTransporte::Tick(float DeltaTime)
{
		Super::Tick(DeltaTime);

        FVector newLocation = GetActorLocation();
        FVector targetLocation = targetLocations[currentTargetIndex];
        FVector direction = (targetLocation - newLocation).GetSafeNormal();
        float distance = FVector::Distance(targetLocation, newLocation);
        newLocation += direction * speed * DeltaTime;

        SetActorLocation(newLocation);

        // Verificar si la nave ha llegado a la ubicación de destino actual
        if (distance < 10.0f)
        {
            // Mover a la siguiente ubicación de destino
            currentTargetIndex = (currentTargetIndex + 1) % targetLocations.Num();
        }
//-----------------------------------------------------------------------------------------//
        float AlturaInicial = 200.0f;
        float AlturaFinal = 350.0f;

        // Definir la velocidad de movimiento vertical
        //float VelocidadVertical = 50.0f; // Puedes ajustar esta velocidad según tu preferencia

        // Calcular la nueva posición en Z
        float NuevaAltura = FMath::Lerp(AlturaInicial, AlturaFinal, FMath::Abs(FMath::Sin(GetWorld()->TimeSeconds * VelocidadVertical)));

        //
        // Si ya hemos alcanzado la altura final, invertimos la dirección
        if (FMath::IsNearlyEqual(NuevaAltura, AlturaFinal, 1.0f))
        {
            VelocidadVertical *= -1.0f; // Cambiamos la dirección
        }

        // Establecer la nueva posición de la nave
        SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, NuevaAltura));
 
}
