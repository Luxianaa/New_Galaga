// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ICommand.h"
#include "Invoker.generated.h"

UCLASS()
class GALAGA_USFX_LAB02_API AInvoker : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInvoker();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	class IICommand* Command;
public:
	void SetCommand(AActor* NewCommand);
	void ExecuteCommand();
	void UndoCommand();
};
