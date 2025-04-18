// Developed by Neko


#include "Mech/EquipmentItem.h"

FMechStats UEquipmentItem::GetModifiedStats() const
{
	if (!Template) return FMechStats();

	FMechStats Result = Template->BaseStatBonus;

	Result.Power   += UpgradeLevel * 2;
	Result.Armor   += UpgradeLevel * 2;
	Result.Speed   += UpgradeLevel * 1;
	Result.Energy  += UpgradeLevel * 3;

	// Tweak formula later
	return Result;
}

int32 UEquipmentItem::GetScrapValue() const
{
	if (!Template) return 0;
	return Template->BaseScrapValue + (UpgradeLevel * 5);
}

bool UEquipmentItem::Upgrade()
{
	if (!Template) return false;
	if (UpgradeLevel >= Template->MaxUpgradeLevel)
		return false;

	UpgradeLevel++;
	return true;
}
