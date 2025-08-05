// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "MechaData.h"
#include "GameFramework/Actor.h"
#include "Inventory/InventoryData.h"
#include "MechaPart.generated.h"

class UTechnic;

USTRUCT(BlueprintType)
struct FMechaPartStruct : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FText Name = FText::FromString("None");

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FText Description = FText();

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UStaticMesh* PartMesh = nullptr;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	ERarity Rarity = ERarity::Common;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UTexture2D* Texture = nullptr; 
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
	FMechaStats BaseStats = FMechaStats(0);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
	TMap<FString, FMechaStats> BonusStats;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
	FMechaStats Stats = FMechaStats(0);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Data")
	EEquipmentSlotType EquipmentSlot = EEquipmentSlotType::Core;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Data")
	TArray<UTechnic*> Technics;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Data")
	int32 TechnicSlotQuantity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Data")
	TArray<FSlotStruct> Recipe;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Data")
	TArray<FSlotStruct> Scraps;
};

UCLASS()
class MECHABATTLES_API AMechaPart : public AActor
{
	GENERATED_BODY()
	
public:
	
	AMechaPart();

	// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Data")
	// FMechaPartStruct MechaPartData;
	//
	// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Data")
	// FText Name = FText();
	//
	// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Data")
	// ERarity Rarity = ERarity::Common;
	//
	// UFUNCTION(BlueprintCallable)
	// FItemStruct GetItemStruct();
	//
	// UFUNCTION(BlueprintCallable)
	// void MakeStats();
	//
	// UFUNCTION(BlueprintCallable)
	// void AddBonus(FString BonusName, FMechaStats Bonus);
	//
	// UFUNCTION(BlueprintCallable)
	// void RemoveBonus(FString BonusName);
	//
	// UFUNCTION(BlueprintCallable, BlueprintPure)
	// FORCEINLINE FMechaStats GetStats() {return MechaPartData.Stats;}
	//
	// UFUNCTION(BlueprintCallable, BlueprintPure)
	// FORCEINLINE TArray<UTechnic*> GetTechnics() {return MechaPartData.Technics;}

protected:
	
	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USceneComponent> Root;

	// UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Data", meta = (AllowPrivateAccess = "true"))
	// UTexture2D* Texture;
	//
	// UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Data", meta = (AllowPrivateAccess = "true"))
	// TSubclassOf<AItemActor> MechaPartItemClass;
		
};
