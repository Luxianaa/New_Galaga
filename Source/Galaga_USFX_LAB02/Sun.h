// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Publisher.h"
#include "Sun.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_LAB02_API ASun : public APublisher
{
	GENERATED_BODY()
	
public: 
	ASun();

protected:

	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;



};
