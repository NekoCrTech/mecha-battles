// Developed by Neko


#include "Grid/Grid.h"
#include "Grid/GridModifier.h"
#include "Grid/GridVisual.h"
#include "Grid/GridMeshInst.h"
#include "Components/ChildActorComponent.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Utilities/UtilitiesLibrary.h"

#define ECC_GROUND ECC_GameTraceChannel1

// Sets default values
AGrid::AGrid()
{
	PrimaryActorTick.bCanEverTick = true;
	
	ChildActorGridVisual = CreateDefaultSubobject<UChildActorComponent>("ChildActorGridVisual");
}

void AGrid::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	if (GridVisualClass)
	{
		ChildActorGridVisual->SetChildActorClass(GridVisualClass);
		GridVisual = Cast<AGridVisual>(ChildActorGridVisual->GetChildActor());
	}
}


void AGrid::SpawnGrid(const FVector CenterLocation, const FVector TileSize, const FIntPoint TileCount, bool bUseEnvironment)
{
	if (!ChildActorGridVisual)
	{
		UE_LOG(LogTemp, Error, TEXT("ChildActorGridVisual is nullptr!"));
		return;
	}

	
	if (!GridVisual)
	{
		UE_LOG(LogTemp, Warning, TEXT("GridVisual not yet spawned — calling CreateChildActor()"));
		ChildActorGridVisual->CreateChildActor();
		GridVisual = Cast<AGridVisual>(ChildActorGridVisual->GetChildActor());
	
		if (!GridVisual)
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to create child actor."));
			return;
		}
	}
	
	
	GridCenterLocation = CenterLocation;
	GridTileSize = TileSize;
	GridTileCount = TileCount;
	
	DestroyGrid();
	
	GridVisual->InitializeGridVisual(this);
	
	CalculateCenterAndBottomLeft(GridCenterLocation, GridBottomLeftCorner);
	
	for (int i = 0; i < (GridTileCount.X - 1); i++)
	{
		int j = (i % 2 != 0 ? 1 : 0);
		for ( j; j < (GridTileCount.Y * 2 - 1); j++)
		{
			SpawnInstance(FIntPoint(i,j), bUseEnvironment);
	
			j=j+1;
		}
	}
}

void AGrid::DestroyGrid()
{
	GridTiles.Empty();
	
	GridVisual->DestroyGridVisual();
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

	//SpawnGrid(GridCenterLocation,GridTileSize,GridTileCount,true);
}

void AGrid::GetCursorLocationOnGrid()
{
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
		return;
	}
	
	TileTransform.SetTranslation(LocationTemp);
	DataTemp.Transform = TileTransform;
	DataTemp.TileType = ETileType::Normal;
	AddGridTile(DataTemp);
}

void AGrid::AddGridTile(FTileData Data)
{
	GridTiles.Add(Data.Index, Data);
	GridVisual->UpdateTileVisual(Data);
}

int32 AGrid::AdjustForOdd(int32 GridCount)
{
	return GridCount % 2 != 0 ? 1 : 0;
}

// Called every frame
void AGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



