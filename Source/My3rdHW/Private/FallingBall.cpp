#include "FallingBall.h"

AFallingBall::AFallingBall()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>("SceneRoot");
	SetRootComponent(SceneRoot);
	
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComp");
	StaticMeshComp->SetupAttachment(SceneRoot);
	
	const ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Shapes/Shape_Sphere.Shape_Sphere"));
	StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	
	const ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Rock_Basalt.M_Rock_Basalt"));
	StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	
	StaticMeshComp->SetSimulatePhysics(true);
}

void AFallingBall::BeginPlay()
{
	Super::BeginPlay();
}

void AFallingBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

