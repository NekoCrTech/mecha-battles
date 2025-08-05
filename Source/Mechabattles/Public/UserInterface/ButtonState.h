// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "ButtonState.generated.h"

UENUM(BlueprintType)
enum class EButtonState : uint8
{
	None UMETA(DisplayName = "None"),
	Hovered UMETA(DisplayName = "Hovered"),
	Selected UMETA(DisplayName = "Selected"),
};