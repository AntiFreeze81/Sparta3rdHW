#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RollingTrap.generated.h"

UCLASS()
class MY3RDHW_API ARollingTrap : public AActor
{
	GENERATED_BODY()

public:
	ARollingTrap();

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "RollingTrap|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RollingTrap|Components")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RollingTrap|Components")
	UStaticMeshComponent* StaticMeshCompLeft;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RollingTrap|Components")
	UStaticMeshComponent* StaticMeshCompRight;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RollingTrap|StartLocation")
	FVector StartLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RollingTrap|RollSpeed")
	float RollSpeed;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RollingTrap|Timer")
	float TimerRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RollingTrap|Timer")
	FTimerHandle RollTimerHandle;
	
	UFUNCTION(BlueprintCallable, Category = "RollingTrap|Functions")
	void RollTrap();
	UFUNCTION(BlueprintCallable, Category = "RollingTrap|Functions")
	float CalculateTimerRate(float InTimerRate);
	
public:
	virtual void Tick(float DeltaTime) override;
};
