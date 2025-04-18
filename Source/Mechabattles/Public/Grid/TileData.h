// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "TileData.generated.h"

UENUM(BlueprintType)
enum class ETileType : uint8
{
	None	UMETA(DisplayName = "None"),
	Normal	UMETA(DisplayName = "Normal"),
	Obstacle	UMETA(DisplayName = "Obstacle"),
};

USTRUCT(BlueprintType)
struct FTileData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FIntPoint Index = FIntPoint(-999, -999);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETileType TileType = ETileType::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTransform Transform = FTransform();
};