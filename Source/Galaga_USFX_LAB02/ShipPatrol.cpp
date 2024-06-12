// Fill out your copyright notice in the Description page of Project Settings.


#include "ShipPatrol.h"
#include "Galaga_USFX_LAB02Pawn.h"
#include "CapsulaVida.h"
#include "Ball.h"
#include "Misil.h"

// Sets default values
AShipPatrol::AShipPatrol()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> Patrol(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO_5.TwinStickUFO_5'"));
	PatrolMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshPtrl"));
	PatrolMesh->SetupAttachment(RootComponent);
	PatrolMesh->SetStaticMesh(Patrol.Object);
	RootComponent = PatrolMesh; 
	TargetLocations.Add(FVector(0.0f, 0.0f, 200.0f));   // Punto A  
	TargetLocations.Add(FVector(1000.0f, 500.0f, 200.0f)); // Punto B 
	TargetLocations.Add(FVector(0.0f, 1000.0f, 200.0f)); // Punto C  
	TargetLocations.Add(FVector(-1000.0f, 500.0f, 200.0f)); // Punto D  
	TargetLocations.Add(FVector(0.0f, 0.0f, 200.0f));   // De vuelta a Punto A  

	CurrentTargetIndex = 0; 
	Speed = 1000.0f; 
	NumShotsFired = 0;
	MaxShots = 4;
	MaxBombs = 5;
}

// Called when the game starts or when spawned
void AShipPatrol::BeginPlay()
{
	Super::BeginPlay(); 
}

// Called every frame
void AShipPatrol::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Time = DeltaTime;   
}

void AShipPatrol::FollowPawn()
{
	Pawn = Cast<AGalaga_USFX_LAB02Pawn>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (Pawn)
	{
		FVector PlayerPosition = Pawn->GetActorLocation();   
		FVector ShipPosition = PlayerPosition + FVector(-600, 0,200);
		// Establece la posición de la nave como la posición del jugador
		SetActorLocation(ShipPosition);  
	}
	
}

void AShipPatrol::Move()
{
	FVector NewLocation = GetActorLocation();
	FVector TargetLocation = TargetLocations[CurrentTargetIndex];
	FVector Direction = (TargetLocation - NewLocation).GetSafeNormal();
	float Distance = FVector::Distance(TargetLocation, NewLocation);
	NewLocation += Direction * Speed * Time;

	SetActorLocation(NewLocation);

	if (Distance < 10.0f)
	{
		CurrentTargetIndex = (CurrentTargetIndex + 1) % TargetLocations.Num();
	}
}

void AShipPatrol::DropCapsule()
{
	if (NumShotsFired >= MaxShots)
	{
		return;
	}
	ACapsulaVida* Life = GetWorld()->SpawnActor<ACapsulaVida>(ACapsulaVida::StaticClass(), GetActorLocation(), GetActorRotation());
	if (Life)
	{
		FVector ForwardDirection = GetActorForwardVector(); 

		FRotator SpawnRotation = ForwardDirection.Rotation(); 

		FVector SpawnLocation = GetActorLocation(); 
		Life->SetActorLocationAndRotation(SpawnLocation, SpawnRotation); 
		Life->Drop(); 
		NumShotsFired++;   
	}
}
void AShipPatrol::ThrowBomb()
{
	if (NumShotsFired1 >= MaxBombs)
	{
		return;
	}
	ABall* Ball = GetWorld()->SpawnActor<ABall>(ABall::StaticClass(), GetActorLocation(), GetActorRotation());
	if (Ball)
		{
		// Obtén la dirección hacia adelante de la nave enemiga
		FVector ForwardDirection = GetActorForwardVector();

		// Calcula la rotación basada en la dirección hacia adelante
		FRotator SpawnRotation = ForwardDirection.Rotation(); 

		// Configura la posición y dirección del proyectil
		FVector SpawnLocation = GetActorLocation();

		Ball->SetActorLocationAndRotation(SpawnLocation, SpawnRotation);
		Ball->Lanzar();     
		NumShotsFired1++;
	}
}
void AShipPatrol::UndoCommand(FString _Command)
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("Jugador deshizo el comando: %s"), *_Command)); 
}