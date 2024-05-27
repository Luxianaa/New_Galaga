// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaHackerLv1.h"
#include "AComponenteMovimiento.h"

ANaveEnemigaHackerLv1::ANaveEnemigaHackerLv1()
{
	componenteMovimiento = CreateDefaultSubobject<UAComponenteMovimiento>(TEXT("ComponenteMovimiento"));
}

void ANaveEnemigaHackerLv1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
