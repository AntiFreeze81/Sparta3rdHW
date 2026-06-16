#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FallingBallSpawnManager.generated.h"

UCLASS()
class MY3RDHW_API AFallingBallSpawnManager : public AActor
{
	GENERATED_BODY()

public:
	AFallingBallSpawnManager();

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="FallingBallSpawnManager|Components")
	USceneComponent* SceneRoot;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FallingBallSpawnManager|SpawnClass")
	TSubclassOf<AActor> FallingBallSpawn;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FallingBallSpawnManager|Timer")
	FTimerHandle SpawnTimerHandle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FallingBallSpawnManager|Timer")
	float TimerRate;
	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FallingBallSpawnManager|SpawnRange")
	float MinX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FallingBallSpawnManager|SpawnRange")
	float MaxX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FallingBallSpawnManager|SpawnRange")
	float MinY;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FallingBallSpawnManager|SpawnRange")
	float MaxY;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FallingBallSpawnManager|SpawnRange")
	float SpawnZ;
	
	UFUNCTION(BlueprintCallable, Category="FallingBallSpawnManager|Functions")
	float CalculateTimerRate(float InTimerRate);
	UFUNCTION(BlueprintCallable, Category="FallingBallSpawnManager|Functions")
	void SpawnBallRandomLocation();
public:
	virtual void Tick(float DeltaTime) override;
};
