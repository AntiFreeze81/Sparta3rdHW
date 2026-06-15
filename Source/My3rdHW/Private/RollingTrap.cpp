#include "RollingTrap.h"

ARollingTrap::ARollingTrap()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>("SceneRoot");
	SetRootComponent(SceneRoot);
	
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComp");
	StaticMeshComp->SetupAttachment(SceneRoot);
	
	StaticMeshCompLeft = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshCompLeft");
	StaticMeshCompLeft->SetupAttachment(StaticMeshComp);
	
	StaticMeshCompRight = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshCompRight");
	StaticMeshCompRight->SetupAttachment(StaticMeshComp);
	
	
	
	PrimaryActorTick.bCanEverTick = true;
}

void ARollingTrap::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARollingTrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

