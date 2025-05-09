// Developed by Neko


#include "Mecha/MechaPart.h"

#include "Mecha/Technic/Technic.h"


AMechaPart::AMechaPart()
{
 	
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(Root);

}

void AMechaPart::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMechaPart::MakeItemStruct()
{
	FItemStruct ItemStruct;

	ItemStruct.Name = Name;
	ItemStruct.Description = FText::FromString(TEXT("A Mecha part that can be equipped on Mechas"));
	ItemStruct.Rarity = Rarity;
	ItemStruct.ItemType = EItemType::MechaPart;
	ItemStruct.Thumbnail = Texture;
	ItemStruct.ItemClass = MechaPartItemClass;
	ItemStruct.StackSize = 1;
	ItemStruct.bCanBeUsed = false;
	ItemStruct.bCanBeScraped = true;

	MechaPartData.ItemStruct = ItemStruct;
}

void AMechaPart::SetTechnicSlotQuantity()
{
	struct FTechnicSlots
	{
		int32 Passive;
		int32 Active;
	};

	// Static lookup table
	static const FTechnicSlots TechnicSlotsByRarity[] = 
	{
		{1, 1}, // Common
		{1, 2}, // Uncommon
		{2, 2}, // Rare
		{2, 3}, // Epic
		{3, 3}  // Legendary
	};

	// Make sure Rarity is a valid index!
	if (static_cast<int32>(Rarity) >= 0 && static_cast<int32>(Rarity) < UE_ARRAY_COUNT(TechnicSlotsByRarity))
	{
		MechaPartData.PassiveTechnicSlotQuantity = TechnicSlotsByRarity[static_cast<int32>(Rarity)].Passive;
		MechaPartData.ActiveTechnicSlotQuantity = TechnicSlotsByRarity[static_cast<int32>(Rarity)].Active;
	}
	else
	{
		// Handle invalid Rarity
		MechaPartData.PassiveTechnicSlotQuantity = 0;
		MechaPartData.ActiveTechnicSlotQuantity = 0;
	}
}

void AMechaPart::MakeStats()
{
	// Start from BaseStats
	FMechaStats FinalStats = MechaPartData.BaseStats;

	// Add each BonusStat
	for (const TPair<FString, FMechaStats>& Pair : MechaPartData.BonusStats)
	{
		const FMechaStats& Bonus = Pair.Value;

		FinalStats.Power += Bonus.Power;
		FinalStats.Control += Bonus.Control;
		FinalStats.Defense += Bonus.Defense;
		FinalStats.Mobility += Bonus.Mobility;
		FinalStats.Cooling += Bonus.Cooling;
	}

	// Save it to MechaPartData.Stats
	MechaPartData.Stats = FinalStats;
}

void AMechaPart::AddBonus(FString BonusName, FMechaStats Bonus)
{
	// Add or overwrite the bonus in the map
	MechaPartData.BonusStats.Add(BonusName, Bonus);

	// Recalculate final stats
	MakeStats();
}

void AMechaPart::RemoveBonus(FString BonusName)
{
	// Remove the bonus from the map
	MechaPartData.BonusStats.Remove(BonusName);

	// Recalculate final stats
	MakeStats();
}

bool AMechaPart::AddTechnic(UTechnic* Technic)
{
	if (!Technic)
	{
		return false;
	}

	if (Technic->bIsActive)
	{
		if (GetActiveTechnicsCount() >= MechaPartData.ActiveTechnicSlotQuantity)
		{
			// No space for active technics
			return false;
		}
		MechaPartData.Technics.Add(Technic);
		AddBonus(Technic->Name.ToString(),Technic->BonusStats);
	}
	else
	{
		if (GetPassiveTechnicsCount() >= MechaPartData.PassiveTechnicSlotQuantity)
		{
			// No space for passive technics
			return false;
		}
		MechaPartData.Technics.Add(Technic);
		AddBonus(Technic->Name.ToString(),Technic->BonusStats);
	}

	// Optionally: apply bonus stats from the technic here if needed

	return true;
}

bool AMechaPart::RemoveTechnic(UTechnic* Technic)
{
	if (!Technic)
	{
		return false;
	}
	
	RemoveBonus(Technic->Name.ToString());
	bool bRemoved = MechaPartData.Technics.RemoveSingle(Technic) > 0;

	return bRemoved;
}

int32 AMechaPart::GetActiveTechnicsCount()
{
	int32 TechnicsCount = 0;
	for (UTechnic* Technic : MechaPartData.Technics)
	{
		if (Technic->bIsActive == true)
		{
			TechnicsCount++;
		}
	}
	return TechnicsCount;
}

int32 AMechaPart::GetPassiveTechnicsCount()
{
	int32 TechnicsCount = 0;
	for (UTechnic* Technic : MechaPartData.Technics)
	{
		if (Technic->bIsActive == false)
		{
			TechnicsCount++;
		}
	}
	return TechnicsCount;
}




