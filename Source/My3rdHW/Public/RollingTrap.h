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
	
public:
	virtual void Tick(float DeltaTime) override;
};
