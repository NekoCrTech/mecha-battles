// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "Mechdata.generated.h"

UENUM(BlueprintType)
enum class EMechSlot : uint8
{
	Core,
	LeftArm,
	RightArm,
	Legs,
	Chip
};

USTRUCT(BlueprintType)
struct FMechStats
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Power = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Armor = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Speed = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Energy = 0;

	// You can add more stats as needed
};

class MECHABATTLES_API MechData
{
public:

};
