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

// FItemStruct AMechaPart::GetItemStruct()
// {
// 	FItemStruct ItemStruct;
//
// 	ItemStruct.Name = Name;
// 	ItemStruct.Description = FText::FromString(TEXT("A Mecha part that can be equipped on Mechas"));
// 	ItemStruct.Rarity = Rarity;
// 	ItemStruct.ItemType = EItemType::MechaPart;
// 	ItemStruct.Thumbnail = Texture;
// 	ItemStruct.ItemClass = MechaPartItemClass;
// 	ItemStruct.StackSize = 1;
// 	ItemStruct.bCanBeUsed = false;
// 	ItemStruct.bCanBeScraped = true;
//
// 	return ItemStruct;
// }
//
//
// void AMechaPart::MakeStats()
// {
// 	// Start from BaseStats
// 	FMechaStats FinalStats = MechaPartData.BaseStats;
//
// 	// Add each BonusStat
// 	for (const TPair<FString, FMechaStats>& Pair : MechaPartData.BonusStats)
// 	{
// 		const FMechaStats& Bonus = Pair.Value;
//
// 		FinalStats.Power += Bonus.Power;
// 		FinalStats.Control += Bonus.Control;
// 		FinalStats.Defense += Bonus.Defense;
// 		FinalStats.Mobility += Bonus.Mobility;
// 		FinalStats.Cooling += Bonus.Cooling;
// 	}
//
// 	// Save it to MechaPartData.Stats
// 	MechaPartData.Stats = FinalStats;
// }
//
// void AMechaPart::AddBonus(FString BonusName, FMechaStats Bonus)
// {
// 	// Add or overwrite the bonus in the map
// 	MechaPartData.BonusStats.Add(BonusName, Bonus);
//
// 	// Recalculate final stats
// 	MakeStats();
// }
//
// void AMechaPart::RemoveBonus(FString BonusName)
// {
// 	// Remove the bonus from the map
// 	MechaPartData.BonusStats.Remove(BonusName);
//
// 	// Recalculate final stats
// 	MakeStats();
// }




