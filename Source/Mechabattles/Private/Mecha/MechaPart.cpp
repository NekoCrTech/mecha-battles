// Developed by Neko


#include "Mecha/MechaPart.h"


AMechaPart::AMechaPart()
{
 	
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;
	
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>("Mesh");
	Mesh->SetupAttachment(Root);

}

void AMechaPart::BeginPlay()
{
	Super::BeginPlay();
	
}


