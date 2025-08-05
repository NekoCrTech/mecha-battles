// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "Combat/Attacks/AttackData.h"
#include "Data/TechnicState.h"
#include "Mecha/MechaData.h"
#include "Technic.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class MECHABATTLES_API UTechnic : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FText Name = FText();

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FMechaStats BonusStats;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UTexture2D* Thumbnail;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	ETechnicState State = ETechnicState::Locked;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FAttackData AttackData = FAttackData();

};
