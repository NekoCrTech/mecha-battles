// Developed by Neko


#include "Mecha/MechaPartComponent.h"


UMechaPartComponent::UMechaPartComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}



void UMechaPartComponent::BeginPlay()
{
	Super::BeginPlay();
}

// AMechaPart* UMechaPartComponent::EquipPart(EEquipmentSlot InSlot, AMechaPart* InPart)
// {
// 	if (AMechaPart** ExistingPartPtr = EquippedParts.Find(InSlot))
// 	{
// 		AMechaPart* ExistingPart = *ExistingPartPtr;
// 		EquippedParts[InSlot] = InPart;
// 		return ExistingPart;
// 	}
//
// 	EquippedParts.Add(InSlot, InPart);
// 	return nullptr;
// }
//
// AMechaPart* UMechaPartComponent::UnequipPart(EEquipmentSlot InSlot)
// {
// 	if (AMechaPart** PartPtr = EquippedParts.Find(InSlot))
// 	{
// 		AMechaPart* RemovedPart = *PartPtr;
//
// 		// Set the entry to nullptr or remove it completely
// 		// Option 1: Keep the slot but set to nullptr
// 		*PartPtr = nullptr;
//
// 		// Option 2 (alternative): Remove the entry completely
// 		// EquippedParts.Remove(InSlot);
//
// 		return RemovedPart;
// 	}
//
// 	return nullptr; // Nothing was equipped in this slot
// }