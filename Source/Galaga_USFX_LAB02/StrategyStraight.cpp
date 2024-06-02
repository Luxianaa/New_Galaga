// Fill out your copyright notice in the Description page of Project Settings.


#include "StrategyStraight.h"
#include "NaveEnemiga.h"
#include "ShipYorke.h"

// Sets default values
AStrategyStraight::AStrategyStraight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

}



void AStrategyStraight::MoverNave(AShipYorke* Yorke)
{
	if (Yorke)
	{
		// Obtener la posición actual de la nave
		FVector PosicionActual = Yorke->GetActorLocation();

		// Definir los límite DERECHO E IZQUIERDO de movimiento
		float LimiteDerecho = 1528.0f;
		float LimiteIzquierdo = -1600.0f;

		// Definir la velocidad de movimiento horizontal
		float VelocidadHorizontal = 800.0f;

		// Calcular el desplazamiento horizontal para este fotograma
		float DesplazamientoHorizontal = VelocidadHorizontal ;

		// Verificar si la nave está moviéndose hacia derecha o izquierda

		if (DireccionMovimientoHorizontal == 1) // Movimiento hacia derecha
		{
			// Mover la nave hacia derecha
			FVector NuevaPosicion = PosicionActual + FVector(0.0f, DesplazamientoHorizontal, 0.0f);
			if (NuevaPosicion.Y <= LimiteDerecho)
			{
				Yorke->SetActorLocation(NuevaPosicion);
			}
			else
			{
				// Si alcanza el límite superior, cambiar la dirección de movimiento a hacia izquierda
				DireccionMovimientoHorizontal = -1;
			}
		}
		else // Movimiento hacia izquierda
		{
			// Mover la nave hacia izquierda
			FVector NuevaPosicion = PosicionActual - FVector(0.0f, DesplazamientoHorizontal, 0.0f);
			if (NuevaPosicion.Y >= LimiteIzquierdo)
			{
				Yorke->SetActorLocation(NuevaPosicion);
			}
			else
			{
				// Si alcanza el límite de la izquierda, cambiar la dirección de movimiento a hacia la derecha
				DireccionMovimientoHorizontal = 1;
			}
		}
	}
}

//void AStrategyStraight::ApplyMovement(/*AShipYorke* Yorke,*/ float DeltaTime)
//{
//	if (Yorke)
//	{
//		// Obtener la posición actual de la nave
//		FVector PosicionActual = Yorke->GetActorLocation();
//
//		// Definir los límite DERECHO E IZQUIERDO de movimiento
//		float LimiteDerecho = 1528.0f;
//		float LimiteIzquierdo = -1600.0f;
//
//		// Definir la velocidad de movimiento horizontal
//		float VelocidadHorizontal = 800.0f;
//
//		// Calcular el desplazamiento horizontal para este fotograma
//		float DesplazamientoHorizontal = VelocidadHorizontal * DeltaTime;
//
//		// Verificar si la nave está moviéndose hacia derecha o izquierda
//
//		if (DireccionMovimientoHorizontal == 1) // Movimiento hacia derecha
//		{
//			// Mover la nave hacia derecha
//			FVector NuevaPosicion = PosicionActual + FVector(0.0f, DesplazamientoHorizontal, 0.0f);
//			if (NuevaPosicion.Y <= LimiteDerecho)
//			{
//				Yorke->SetActorLocation(NuevaPosicion);
//			}
//			else
//			{
//				// Si alcanza el límite superior, cambiar la dirección de movimiento a hacia izquierda
//				DireccionMovimientoHorizontal = -1;
//			}
//		}
//		else // Movimiento hacia izquierda
//		{
//			// Mover la nave hacia izquierda
//			FVector NuevaPosicion = PosicionActual - FVector(0.0f, DesplazamientoHorizontal, 0.0f);
//			if (NuevaPosicion.Y >= LimiteIzquierdo)
//			{
//				Yorke->SetActorLocation(NuevaPosicion);
//			}
//			else
//			{
//				// Si alcanza el límite de la izquierda, cambiar la dirección de movimiento a hacia la derecha
//				DireccionMovimientoHorizontal = 1;
//			}
//		}
//	}
//}
	
