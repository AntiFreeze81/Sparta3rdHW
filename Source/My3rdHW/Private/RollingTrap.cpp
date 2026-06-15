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
	
	const ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_CobbleStone_Smooth.M_CobbleStone_Smooth"));
	StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	StaticMeshCompLeft->SetMaterial(0, MaterialAsset.Object);
	StaticMeshCompRight->SetMaterial(0, MaterialAsset.Object);
	
	RollSpeed = 90.0f;
	TimerRate = 1.0f;
	
	PrimaryActorTick.bCanEverTick = true;
}

void ARollingTrap::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();
	
	GetWorldTimerManager().SetTimer(RollTimerHandle, this, &ARollingTrap::RollTrap, CalculateTimerRate(TimerRate), true);
}

void ARollingTrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARollingTrap::RollTrap()
{
	AddActorLocalRotation(FRotator(0.0f, RollSpeed * CalculateTimerRate(TimerRate), 0.0f));	
}

float ARollingTrap::CalculateTimerRate(float InTimerRate)
{
	if (InTimerRate > 0.0f)
	{
		return 1.0f / InTimerRate;
	}
	return 1.0f;
}