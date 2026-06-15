#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingFloor.generated.h"

UCLASS()
class MY3RDHW_API AMovingFloor : public AActor
{
	GENERATED_BODY()

public:
	AMovingFloor();

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MovingFloor|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingFloor|Components")
	UStaticMeshComponent* StaticMeshComp;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingFloor|StartLocation")
	FVector StartLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingFloor|MoveSpeed")
	float MoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingFloor|MaxRange")
	float MaxRange;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MovingFloor|TotalDistance")
	float TotalDistance;
	
	UFUNCTION(BlueprintCallable, Category = "MovingFloor|Functions")
	void MoveForwardAndBack();
	UFUNCTION(BlueprintCallable, Category = "MovingFloor|Functions")
	float CalculateTimerRate(float InTimerRate);
	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingFloor|Timer")
	float TimerRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingFloor|Timer")
	FTimerHandle MoveTimerHandle;
	
public:
	virtual void Tick(float DeltaTime) override;
};
