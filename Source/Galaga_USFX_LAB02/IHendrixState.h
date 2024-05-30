// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IHendrixState.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIHendrixState : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GALAGA_USFX_LAB02_API IIHendrixState
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual void Move() = 0;
	virtual void ShootTriple() = 0;
	virtual void ChangeMesh() = 0;
	virtual void Hide() = 0;

	virtual void SetHendrix(class AMotherShipHendrix* Hendrix) = 0;

};
