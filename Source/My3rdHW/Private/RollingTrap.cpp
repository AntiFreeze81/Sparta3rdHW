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
	
	const ConstructorHelpers::FObjectFinder<UStaticMesh> CenterMeshAsset(TEXT("/Game/Resources/Shapes/Shape_Cylinder.Shape_Cylinder"));
	StaticMeshComp->SetStaticMesh(CenterMeshAsset.Object);
	
	const ConstructorHelpers::FObjectFinder<UStaticMesh> SideMeshAsset(TEXT("/Game/Resources/Shapes/Shape_Pipe.Shape_Pipe"));
	StaticMeshCompLeft->SetStaticMesh(SideMeshAsset.Object);
	StaticMeshCompRight->SetStaticMesh(SideMeshAsset.Object);
	
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

