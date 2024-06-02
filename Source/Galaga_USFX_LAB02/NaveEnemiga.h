// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AComponenteMovimiento.h"
#include "IStrategy.h"
#include "NaveEnemiga.generated.h"


UCLASS(Abstract)
class GALAGA_USFX_LAB02_API ANaveEnemiga : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* mallaNaveEnemiga; // Malla de la nave enemiga	

protected:
	int caca;
	float velocidad;
	float velocidadDisparo;
	float resistencia;
	float danoProducido;
	float valorDestruccion;
	float recompensa;
	float energia;
	float tiempoDisparo;
	float tiempoReaparicion;
	FString nombre;
	FVector posicion;
	FVector ubicacionActual;
	float Radio ; // Radio de la circunferencia
	float Angulo; // Ángulo inicial
	float Speed ; // Velocidad de rotación

	UAComponenteMovimiento* MovimientoNavesComponent; 


	UPROPERTY(Category = Audio, EditAnywhere, BlueprintReadWrite)
	class USoundBase* FireSound; 
	int Vida;
	
public:	
	// Sets default values for this actor's properties
	ANaveEnemiga();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	
	float FireRate;
	FTimerHandle FireTimerHandle;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void FireProjectile();
	virtual void ReceiveDamage() PURE_VIRTUAL(ANaveEnemiga::ReceiveDamage, );

private:
	IIStrategy* Strategy;
	FTimerHandle ChangeHandle;
	//void ChangeStrategy();
	//float IntervaloCambio= 5.0f;

public:
	 
	//void SetStrategy(IIStrategy* _Strategy); 
	/*void AlterarEstrategia(AActor* _StrategyElegida);
	void UsarEstrategia(float DeltaTime);*/

};
