// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Capsula.h"
#include "FactoryCapsula.generated.h"

UCLASS()
class GALAGA_USFX_LAB02_API AFactoryCapsula : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	//AFactoryCapsula();
	//virtual void Mostrar() = 0; 
	UFUNCTION(BlueprintCallable, Category = "FabricaCapsulas")
	static ACapsula* GenerarCapsulas(FString tipoCapsula, UWorld* World, FVector SpawnLocation, FRotator ZeroRotator); //Factory Method
	//llamar sin crear obj  
	// 
	//virtual ACapsula* GenerarCapsulas(FString tipoCapsula, UWorld* world, )
	//PURE_VIRTUAL(AFactoryCapsula::GenerarCapsulas, return nullptr;); 

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	FTimerHandle SpawnTimerHandle; 
};
