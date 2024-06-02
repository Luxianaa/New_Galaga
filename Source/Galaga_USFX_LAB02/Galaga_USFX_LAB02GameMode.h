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
	//---------------------------
	float Time;  
	class AStrategyStraight* StrategyStraight; 
};



