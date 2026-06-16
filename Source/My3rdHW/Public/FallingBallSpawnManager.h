// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FallingBallSpawnManager.generated.h"

UCLASS()
class MY3RDHW_API AFallingBallSpawnManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFallingBallSpawnManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
