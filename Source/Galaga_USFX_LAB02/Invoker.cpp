// Fill out your copyright notice in the Description page of Project Settings.


#include "Invoker.h"
#include "ICommand.h"


// Sets default values
AInvoker::AInvoker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AInvoker::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AInvoker::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AInvoker::SetCommand(IICommand* NewCommand)
{
	Command = NewCommand;
}

void AInvoker::ExecuteCommand()
{
	Command->Execute();
}

void AInvoker::UndoCommand()
{
	Command->Undo();
}

