#include "My3rdHW/Public/MovingFloor.h"

AMovingFloor::AMovingFloor()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>("SceneRoot");
	SetRootComponent(SceneRoot);
	
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComp");
	StaticMeshComp->SetupAttachment(SceneRoot);
	
	const ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Shapes/Shape_Cube.Shape_Cube"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}
	
	const ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Concrete_Tiles.M_Concrete_Tiles"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}
	
	MoveSpeed = 150.0f;
	MaxRange = 1500.0f;
	TotalDistance = 0.0f;
	TimerRate = 1.0f;
	
	PrimaryActorTick.bCanEverTick = true;
}

void AMovingFloor::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();
	
	TimerRate = CalculateTimerRate(TimerRate);
	
	GetWorldTimerManager().SetTimer(MoveTimerHandle, this, &AMovingFloor::MoveForwardAndBack, TimerRate, true);
}

void AMovingFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMovingFloor::MoveForwardAndBack()
{
	if (FMath::FloorToInt32(TotalDistance / MaxRange) & 1)
	{
		AddActorWorldOffset(FVector(0.0f, MoveSpeed * TimerRate, 0.0f));
	}
	else
	{
		AddActorWorldOffset(FVector(0.0f, -(MoveSpeed * TimerRate), 0.0f));
	}
	TotalDistance += MoveSpeed * TimerRate;
}

float AMovingFloor::CalculateTimerRate(float InTimerRate)
{
	if (InTimerRate > 0)
	{
		return 1.0f / InTimerRate;
	}
	return 1.0f;
}