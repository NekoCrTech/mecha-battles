// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "AttackData.generated.h"

class AAttackAnimation;


UENUM(BlueprintType)
enum class EAttackRangePattern : uint8
{
	None	UMETA(DisplayName = "None"),
	Line UMETA(DisplayName = "Line"),
	Diagonal UMETA(DisplayName = "Diagonal"),
	HalfDiagonal UMETA(DisplayName = "HalfDiagonal"),
	Star UMETA(DisplayName = "Star"),
	Diamond UMETA(DisplayName = "Diamond"),
	Square UMETA(DisplayName = "Square"),
};

USTRUCT(BlueprintType)
struct FAttackAssets : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Asset)
	TSubclassOf<AAttackAnimation> AttackAnimation = nullptr;
};

USTRUCT(BlueprintType)
struct FAttackAction : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Asset)
	EAttackRangePattern RangePattern = EAttackRangePattern::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Asset)
	FIntPoint RangeMinMax = FIntPoint(0);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Asset)
	bool bRequireLineOfSight = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Asset)
	float LineOfSight_HeightFromGround = 150.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Asset)
	float LineOfSight_OffsetFromCenter = 1/4;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Asset)
	bool LineOfSight_DrawDebugLine = false;
	
};

USTRUCT(BlueprintType)
struct FAttackData : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attack)
	FText AttackID = FText();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attack)
	FAttackAssets Assets = FAttackAssets();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attack)
	FAttackAction Action = FAttackAction();
	
};
