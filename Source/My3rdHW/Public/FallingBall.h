#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FallingBall.generated.h"

UCLASS()
class MY3RDHW_API AFallingBall : public AActor
{
	GENERATED_BODY()

public:
	AFallingBall();

protected:
	virtual void BeginPlay() override;
	
public:
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "FallingBall|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FallingBall|Components")
	UStaticMeshComponent* StaticMeshComp;
};
