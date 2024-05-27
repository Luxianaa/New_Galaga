//// Fill out your copyright notice in the Description page of Project Settings.


#include "Publisher.h"
#include "ISubscriber.h"

APublisher::APublisher()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APublisher::BeginPlay()
{
	Super::BeginPlay();
}

void APublisher::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APublisher::Subscribe(AActor* _Subscriber)
{
	Subscribers.Add(_Subscriber);
}

void APublisher::Unsubscribe(AActor* _Subscriber)
{
		Subscribers.Remove(_Subscriber);
}

void APublisher::NotifySubscribers()
{
	for (AActor* Sub : Subscribers)
	{
		IISubscriber* Subcriber = Cast<IISubscriber>(Sub);  
		if (Subcriber)
		{
			Subcriber->Update(this); 
		}
	}	

}
