#include "FallingBallSpawnManager.h"

#include "FallingBall.h"

AFallingBallSpawnManager::AFallingBallSpawnManager()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>("SceneRoot");
	SetRootComponent(SceneRoot);
	
	FallingBallSpawn = nullptr;
	
	TimerRate = 1.0f;
	MinX = -300.0f;
	MaxX = 2500.0f;
	MinY = -2200.0f;
	MaxY = -1100.0f;
	SpawnZ = 1500.0f;
	
	PrimaryActorTick.bCanEverTick = false;
}

void AFallingBallSpawnManager::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &AFallingBallSpawnManager::SpawnBallRandomLocation, CalculateTimerRate(TimerRate), true);
}

void AFallingBallSpawnManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

float AFallingBallSpawnManager::CalculateTimerRate(float InTimerRate)
{	
	if (InTimerRate > 0.0f)
	{
		return InTimerRate;
	}
	return 1.0f;
	
}

void AFallingBallSpawnManager::SpawnBallRandomLocation()
{
	if (FallingBallSpawn == nullptr)
	{
		return;
	}
	
	float RandomX = FMath::RandRange(MinX, MaxX);
	float RandomY = FMath::RandRange(MinY, MaxY);
	
	FVector SpawnLocation = FVector(RandomX, RandomY, SpawnZ);
	FRotator SpawnRotation = FRotator::ZeroRotator;
	
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	
	AActor* NewBall = GetWorld()->SpawnActor<AActor>(
		FallingBallSpawn,
		SpawnLocation,
		SpawnRotation,
		SpawnParams
	);
	
	if (NewBall)
	{
		NewBall->SetLifeSpan(10.0f);
	}
}
