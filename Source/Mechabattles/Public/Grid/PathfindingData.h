// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "PathfindingData.generated.h"

USTRUCT(BlueprintType)
struct FPathfindingData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pathfinding")
	FIntPoint Index = FIntPoint(-999, -999);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pathfinding")
	int32 CostToEnterTile = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pathfinding")
	int32 CostFromStart = 999999;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pathfinding")
	int32 MinimumCostToTarget = 999999;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pathfinding")
	FIntPoint PreviousIndex = FIntPoint(-999, -999);
};