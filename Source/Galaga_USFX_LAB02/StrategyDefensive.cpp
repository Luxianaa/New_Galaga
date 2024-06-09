// Fill out your copyright notice in the Description page of Project Settings.


#include "StrategyDefensive.h"
#include "Galaga_USFX_LAB02Pawn.h" 
#include "CapsulaVida.h"
#include "Kismet/GameplayStatics.h" 

// Sets default values
AStrategyDefensive::AStrategyDefensive()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStrategyDefensive::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStrategyDefensive::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AStrategyDefensive::MoveFireHide()
{
	Pawn = Cast<AGalaga_USFX_LAB02Pawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	Pawn->MoveSpeed = +900.0f;  
	Pawn->FireRate = 2.0f; 

	ACapsulaVida* Life = GetWorld()->SpawnActor<ACapsulaVida>(ACapsulaVida::StaticClass(), GetActorLocation(), GetActorRotation());
	if (Life)
	{
		FVector ForwardDirection = Pawn->GetActorForwardVector();
		FRotator SpawnRotation = ForwardDirection.Rotation();
		FVector SpawnLocation = Pawn->GetActorLocation();

		// Ajustar la rotaci�n para que el Alien mire hacia adelante
		FRotator AdjustedRotation = SpawnRotation;
		AdjustedRotation.Pitch = 180.0f; // Aseg�rate de que no haya inclinaci�n hacia arriba/abajo 
		AdjustedRotation.Roll = 0.0f;  // Aseg�rate de que no haya rotaci�n lateral 

		Life->SetActorLocationAndRotation(SpawnLocation, AdjustedRotation);
		Life->Drop();
	} 

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Defensive Strategy On"));
}

