// Developed by Neko


#include "Mecha/MechaActor.h"

// Sets default values
AMechaActor::AMechaActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMechaActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMechaActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

