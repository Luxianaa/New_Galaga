// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Galaga_USFX_LAB02GameMode.generated.h"

UCLASS(MinimalAPI)
class AGalaga_USFX_LAB02GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	AGalaga_USFX_LAB02GameMode();
protected:

	virtual void BeginPlay() override;	
public:
	virtual void Tick(float DeltaTime) override;

protected:

	UPROPERTY(VisibleAnywhere, Category = "Adapter")
	class ABallAdapter* Adaptader;
	/*UPROPERTY(VisibleAnywhere, Category = "Pawn")
	class AGalaga_USFX_L02Pawn* Pawn;*/ 



	UPROPERTY(VisibleAnywhere, Category = "ShieldMotherShip")
	class AShieldMotherShip* ShieldMotherShip;
	UPROPERTY(VisibleAnywhere, Category = "NasMotherShip")
	class ANasMotherShip* NasMotherShip;
	UPROPERTY(VisibleAnywhere, Category = "DoomMotherShip")
	class ADoomMotherShip* DoomMotherShip;
	UPROPERTY(VisibleAnywhere, Category = "MotherDirector")
	class AMotherDirector* MotherDirector;

	UPROPERTY(VisibleAnywhere, Category = "FacadeShip")
	class AFacadeShip* FacadeShip;
	FTimerHandle SpawnTimerHandle;
	//--------------------------
	class AMoon* Moon; //obs
	class AShipYorke* ShipYorke;//sub
	class APublisher* Publisher;
	class AHendrixShip* HendrixShip;
	class AShipRager* ShipRager;
	//---------------------------Strategy
	float Tiempo;  
	class AStrategyStraight* StrategyStraight;
	class AStrategyCrazy* StrategyCrazy;
	class AStrategyAlly* StrategyAlly; 
	class ANavePruebas* NavePrueba;
	class ANaveEnemiga * NaveEnemiga;

	class AGalaga_USFX_LAB02Pawn* Pawn;
	//-------------------------------------------------------------

	UPROPERTY(EditAnywhere, Category = "GameModeBase") 
	class AInvoker* Invoker;
	UPROPERTY(EditAnywhere, Category = "GameModeBase") 
	class AShipPatrol* Receptor;
	UPROPERTY(EditAnywhere, Category = "GameModeBase") 
	class ACommadDrop* CommandDrop;
	UPROPERTY(EditAnywhere, Category = "GameModeBase")
	class ACommandMove* CommandMove;
	UPROPERTY(EditAnywhere, Category = "GameModeBase")
	class ACommandTeleport* CommandTeleport;
	UPROPERTY(EditAnywhere, Category = "GameModeBase")
	class ACommandBomber* CommandBomber;
	UPROPERTY(EditAnywhere, Category = "GameModeBase")
	class ACommandDestruction* CommandDestruction;

//-------------------------------
	void ExecuteCommandDrop();
	void ExecuteCommandMove();
	void ExecuteCommandTeleport(); 
	void ExecuteCommandBomber();
	void DeshacerComando(); 
//--------------------------------

	class IICommand* UltimoComando;
	TArray<IICommand*> Comandos;      
	FTimerHandle TimerHandle;
	float temp;
};



