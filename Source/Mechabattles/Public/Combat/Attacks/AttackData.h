// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "AttackData.generated.h"


class AAttackAnimation;

USTRUCT(BlueprintType)
struct FAttackAssets : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Asset)
	TSubclassOf<AAttackAnimation> AttackAnimation = nullptr;
};

USTRUCT(BlueprintType)
struct FAttackData : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attack)
	FText AttackID = FText();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attack)
	FAttackAssets Assets = FAttackAssets();
	
};
