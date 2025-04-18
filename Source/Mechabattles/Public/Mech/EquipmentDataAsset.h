// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Mech/MechData.h"
#include "EquipmentDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class MECHABATTLES_API UEquipmentDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Equipment")
	FText ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Equipment")
	EMechSlot SlotType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	FMechStats BaseStatBonus;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Visual")
	UTexture2D* Icon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Equipment")
	int32 MaxUpgradeLevel = 5;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Equipment")
	int32 BaseScrapValue = 10;

	// You can add rarity, effects, or ability references later
	
};
