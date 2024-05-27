// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaHacker.h"
#include "NaveEnemigaHackerLv1.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_LAB02_API ANaveEnemigaHackerLv1 : public ANaveEnemigaHacker
{
	GENERATED_BODY()
public:
	ANaveEnemigaHackerLv1();
	class UAComponenteMovimiento* componenteMovimiento;
	
protected:
	FString tipoNave ="hackerLv1";
public:
	// Called every frame
		virtual void Tick(float DeltaTime) override;
};
