// Fill out your copyright notice in the Description page of Project Settings.



#include "AComponenteInvisible.h"
//#include "NaveEnemiga.h"

// Sets default values for this component's properties
UAComponenteInvisible::UAComponenteInvisible()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}
 


// Called when the game starts
void UAComponenteInvisible::BeginPlay()
{
	Super::BeginPlay();
	//mallaNaveEnemiga = Cast<UStaticMeshComponent>(GetOwner()->GetComponentByClass(UStaticMeshComponent::StaticClass()));


		//accede a la clase NE para conseguir puntero de malla
	//mallaNaveE = Cast<UStaticMeshComponent>(GetOwner()->GetComponentByClass(UStaticMeshComponent::StaticClass()));//

	//establecer el temporizador para las naves en 5segundos
	//GetWorld()->GetTimerManager().SetTimer(TiempoVisibilidad, this, &UAComponenteInvisible::AparecerDesaparecerNavesEspias, 2.0f, true);
}



// Called every frame
void UAComponenteInvisible::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

//void UAComponenteInvisible::AparecerDesaparecerNavesEspias()
//{
//
//	if (mallaNaveE)//verificar
//	{
//		// Decide aleatoriamente si la nave debe ser invisible
//		bool Desaparecer = FMath::RandBool();
//
//		// Cambia la visibilidad de la malla aleatoriamente
//		mallaNaveE->SetVisibility(!Desaparecer);
//	}
//}
