// Fill out your copyright notice in the Description page of Project Settings.
#pragma once 

#include "Sun.h"

ASun::ASun()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASun::BeginPlay()
{
	Super::BeginPlay();
}

void ASun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//NotifySubscribers();
}
