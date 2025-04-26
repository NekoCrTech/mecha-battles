// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "InventoryActions.generated.h"

UENUM(BlueprintType)
enum class EInventoryActions : uint8
{
	None	UMETA(DisplayName = "None"),
	Scrap	UMETA(DisplayName = "Scrap"),
	Use		UMETA(DisplayName = "Use"),
	Drop	UMETA(DisplayName = "Drop"),
	Destroy	UMETA(DisplayName = "Destroy"),
};

USTRUCT(BlueprintType)
struct FInventoryActionStruct : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EInventoryActions InventoryAction = EInventoryActions::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FKey Key = FKey();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Text = FText();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Texture = nullptr;
};
