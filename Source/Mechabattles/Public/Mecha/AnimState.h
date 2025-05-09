// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "AnimState.generated.h"

UENUM(BlueprintType)
enum class EMechaAnimState : uint8
{
	Idle	UMETA(DisplayName = "Idle"),
	Walk 	UMETA(DisplayName = "Walk"),
	Attack	UMETA(DisplayName = "Attack"),
	Hit		UMETA(DisplayName = "Hit"),
	Death		UMETA(DisplayName = "Death"),
	Respawn	UMETA(DisplayName = "Respawn"),
};
