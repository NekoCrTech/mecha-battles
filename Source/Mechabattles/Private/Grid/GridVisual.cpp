// Developed by Neko


#include "Grid/GridVisual.h"
#include "Components/ChildActorComponent.h"
#include "Components/SceneComponent.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Utilities/UtilitiesLibrary.h"

// Sets default values
AGridVisual::AGridVisual()
{
	PrimaryActorTick.bCanEverTick = false;

	Scene = CreateDefaultSubobject<USceneComponent>("Scene");
	RootComponent = Scene;

	ChildActor = CreateDefaultSubobject<UChildActorComponent>("ChildActor_GridMeshInst");
	ChildActor->SetupAttachment(Scene);

	
}

void AGridVisual::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	if (GridMeshInstClass)
	{
		ChildActor->SetChildActorClass(GridMeshInstClass);
		ChildActor->CreateChildActor();
		GridMeshInst = Cast<AGridMeshInst>(ChildActor->GetChildActor());
	}
}

void AGridVisual::BeginPlay()
{
	Super::BeginPlay();
}

void AGridVisual::InitializeGridVisual(AGrid* InGrid)
{
	if (GridMeshInst)
	{
		Grid=InGrid;
		GridMeshInst->InitializeGridMeshInst(Grid->GridShapeData, FVector::ZeroVector, ECollisionEnabled::QueryOnly);
    
		SetActorLocation(FVector(0));
		SetOffsetFromGround(OffsetFromGround);
	}
}

void AGridVisual::DestroyGridVisual() const
{
	if (!IsValid(GridMeshInst))
	{
		UE_LOG(LogTemp, Warning, TEXT("DestroyGridVisual: GridMeshInst is null"));
		return;
	}
	
	if (!IsValid(GridMeshInst->InstancedStaticMesh))
	{
		UE_LOG(LogTemp, Warning, TEXT("DestroyGridVisual: InstancedStaticMesh is null (maybe too early?)"));
		return;
	}

	GridMeshInst->ClearInstances();
}

void AGridVisual::UpdateTileVisual(FTileData TileData)
{
	if (GridMeshInst)
	{
		GridMeshInst->RemoveInstance(TileData.Index);

		if (UUtilitiesLibrary::IsTileTypeWalkable(TileData.TileType))
		{
			GridMeshInst->AddInstance(TileData.Transform, TileData.Index);
		}
	}
	
}

void AGridVisual::SetOffsetFromGround(float Offset)
{
	OffsetFromGround = Offset;
	FVector Location = GetActorLocation();
	SetActorLocation(FVector(Location.X,Location.Y,Location.Z+OffsetFromGround));
}


