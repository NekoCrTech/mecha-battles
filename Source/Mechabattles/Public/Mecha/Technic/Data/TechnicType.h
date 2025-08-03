// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "TechnicType.generated.h"

UENUM(BlueprintType)
enum class ETechnicType : uint8
{
	Active		UMETA(DisplayName = "Active"),
	Passive		UMETA(DisplayName = "Passive")
};
