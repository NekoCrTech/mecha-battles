// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "MechaData.h"
#include "Components/ActorComponent.h"
#include "Inventory/InventoryData.h"
#include "MechaPartComponent.generated.h"

UENUM(BlueprintType)
enum class EEquipmentSlot : uint8
{
	Head UMETA(DisplayName = "Head"),
	HandRight UMETA(DisplayName = "HandRight"),
	HandLeft UMETA(DisplayName = "HandLeft"),
	Torso UMETA(DisplayName = "Torso"),
	Legs UMETA(DisplayName = "Legs"),
	Core UMETA(DisplayName = "Core")
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable )
class MECHABATTLES_API UMechaPartComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UMechaPartComponent();

	// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	// TMap<EEquipmentSlot, AMechaPart*> EquippedParts;

	// UFUNCTION(BlueprintCallable)
	// AMechaPart* EquipPart(EEquipmentSlot InSlot, AMechaPart* InPart);
	//
	// UFUNCTION(BlueprintCallable)
	// AMechaPart* UnequipPart(EEquipmentSlot InSlot);
	
protected:
	virtual void BeginPlay() override;
		
};
