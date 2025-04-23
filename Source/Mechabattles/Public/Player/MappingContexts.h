// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "MappingContexts.generated.h"

UENUM(BlueprintType)
enum class EMappingContext : uint8
{
	None			UMETA(DisplayName = "None"),
	Wold			UMETA(DisplayName = "Wold"),
	UserInterface	UMETA(DisplayName = "UserInterface"),
	Battle			UMETA(DisplayName = "Battle")
};