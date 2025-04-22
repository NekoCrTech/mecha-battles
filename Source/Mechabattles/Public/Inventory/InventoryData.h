// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "InventoryData.generated.h"

UENUM(BlueprintType)
enum class ERarity : uint8
{
	Common		UMETA(DisplayName = "Common"),
	Uncommon	UMETA(DisplayName = "Uncommon"),
	Rare		UMETA(DisplayName = "Rare"),
	Epic		UMETA(DisplayName = "Epic"),
	Legendary	UMETA(DisplayName = "Legendary")
	
};

UENUM(BlueprintType)
enum class EItemType : uint8
{
	None		UMETA(DisplayName = "None"),
	Resource	UMETA(DisplayName = "Resource"),
	MechaPart	UMETA(DisplayName = "MechaPart"),
	Tool		UMETA(DisplayName = "Tool")
};

USTRUCT(BlueprintType)
struct FSlotStruct : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ItemID = FName();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Quantity = 0;
};

USTRUCT(BlueprintType)
struct FItemStruct : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Name = FText();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Description = FText();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ERarity Rarity = ERarity::Common;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EItemType ItemType = EItemType::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Thumbnail = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> ItemClass = TSubclassOf<AActor>();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 StackSize = 64;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCanBeUsed = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCanBeScraped = false;
};
