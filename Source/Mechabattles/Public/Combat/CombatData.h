// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "CombatData.generated.h"

class AMechaActor;

USTRUCT(BlueprintType)
struct FMechaSet : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSet<AMechaActor*> MechaActors = TSet<AMechaActor*>(); 
};


