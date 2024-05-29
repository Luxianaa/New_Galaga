// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IObserver.h"
#include "Publisher.generated.h"

UCLASS()
class GALAGA_USFX_LAB02_API APublisher : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APublisher();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	class AMoon* Moon;
private:
	TArray<IIObserver*> Observers;
public:
	void AddObserver(IIObserver* Observer);
	void RemoveObserver(IIObserver* Observer);
	void NotifyObservers();
	void ObserveMoon(class AMoon* _Moon);

};
