// Fill out your copyright notice in the Description page of Project Settings.


#include "StrategyDeluxe.h"
#include "Galaga_USFX_LAB02Pawn.h"
#include "Kismet/GameplayStatics.h"
//#include "MyGalaga_USFX_LAB02Bomb.h"
// Sets default values
AStrategyDeluxe::AStrategyDeluxe()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStrategyDeluxe::BeginPlay()
{
	Super::BeginPlay();
	bIsHidden = false; 
}

// Called every frame
void AStrategyDeluxe::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AStrategyDeluxe::ExecuteStrategy()
{
	Pawn = Cast<AGalaga_USFX_LAB02Pawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));     
	bIsHidden = !bIsHidden;  
	if(bIsHidden) 
	{ 
		Pawn->SetActorHiddenInGame(true); 
		Pawn->SetActorEnableCollision(false);  
		UE_LOG(LogTemp, Warning, TEXT("Pawn is now hidden")); 
		/*bool Desaparecer = FMath::RandBool();   
		Pawn->SetActorHiddenInGame(!Desaparecer);   */
	}
}

