// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UtilitiesLibrary.generated.h"

enum class EColorEnum : uint8;

UCLASS()
class MECHABATTLES_API UUtilitiesLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Utilities Library")
	static FVector SnapVectorToVector(FVector A, FVector B);

	UFUNCTION(BlueprintCallable,BlueprintPure, Category = "Utilities")
	static FVector GetColorByTileType(ETileType TileType);

	UFUNCTION(BlueprintCallable,BlueprintPure, Category = "Utilities")
	static bool IsTileTypeWalkable(ETileType InTileType);

	UFUNCTION(BlueprintCallable,BlueprintPure, Category = "Utilities")
	static FLinearColor GetColorFromEnum (EColorEnum Color);
	
};
