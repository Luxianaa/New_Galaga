// Fill out your copyright notice in the Description page of Project Settings.


#include "StrategyAlly.h"
#include "ShipYorke.h"
#include "CapsulaVida.h"
#include "CapsulaEnergia.h"

// Sets default values
AStrategyAlly::AStrategyAlly()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Radio = 20.0f;// dio de la circunferencia
	Angulo = 0.0f; // �ngulo inicial
	Speed = 2.0f;
	Time = 0.0f;
	NumShotsFired = 0; 
	MaxShots = 10; 

}

// Called when the game starts or when spawned
void AStrategyAlly::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStrategyAlly::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Time += DeltaTime;

}

void AStrategyAlly::ExecuteStrategy(AShipYorke* Yorke)
{
	Angulo += Speed * Time;
	float PosicionX = Yorke->GetActorLocation().X + Radio * FMath::Cos(Angulo);
	float PosicionY = Yorke->GetActorLocation().Y + Radio * FMath::Sin(Angulo);
	FVector NuevaPosicion = FVector(PosicionX, PosicionY, Yorke->GetActorLocation().Z);
	Yorke->SetActorLocation(NuevaPosicion); 

	if (NumShotsFired >= MaxShots)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("L�mite de disparos alcanzado"));
		return;
	}
	if (Time >= 4) {
		ACapsulaEnergia* Energy = GetWorld()->SpawnActor<ACapsulaEnergia>(ACapsulaEnergia::StaticClass(), GetActorLocation(), GetActorRotation());
		if (Energy)
		{
			FVector ForwardDirection = Yorke->GetActorForwardVector();
			FRotator SpawnRotation = ForwardDirection.Rotation();
			FVector SpawnLocation = Yorke->GetActorLocation();

			// Ajustar la rotaci�n para que el Alien mire hacia adelante
			FRotator AdjustedRotation = SpawnRotation;
			AdjustedRotation.Pitch = 180.0f; // Aseg�rate de que no haya inclinaci�n hacia arriba/abajo 
			AdjustedRotation.Roll = 0.0f;  // Aseg�rate de que no haya rotaci�n lateral 

			Energy->SetActorLocationAndRotation(SpawnLocation, AdjustedRotation);
			Energy->Drop();
			NumShotsFired++;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Disparos realizados: %d"), NumShotsFired));
		}
	}
	if (Time >= 6)
	{
		ACapsulaVida* Life = GetWorld()->SpawnActor<ACapsulaVida>(ACapsulaVida::StaticClass(), GetActorLocation(), GetActorRotation());
		 if (Life)
		 {
			FVector ForwardDirection = Yorke->GetActorForwardVector();
			FRotator SpawnRotation = ForwardDirection.Rotation();
			FVector SpawnLocation = Yorke->GetActorLocation();

			// Ajustar la rotaci�n para que el Alien mire hacia adelante
			FRotator AdjustedRotation = SpawnRotation;
			AdjustedRotation.Pitch = 180.0f; // Aseg�rate de que no haya inclinaci�n hacia arriba/abajo 
			AdjustedRotation.Roll = 0.0f;  // Aseg�rate de que no haya rotaci�n lateral 

			Life->SetActorLocationAndRotation(SpawnLocation, AdjustedRotation);
			Life->Drop();   
			NumShotsFired++;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Disparos realizados: %d"), NumShotsFired));
		}
	}
}

