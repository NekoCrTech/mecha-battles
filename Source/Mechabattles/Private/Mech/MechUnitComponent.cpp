// Developed by Neko


#include "Mech/MechUnitComponent.h"

#include "Mech/EquipmentItem.h"

UMechUnitComponent::UMechUnitComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FMechStats UMechUnitComponent::GetTotalStats() const
{
	FMechStats Total = BaseStats;

	for (const auto& Pair : EquippedItems)
	{
		if (Pair.Value)
		{
			FMechStats Bonus = Pair.Value->GetModifiedStats();
			Total.Power   += Bonus.Power;
			Total.Armor   += Bonus.Armor;
			Total.Speed   += Bonus.Speed;
			Total.Energy  += Bonus.Energy;
		}
	}

	return Total;
}

bool UMechUnitComponent::EquipItem(EMechSlot Slot, UEquipmentItem* Item)
{
	if (!Item || !Item->Template) return false;

	// Check slot type matches
	if (Item->Template->SlotType != Slot)
	{
		UE_LOG(LogTemp, Warning, TEXT("Item does not match target slot!"));
		return false;
	}

	// Equip (override if needed)
	EquippedItems.Add(Slot, Item);
	return true;
}

bool UMechUnitComponent::ScrapItem(UEquipmentItem* Item, int32& OutScrapValue)
{
	OutScrapValue = 0;
	if (!Item) return false;

	// Check if equipped, remove it
	for (auto& Pair : EquippedItems)
	{
		if (Pair.Value == Item)
		{
			EquippedItems.Remove(Pair.Key);
			break;
		}
	}

	// Return value and destroy item
	OutScrapValue = Item->GetScrapValue();
	
	return true;
}

UEquipmentItem* UMechUnitComponent::GetEquippedItem(EMechSlot Slot) const
{
	return EquippedItems.Contains(Slot) ? EquippedItems[Slot] : nullptr;
}

void UMechUnitComponent::BeginPlay()
{
	Super::BeginPlay();
		
}


