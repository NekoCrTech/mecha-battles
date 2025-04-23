// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MbPlayerController.generated.h"

class UInputMappingContext;
/**
 * 
 */
UCLASS()
class MECHABATTLES_API AMbPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* WorldMappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* UserInterfaceMappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* BattleMappingContext;
};
