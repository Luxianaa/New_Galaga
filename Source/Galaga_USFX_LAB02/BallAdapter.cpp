// Fill out your copyright notice in the Description page of Project Settings.


#include "BallAdapter.h"
#include "Ball.h"

// Sets default values
ABallAdapter::ABallAdapter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABallAdapter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABallAdapter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



