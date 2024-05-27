// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaEspiaLv1.h"
#include "AComponenteMovimiento.h"

ANaveEnemigaEspiaLv1::ANaveEnemigaEspiaLv1()
{
    PrimaryActorTick.bCanEverTick = true;

    componenteMovimiento = CreateDefaultSubobject<UAComponenteMovimiento>(TEXT("ComponenteMovimiento"));


}

void ANaveEnemigaEspiaLv1::Tick(float DeltaTime)
{
    Super ::Tick(DeltaTime); 

    
} 
