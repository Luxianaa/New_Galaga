// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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
private:
//	UPROPERTY(VisibleAnywhere, Category = "Publisher")
	TArray<AActor*> Subscribers;

	class IISubscriber* ISubscriber;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Subscribe(AActor* _Subscriber);
	virtual void Unsubscribe(AActor* _Subscriber);
	virtual void NotifySubscribers();


};
