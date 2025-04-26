// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "Mecha/MechaData.h"
#include "UObject/NoExportTypes.h"
#include "Technic.generated.h"

/**
 * 
 */
UCLASS()
class MECHABATTLES_API UTechnic : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FText Name = FText();

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool bIsActive = false;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FMechaStats BonusStats;
	
};
