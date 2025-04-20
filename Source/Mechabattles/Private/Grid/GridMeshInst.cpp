// Developed by Neko


#include "Grid/GridMeshInst.h"

#include "Components/InstancedStaticMeshComponent.h"

AGridMeshInst::AGridMeshInst()
{
	PrimaryActorTick.bCanEverTick = false;

	InstancedStaticMesh = CreateDefaultSubobject<UInstancedStaticMeshComponent>("InstancedStaticMesh");
	SetRootComponent(InstancedStaticMesh);

}

void AGridMeshInst::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGridMeshInst::AddInstance(FTransform Transform, FIntPoint Index)
{
	RemoveInstance(Index);
	InstancedStaticMesh->AddInstance(Transform);
	InstanceIndexes.Add(Index);
}

void AGridMeshInst::RemoveInstance(FIntPoint IndexToRemove)
{
	if (InstanceIndexes.Contains(IndexToRemove))
	{
		InstancedStaticMesh->RemoveInstance(InstanceIndexes.Find(IndexToRemove));
		InstanceIndexes.Remove(IndexToRemove);
	}
}

void AGridMeshInst::ClearInstances()
{
	InstancedStaticMesh->ClearInstances();
	InstanceIndexes.Empty();
}


void AGridMeshInst::InitializeGridMeshInst(FGridShapeData GridShapeData, FVector Color, ECollisionEnabled::Type Collision)
{
	if (InstancedStaticMesh)
	{
		InstancedStaticMesh->SetStaticMesh(GridShapeData.FlatMesh);
		InstancedStaticMesh->SetMaterial(0, GridShapeData.FlatMaterial);
		InstancedStaticMesh->SetVectorParameterValueOnMaterials("Color", Color);
		InstancedStaticMesh->SetCollisionEnabled(Collision);
	}
}

