// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Capsula.generated.h"

UCLASS()
class GALAGA_USFX_LAB02_API ACapsula : public AActor
{
	GENERATED_BODY()
	
public:	
	//FString TipoCapsula;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* mallaCapsula;
	// Sets default values for this actor's properties
	ACapsula();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

//	UFUNCTION()//Funcion que se llama cuando la capsula colisiona con un objeto de la escena
//	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);



	//FString GetTipoCapsula();


};
