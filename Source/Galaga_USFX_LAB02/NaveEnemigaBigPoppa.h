// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaBigPoppa.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_LAB02_API ANaveEnemigaBigPoppa : public ANaveEnemiga
{
	GENERATED_BODY()
public:

	ANaveEnemigaBigPoppa();

	class UAComponenteMovimiento* componenteMovimiento;
public:
	virtual void Tick(float DeltaTime) override;
protected:
	FString tipoNave="BigPoppa";



	
};
