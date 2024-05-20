// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaCazaLv1.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_LAB02_API ANaveEnemigaCazaLv1 : public ANaveEnemigaCaza
{
	GENERATED_BODY()
public:
		ANaveEnemigaCazaLv1();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Tick(float DeltaTime) override;

	FString tipoNave = "CazaLv1";
};
