// Fill out your copyright notice in the Description page of Project Settings.


#include "ShipRager.h"
#include "CapsulaCrazy.h"
#include "ProyectilEnemigo.h"
#include "FacadeShip.h"

// Sets default values
AShipRager::AShipRager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> mallaRage(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO_3.TwinStickUFO_3'"));
	RageMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshPrope"));
	RageMesh->SetupAttachment(RootComponent);
	RageMesh->SetStaticMesh(mallaRage.Object);
    RootComponent = RageMesh;
	//SetActorScale3D(FVector(20.5f, 20.5f, 20.5f));
    SetActorScale3D(FVector(3.0f, 3.0f,3.0f)); 
	bIsActive = false;
	TimeAlive = 0.0f;
	MovementSpeed = 2000.0f;
    FireRate = 0.5f;//Cadencia Balas
}

// Called when the game starts or when spawned
void AShipRager::BeginPlay()
{
	Super::BeginPlay();
    // Spawn the FacadeShip and ensure it is successfully created

    // Guarda la posici�n inicial
    InitialLocation = GetActorLocation();

    // Llama a la funci�n para activar la nave (puedes cambiar c�mo y cu�ndo se activa seg�n tus necesidades)
    bIsActive = true;

    // Mueve la nave al punto de inicio
    SetActorLocation(InitialLocation);

    // Guarda el punto final (el punto de inicio en el lado opuesto del escenario)
    FinalLocation = FVector(InitialLocation.X , InitialLocation.Y * -1.0f, InitialLocation.Z);

   GetWorld()->GetTimerManager().SetTimer(FireTimerHandle, this, &AShipRager::Shoot, FireRate, true);
 //  GetWorld()->GetTimerManager().SetTimer(MoveTimerHandle, this, &AShipRager::Move, 1.0f, true); 

 
}

// Called every frame
void AShipRager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    if (bIsActive)
    {
        // Mueve y dispara la nave mientras est� activa
        Move();

        // Incrementa el tiempo vivo
        TimeAlive += DeltaTime;

        // Despawnea la nave despu�s de cierto tiempo (puedes cambiar esto seg�n tus necesidades)
        if (TimeAlive > 10.0f)
        {
            Despawn();
        }
    }
}

void AShipRager::Move()
{
    if (!bReachedMiddle)
    {
        // Calcula la distancia al punto medio
        FVector CurrentLocation = GetActorLocation();
        FVector Midpoint = (InitialLocation + FinalLocation) * 0.5f;
        float DistanceToMidpoint = FVector::Dist(CurrentLocation, Midpoint);

        // Si la nave no est� cerca del punto medio, mueve hacia all�
        if (DistanceToMidpoint > 5.0f) // Puedes ajustar este valor seg�n la distancia que desees
        {
            FVector Direction = (Midpoint - CurrentLocation).GetSafeNormal();
            SetActorLocation(CurrentLocation + Direction * MovementSpeed * GetWorld()->GetDeltaSeconds());
        }
        else
        {
            // La nave ha alcanzado el punto medio
            bReachedMiddle = true;
            TimeAtMiddle = 3.0f; // Reinicia el tiempo en el punto medio
        }
    }
    else
    {
        // Si la nave ya alcanz� el punto medio
        TimeAtMiddle += GetWorld()->GetDeltaSeconds();

        // Si la nave ha pasado suficiente tiempo en el punto medio, mueve hacia el punto final
        if (TimeAtMiddle > 8.0f) // Cambia este valor seg�n el tiempo que quieras que la nave permanezca en el punto medio
        {
            FVector CurrentLocation = GetActorLocation();
            float DistanceToFinal = FVector::Dist(CurrentLocation, FinalLocation);
            if (DistanceToFinal > 3.0f) // Puedes ajustar este valor seg�n la distancia que desees
            {
                FVector Direction = (FinalLocation - CurrentLocation).GetSafeNormal();
                SetActorLocation(CurrentLocation + Direction * MovementSpeed * GetWorld()->GetDeltaSeconds());
            }
            else
            {
                // La nave ha llegado al punto final, despawn�ala
                Despawn();
            }
        }
    }
}

void AShipRager::Despawn()
{
    bIsActive = false;
    SetActorLocation(InitialLocation);
    TimeAlive = 0.0f;
    PrimaryActorTick.bCanEverTick = false; 
}

void AShipRager::Shoot()
{
    ACapsulaCrazy* Crazy = GetWorld()->SpawnActor<ACapsulaCrazy>(ACapsulaCrazy::StaticClass(), GetActorLocation(), GetActorRotation());
    if(Crazy)
    {
        // Obt�n la direcci�n hacia adelante de la nave enemiga
        FVector ForwardDirection = GetActorForwardVector();

        // Calcula la rotaci�n basada en la direcci�n hacia adelante
        FRotator SpawnRotation = ForwardDirection.Rotation();

        // Configura la posici�n y direcci�n del proyectil
        FVector SpawnLocation = GetActorLocation();
        Crazy->SetActorLocationAndRotation(SpawnLocation, SpawnRotation);
        // Dispara el proyectil
        Crazy->FireCpasule(); 
    }
}

