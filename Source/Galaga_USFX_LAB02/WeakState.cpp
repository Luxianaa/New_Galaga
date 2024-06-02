// Fill out your copyright notice in the Description page of Project Settings.


#include "WeakState.h"
#include "HendrixShip.h"
//#include "CapsulaCrazy.h"  

// Sets default values
AWeakState::AWeakState()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TargetLocations.Add(FVector(0.0f, 0.0f, 200.0f));   // Punto A 
	TargetLocations.Add(FVector(1000.0f, 500.0f, 200.0f)); // Punto B
	TargetLocations.Add(FVector(0.0f, 1000.0f, 200.0f)); // Punto C 
	TargetLocations.Add(FVector(-1000.0f, 500.0f, 200.0f)); // Punto D   
	TargetLocations.Add(FVector(0.0f, 0.0f, 200.0f));   // De vuelta a Punto A  
	CurrentTargetIndex = 0;   
	Speed = 900.0f;  
	NumShotsFired = 0; 
	MaxShots = 3;  
}

// Called when the game starts or when spawned
void AWeakState::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(TiempoVisibilidad, this, &AWeakState::Hide, 0.3f, true); 
}

// Called every frame
void AWeakState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWeakState::Move(float DeltaTime)
{ 
	FVector newLocation = Hendrix->GetActorLocation(); 
	FVector targetLocation = TargetLocations[CurrentTargetIndex]; 
	FVector direction = (targetLocation - newLocation).GetSafeNormal(); 
	float distance = FVector::Distance(targetLocation, newLocation);
	newLocation += direction * Speed * DeltaTime;

	Hendrix->SetActorLocation(newLocation);

	// Verificar si la nave ha llegado a la ubicación de destino actual
	if (distance < 10.0f)
	{
		// Mover a la siguiente ubicación de destino
		CurrentTargetIndex = (CurrentTargetIndex + 1) % TargetLocations.Num(); 
	}
}

void AWeakState::Drop()
{
	//if (NumShotsFired >= MaxShots)
	//{
	//	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Límite de disparos alcanzado"));
	//	return; 
	//}
	//ACapsulaCrazy* Crazy = GetWorld()->SpawnActor<ACapsulaCrazy>(ACapsulaCrazy::StaticClass(), GetActorLocation(), GetActorRotation());
	//if (Crazy)
	//{
	//	// Obtén la dirección hacia adelante de la nave enemiga
	//	FVector ForwardDirection = Hendrix->GetActorForwardVector();

	//	// Calcula la rotación basada en la dirección hacia adelante
	//	//FRotator SpawnRotation = ForwardDirection.Rotation(); 

	//	// Configura la posición y dirección del proyectil
	//	FVector SpawnLocation = Hendrix->GetActorLocation(); 
	//	Crazy->SetActorLocationAndRotation(Hendrix->GetActorLocation(), ForwardDirection.Rotation());
	//	// Dispara el proyectil 
	//	NumShotsFired++;
	//	Crazy->FireCpasule(); 
	//} 
}

void AWeakState::Hide()
{
	if(Hendrix)
	{
		bool Desaparecer = FMath::RandBool();

		Hendrix->SetActorHiddenInGame(!Desaparecer);
		//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, Desaparecer ? TEXT("Visible") : TEXT("Oculto"));
	}
}

void AWeakState::SetHendrix(AHendrixShip* _Hendrix)
{
	Hendrix = Cast<AHendrixShip>(_Hendrix);
	Hendrix->SetState(Hendrix->GetWeakState());
}

