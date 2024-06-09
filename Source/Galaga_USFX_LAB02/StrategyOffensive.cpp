// Fill out your copyright notice in the Description page of Project Settings.


#include "StrategyOffensive.h"
#include "Galaga_USFX_LAB02Pawn.h" 
#include "Kismet/GameplayStatics.h" 

// Sets default values
AStrategyOffensive::AStrategyOffensive()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStrategyOffensive::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStrategyOffensive::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); 

}

void AStrategyOffensive::MoveFireHide()
{
	Pawn = Cast<AGalaga_USFX_LAB02Pawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	Pawn->MoveSpeed = +3000.0f; 
	Pawn->FireRate = 0.1f; 
	Pawn->Teleport2(); 

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Offensive Strategy On"));
}

