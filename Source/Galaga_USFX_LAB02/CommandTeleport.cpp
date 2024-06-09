// Fill out your copyright notice in the Description page of Project Settings.


#include "CommandTeleport.h"
#include "Galaga_USFX_LAB02Pawn.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ACommandTeleport::ACommandTeleport()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACommandTeleport::BeginPlay()
{
	Super::BeginPlay();	
	Pawn = Cast<AGalaga_USFX_LAB02Pawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
}

// Called every frame
void ACommandTeleport::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACommandTeleport::Execute()
{
	Pawn->Teleport();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Teleport"));  
}

void ACommandTeleport::Undo()
{
}

