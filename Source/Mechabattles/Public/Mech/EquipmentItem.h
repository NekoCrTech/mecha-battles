// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Mech/MechData.h"
#include "Mech/EquipmentDataAsset.h"
#include "EquipmentItem.generated.h"

/**
 * 
 */
UCLASS()
class MECHABATTLES_API UEquipmentItem : public UObject
{
	GENERATED_BODY()

public:
	// Reference to static data
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Equipment")
	UEquipmentDataAsset* Template;

	// Dynamic properties
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Equipment")
	int32 UpgradeLevel = 0;

	// Gets the final bonus from base stats + upgrades
	UFUNCTION(BlueprintCallable, Category = "Stats")
	FMechStats GetModifiedStats() const;

	// Get total scrap value
	UFUNCTION(BlueprintCallable, Category = "Scrap")
	int32 GetScrapValue() const;

	// Upgrades the item
	UFUNCTION(BlueprintCallable, Category = "Upgrade")
	bool Upgrade();
	
};
