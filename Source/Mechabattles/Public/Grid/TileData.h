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

UENUM(BlueprintType)
enum class ETileState : uint8
{
	None		UMETA(DisplayName = "None"),
	Hovered		UMETA(DisplayName = "Hovered"),
	Selected	UMETA(DisplayName = "Selected"),
	IsNeighbor	UMETA(DisplayName = "IsNeighbor"),
	IsInPath		UMETA(DisplayName = "IsInPath"),
};

USTRUCT(BlueprintType)
struct FTileData : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FIntPoint Index = FIntPoint(-999, -999);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETileType TileType = ETileType::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTransform Transform = FTransform();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<ETileState> States = TArray<ETileState>();
};