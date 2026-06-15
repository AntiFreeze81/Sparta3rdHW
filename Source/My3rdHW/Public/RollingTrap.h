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
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MovingFloor|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingFloor|Components")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingFloor|Components")
	UStaticMeshComponent* StaticMeshCompLeft;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingFloor|Components")
	UStaticMeshComponent* StaticMeshCompRight;
	
public:
	virtual void Tick(float DeltaTime) override;
};
