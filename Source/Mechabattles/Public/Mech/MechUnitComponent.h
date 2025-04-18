// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Mech/MechData.h"
#include "MechUnitComponent.generated.h"

class UEquipmentItem;




UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MECHABATTLES_API UMechUnitComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	
	UMechUnitComponent();

	// Base stats without equipment
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
	FMechStats BaseStats;

	// Equipped items
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Equipment")
	TMap<EMechSlot, UEquipmentItem*> EquippedItems;
	
	// Final calculated stats
	UFUNCTION(BlueprintCallable, Category="Stats")
	FMechStats GetTotalStats() const;
	
	// Equip item
	UFUNCTION(BlueprintCallable, Category="Equipment")
	bool EquipItem(EMechSlot Slot, UEquipmentItem* Item);
	
	// Scrap item
	UFUNCTION(BlueprintCallable, Category="Equipment")
	bool ScrapItem(UEquipmentItem* Item, int32& OutScrapValue);

	UFUNCTION(BlueprintPure)
	UEquipmentItem* GetEquippedItem(EMechSlot Slot) const;

protected:
	
	virtual void BeginPlay() override;

		
};
