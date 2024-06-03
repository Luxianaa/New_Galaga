// Fill out your copyright notice in the Description page of Project Settings.


#include "StrategyCrazy.h"
#include "ShipYorke.h"
#include "Aliens.h"

// Sets default values
AStrategyCrazy::AStrategyCrazy()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    TargetLocations.Add(FVector(-600.0f, -1000.0f, 200.0f)); // Punto A
    TargetLocations.Add(FVector(-3000.0f, -500.0f, 200.0f));  // Punto B
    TargetLocations.Add(FVector(600.0f, 1000.0f, 200.0f));   // Punto C
    TargetLocations.Add(FVector(-600.0f, 1000.0f, 200.0f));  // Punto D
    TargetLocations.Add(FVector(-600.0f, -1000.0f, 200.0f)); // De vuelta a Punto A

    CurrentTargetIndex = 0;
    MovementSpeed = 3000.0f; // Y
    Time = 0.0f;
    NumShotsFired = 0;
    MaxShots = 10;
}

// Called when the game starts or when spawned
void AStrategyCrazy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStrategyCrazy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    Time += DeltaTime;

}

void AStrategyCrazy::ExecuteStrategy(AShipYorke* Yorke)
{
    if (TargetLocations.Num() == 0) return;

    FVector CurrentLocation = Yorke->GetActorLocation();
    FVector TargetLocation = TargetLocations[CurrentTargetIndex];
    FVector Direction = (TargetLocation - CurrentLocation).GetSafeNormal();
    FVector NewLocation = CurrentLocation + Direction * MovementSpeed * Yorke->GetWorld()->DeltaTimeSeconds;


    Yorke->SetActorLocation(NewLocation);

    if (FVector::Dist(NewLocation, TargetLocation) < 10.0f) // Check if close to the target
    {
        CurrentTargetIndex = (CurrentTargetIndex + 1) % TargetLocations.Num();
    }

    if (NumShotsFired >= MaxShots)
    {
        //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Límite de disparos alcanzado"));
        return;
    }

    AAliens* Alien = GetWorld()->SpawnActor<AAliens>(AAliens::StaticClass(), GetActorLocation(), GetActorRotation());
    if (Alien)
    {
        FVector ForwardDirection = Yorke->GetActorForwardVector(); 
        FRotator SpawnRotation = ForwardDirection.Rotation(); 
        FVector SpawnLocation = Yorke->GetActorLocation(); 

        // Ajustar la rotación para que el Alien mire hacia adelante
        FRotator AdjustedRotation = SpawnRotation; 
        AdjustedRotation.Pitch = 180.0f; // Asegúrate de que no haya inclinación hacia arriba/abajo 
        AdjustedRotation.Roll = 0.0f;  // Asegúrate de que no haya rotación lateral 

        Alien->SetActorLocationAndRotation(SpawnLocation, AdjustedRotation); 
        Alien->Drop(); 
        NumShotsFired++; 
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Disparos realizados: %d"), NumShotsFired)); 
    } 
}

