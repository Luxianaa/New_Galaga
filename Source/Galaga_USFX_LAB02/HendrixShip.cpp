// Fill out your copyright notice in the Description page of Project Settings.


#include "HendrixShip.h"
#include "CrazyState.h"
#include "AgresiveState.h"
#include "WeakState.h"

// Sets default values
AHendrixShip::AHendrixShip()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> meshHendrix(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO_Nodriza.TwinStickUFO_Nodriza'"));
	HendrixMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshHendrix"));
	HendrixMesh->SetupAttachment(RootComponent);
	HendrixMesh->SetStaticMesh(meshHendrix.Object);
	RootComponent = HendrixMesh;
	SetActorScale3D(FVector(3.0, 3.0f, 3.0f));
	Vida = 200;
}

// Called when the game starts or when spawned
void AHendrixShip::BeginPlay()
{
	Super::BeginPlay();
	CrazyState= GetWorld()->SpawnActor<ACrazyState>();
	AgresiveState = GetWorld()->SpawnActor<AAgresiveState>();  
	WeakState = GetWorld()->SpawnActor<AWeakState>();

	InicializarEstados(); 
}

// Called every frame
void AHendrixShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveHendrix(DeltaTime);
	DropHendrix(); 
}

void AHendrixShip::ReceiveDamageHendrix()
{
	Vida -= 25;
	if (Vida <= 0)
	{
		Destroy();
	}
	InicializarEstados();
}

void AHendrixShip::InicializarEstados()
{
	if (Vida >= 100)  
	{
		CrazyState->SetHendrix(this);
		SetState(CrazyState);
	}
	else if (Vida >= 50 && Vida < 100)
	{
		AgresiveState->SetHendrix(this);
		SetState(AgresiveState);
	}
	else 
	{
		WeakState->SetHendrix(this);
		SetState(WeakState);
	}
}

void AHendrixShip::MoveHendrix(float DeltaTime)
{
	State->Move(DeltaTime);
}

void AHendrixShip::DropHendrix()
{
	State->Drop();
}

void AHendrixShip::HideHendrix()
{
	State->Hide(); 
}

void AHendrixShip::SetState(IIHendrixState* _State)
{
		State = _State; //Cambiar el estado
}

IIHendrixState* AHendrixShip::GetCrazyState()
{
	return CrazyState;
}

IIHendrixState* AHendrixShip::GetAgresiveState()
{
	return AgresiveState;
}

IIHendrixState* AHendrixShip::GetWeakState()
{
	return WeakState;
}

IIHendrixState* AHendrixShip::GetState()
{
	return State;
}

