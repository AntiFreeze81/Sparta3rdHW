// Fill out your copyright notice in the Description page of Project Settings.


#include "My3rdHW/Public/MovingFloor.h"


// Sets default values
AMovingFloor::AMovingFloor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingFloor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMovingFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

