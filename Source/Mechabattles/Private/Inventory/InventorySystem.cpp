// Developed by Neko


#include "Inventory/InventorySystem.h"

// Sets default values for this component's properties
UInventorySystem::UInventorySystem()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UInventorySystem::BeginPlay()
{
	Super::BeginPlay();

	
}

void UInventorySystem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}


