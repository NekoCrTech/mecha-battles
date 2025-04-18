// Developed by Neko


#include "Grid/GridModifier.h"
#include "Utilities/UtilitiesLibrary.h"

#define ECC_GROUND ECC_GameTraceChannel1

// Sets default values
AGridModifier::AGridModifier()
{
	PrimaryActorTick.bCanEverTick = false;
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	StaticMeshComponent->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void AGridModifier::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGridModifier::SetGridModifier()
{
	if (ModifierMesh)
	{
		StaticMeshComponent->SetStaticMesh(ModifierMesh);
		if (ModifierMaterial)
		{
			StaticMeshComponent->SetMaterial(0, ModifierMaterial);
		}
	}
	StaticMeshComponent->SetVectorParameterValueOnMaterials("Color", UUtilitiesLibrary::GetColorByTileType(TileType));
	//StaticMeshComponent->SetCollisionResponseToChannels(ECR_Ignore);
	StaticMeshComponent->SetCollisionResponseToChannel(ECC_GROUND, ECR_Overlap);
	AGridModifier::SetActorHiddenInGame(true);
}


