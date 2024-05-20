// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaCazaLv1.h"

ANaveEnemigaCazaLv1::ANaveEnemigaCazaLv1()
{
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> malla(TEXT("StaticMesh'/Game/TwinStick/Meshes/CazaLvl1.CazaLvl1'"));
	//mallaNaveEnemiga->SetStaticMesh(malla.Object);// Cargamos la malla de la nave enemiga
	////VelocidadEntrada = 50.0f; //
	////Radio = 2.0f;// dio de la circunferencia
	////Angulo = 0.0f; // Ángulo inicial
	////Speed = 3.0f;
}

void ANaveEnemigaCazaLv1::BeginPlay()
{
		Super::BeginPlay();
}

void ANaveEnemigaCazaLv1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); 

}
