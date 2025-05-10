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

UENUM(BlueprintType)
enum class EAttackType : uint8
{
	None	UMETA(DisplayName = "None"),
	Overheat UMETA(DisplayName = "Overheat"),
	EMP UMETA(DisplayName = "EMP"),
	Piercing UMETA(DisplayName = "Piercing"),
	LockOn UMETA(DisplayName = "LockOn"),
	Hacking UMETA(DisplayName = "Hacking"),
	Buff UMETA(DisplayName = "Buff"),
	Repair UMETA(DisplayName = "Repair"),
};

USTRUCT(BlueprintType)
struct FAttackAssets : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Asset)
	TSubclassOf<AAttackAnimation> AttackAnimation = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Asset)
	TObjectPtr<UTexture2D> Texture = nullptr;
};

USTRUCT(BlueprintType)
struct FLineOfSight : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	bool bRequireLineOfSight = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	float LineOfSight_HeightFromGround = 150.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	float LineOfSight_OffsetFromCenter = 0.25f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	bool LineOfSight_DrawDebugLine = false;
	
};

USTRUCT(BlueprintType)
struct FAttackAction : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	EAttackRangePattern RangePattern = EAttackRangePattern::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	FIntPoint RangeMinMax = FIntPoint(0);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	FLineOfSight LineOfSight = FLineOfSight();
	
};

USTRUCT(BlueprintType)
struct FAttackImpact : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	int32 BaseHitChance = 20;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	int32 BaseDamage = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	int32 Multiplier = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	TArray<EAttackType> AttackTypes = TArray<EAttackType>();
};

USTRUCT(BlueprintType)
struct FAttackImpactReal : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	int32 ModifierHp = 0;
};

USTRUCT(BlueprintType)
struct FAttackRequirements : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	int32 Cost_AP = 1;
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attack)
	FAttackAction ActionAoe = FAttackAction();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attack)
	FAttackImpact Impact = FAttackImpact();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attack)
	FAttackRequirements Requirements = FAttackRequirements();	
};
