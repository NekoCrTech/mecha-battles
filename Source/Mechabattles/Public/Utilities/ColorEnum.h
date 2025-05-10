// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "ColorEnum.generated.h"

UENUM(BlueprintType)
enum class EColorEnum : uint8
{
	None	UMETA(DisplayName = "None"),
	Red	UMETA(DisplayName = "Red"),
	Green	UMETA(DisplayName = "Green"),
	Blue	UMETA(DisplayName = "Blue"),
	Yellow	UMETA(DisplayName = "Yellow"),
	White	UMETA(DisplayName = "White"),
	Black	UMETA(DisplayName = "Black"),
};