// Fill out your copyright notice in the Description page of Project Settings.


#include "FallingBallSpawnManager.h"


// Sets default values
AFallingBallSpawnManager::AFallingBallSpawnManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AFallingBallSpawnManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFallingBallSpawnManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

