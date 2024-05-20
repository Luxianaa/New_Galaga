// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AComponenteInvisible.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GALAGA_USFX_LAB02_API UAComponenteInvisible : public UActorComponent
{
	GENERATED_BODY()

public:	
	//UStaticMeshComponent* mallaNaveE;
	
	// Sets default values for this component's properties
	UAComponenteInvisible();


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	//void AparecerDesaparecerNaves(); 
	//void DesaparecerNavesEspias();
	//void MostrarNavesEspias(); 
	//FTimerHandle TiempoVisibilidad;//
};
