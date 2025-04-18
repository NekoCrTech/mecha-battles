// Developed by Neko


#include "Grid/Grid.h"

#include "Components/InstancedStaticMeshComponent.h"
#include "Grid/GridModifier.h"
#include "Utilities/UtilitiesLibrary.h"

#define ECC_GROUND ECC_GameTraceChannel1

// Sets default values
AGrid::AGrid()
{
	PrimaryActorTick.bCanEverTick = true;

	InstancedStaticMeshComponent = CreateDefaultSubobject<UInstancedStaticMeshComponent>("InstancedStaticMesh");
}


void AGrid::SpawnGrid(const FVector CenterLocation, const FVector TileSize, const FIntPoint TileCount, bool bUseEnvironment)
{
	GridCenterLocation = GetActorLocation();
	GridTileSize = TileSize;
	GridTileCount = TileCount;

	DestroyGrid();

	InstancedStaticMeshComponent->SetStaticMesh(GridShapeData.FlatMesh);
	InstancedStaticMeshComponent->SetMaterial(0, GridShapeData.FlatBorderMaterial);

	SetGridOffsetFromGround();

	CalculateCenterAndBottomLeft(GridCenterLocation, GridBottomLeftCorner);

	for (int i = 0; i < (GridTileCount.X - 1); i++)
	{
		int j = (i % 2 != 0 ? 1 : 0);
		for ( j; j < (GridTileCount.Y * 2 - 1); j++)
		{
			//FIntPoint LoopIndex = FIntPoint(i, j);
			SpawnInstance(FIntPoint(i,j), bUseEnvironment);

			j=j+1;
		}
	}
}

void AGrid::DestroyGrid()
{
	InstancedStaticMeshComponent->ClearInstances();
}

void AGrid::CalculateCenterAndBottomLeft(FVector& Center, FVector& BottomLeft)
{
	Center = UUtilitiesLibrary::SnapVectorToVector(GridCenterLocation,GridTileSize * FVector(1.5,1,1));
	
	float X = Center.X - (((GridTileCount.X - AdjustForOdd(GridTileCount.X)) / 3) * GridTileSize.X);
	float Y = Center.Y - (((GridTileCount.Y - AdjustForOdd(GridTileCount.Y)) / 2) * GridTileSize.Y);
	
	BottomLeft = Center - UUtilitiesLibrary::SnapVectorToVector(FVector((GridTileCount.X/3)*GridTileSize.X,(GridTileCount.Y/2)*GridTileSize.Y,0),GridTileSize * FVector(1.5,1,1));
	
}

FVector AGrid::GetTileLocationFromGridIndex(FIntPoint GridIndex)
{
	float X = GridBottomLeftCorner.X +(GridTileSize.X * GridIndex.X * 0.75);
	float Y = GridBottomLeftCorner.Y +(GridTileSize.Y * GridIndex.Y * 0.50);
	
	return FVector(X, Y, GridBottomLeftCorner.Z);
}

bool AGrid::TraceForGround(FVector& InLocation, FVector& HitLocation, ETileType& TileType)
{
	FVector StartLocation = FVector(InLocation.X, InLocation.Y, InLocation.Z + 1000);
	FVector EndLocation = FVector(InLocation.X, InLocation.Y, InLocation.Z - 1000);

	float Radius = GridTileSize.X / 3;

	FCollisionQueryParams TraceParams(FName(TEXT("GroundTrace")), false, this);

	TArray<FHitResult> HitResults;

	// Do the sweep (sphere trace)
	bool bHit = GetWorld()->SweepMultiByChannel(
		HitResults,
		StartLocation,
		EndLocation,
		FQuat::Identity,
		ECC_GROUND, // your custom channel
		FCollisionShape::MakeSphere(Radius),
		TraceParams
	);

	if (bHit)
	{
		for (const FHitResult& Hit : HitResults)
		{
			bool bHitSomething = false;
			if (Hit.bBlockingHit)
			{
				TileType = ETileType::Normal;
				float Z = FMath::GridSnap(Hit.ImpactPoint.Z-Radius,GridTileSize.Z);
				HitLocation = FVector(InLocation.X,InLocation.Y,Z);

				if (AGridModifier* GridModifier = Cast<AGridModifier>(Hit.GetActor()))
				{
					TileType = GridModifier->TileType;
				}

				// Debug: Draw the hit point
				// DrawDebugSphere(GetWorld(), InLocation, Radius, 12, FColor::Green, false, 2.0f);

				bHitSomething = true;
			}
			return bHitSomething;
		}
	}

	// If no hit found
	HitLocation = FVector::ZeroVector;

	// Debug: Draw the trace path
	// DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, false, 2.0f, 0, 2.0f);
	// DrawDebugSphere(GetWorld(), EndLocation, Radius, 12, FColor::Red, false, 2.0f);

	return false;
}


// Called when the game starts or when spawned
void AGrid::BeginPlay()
{
	Super::BeginPlay();
}

void AGrid::SpawnInstance(FIntPoint Index, bool bUseEnvironment)
{
	FTransform TileTransform;
	TileTransform.SetScale3D(GridTileSize/GridShapeData.MeshSize);
	FVector LocationTemp = GetTileLocationFromGridIndex(Index);

	FTileData DataTemp;
	DataTemp.Index = Index;
	
	if (bUseEnvironment)
	{
		FVector HitLocation;
		ETileType TileType = ETileType::None;
		TraceForGround(LocationTemp, HitLocation, TileType);
		DataTemp.TileType = TileType;
		TileTransform.SetTranslation(HitLocation);
		DataTemp.Transform = TileTransform;

		AddGridTile(DataTemp);
		InstancedStaticMeshComponent->AddInstance(TileTransform);
		return;
	}

	TileTransform.SetTranslation(LocationTemp);
	DataTemp.Transform = TileTransform;
	DataTemp.TileType = ETileType::Normal;
	AddGridTile(DataTemp);

	InstancedStaticMeshComponent->AddInstance(TileTransform);

}

void AGrid::AddGridTile(FTileData Data)
{
	GridTiles.Add(Data.Index, Data);
}

int32 AGrid::AdjustForOdd(int32 GridCount)
{
	return GridCount % 2 != 0 ? 1 : 0;
}

void AGrid::SetGridOffsetFromGround(float Offset)
{
	OffsetFromGround = Offset;
	InstancedStaticMeshComponent->SetWorldLocation(FVector(0,0,OffsetFromGround));
}

bool AGrid::IsTileTypeWalkable(ETileType InTileType)
{
	if (InTileType == ETileType::None || InTileType == ETileType::Obstacle) return false;
	return true;
}


// Called every frame
void AGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

