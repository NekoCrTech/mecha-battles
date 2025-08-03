// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "TechnicState.generated.h"

UENUM(BlueprintType)
enum class ETechnicState : uint8
{
	Locked		UMETA(DisplayName = "Locked"),
	Unlocked	UMETA(DisplayName = "Unlocked"),
	Owned		UMETA(DisplayName = "Owned")
};
