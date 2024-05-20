// Fill out your copyright notice in the Description page of Project Settings.


#include "Capsula.h"
#include "Kismet/GameplayStatics.h" 
#include "Galaga_USFX_LAB02Pawn.h"  

// Sets default values
ACapsula::ACapsula()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> mallaC(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule_2.Shape_NarrowCapsule_2'")); 
	mallaCapsula = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CapsulaMesh")); 
	mallaCapsula->SetupAttachment(RootComponent);
	mallaCapsula->SetStaticMesh(mallaC.Object); 
	RootComponent = mallaCapsula;
	InitialLifeSpan = 5.0f;
	


 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACapsula::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACapsula::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//void ACapsula::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
//{
//	AGalaga_USFX_LAB02Pawn* Pawn = Cast<AGalaga_USFX_LAB02Pawn>(OtherActor);
//	if (Pawn)
//	{
//		Destroy();//Destruir la capsula
//	}
//	
//}


