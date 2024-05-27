// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaTransporteLv1.h"
#include "AComponenteMovimiento.h"

ANaveEnemigaTransporteLv1::ANaveEnemigaTransporteLv1()
{
	componenteMovimiento = CreateDefaultSubobject<UAComponenteMovimiento>(TEXT("ComponenteMovimiento"));
}

void ANaveEnemigaTransporteLv1::Tick(float DeltaTime)
{
		Super::Tick(DeltaTime);
}
