// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "MechaData.generated.h"

enum class ETileType : uint8;
class AMechaPart;

UENUM(BlueprintType)
enum class EEquipmentSlot : uint8
{
	Head	UMETA(DisplayName = "Head"),
	Hand	UMETA(DisplayName = "Hand"),
	Torso	UMETA(DisplayName = "Torso"),
	Legs	UMETA(DisplayName = "Legs"),
	Core	UMETA(DisplayName = "Core")
};


USTRUCT(BlueprintType)
struct FMechaEquipment : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Equipment)
	AMechaPart* Head = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Equipment)
	AMechaPart* RightHand = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Equipment)
	AMechaPart* LeftHand = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Equipment)
	AMechaPart* Torso = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Equipment)
	AMechaPart* Legs = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Equipment)
	AMechaPart* Core = nullptr;
};

USTRUCT(BlueprintType)
struct FMechaAssets
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Assets)
	USkeletalMesh* Mesh = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Assets)
	TSubclassOf<UAnimInstance> AnimInstance = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Assets)
	UTexture2D* Icon = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Assets)
	UMaterialInstance* HeadMaterial = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Assets)
	UMaterialInstance* LegsMaterial = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Assets)
	UMaterialInstance* TorsoMaterial = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Assets)
	FLinearColor Color = FLinearColor::White;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Assets)
	FLinearColor EmissiveColor = FLinearColor::White;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Assets)
	UTextureRenderTarget2D* RenderTarget = nullptr;
	
};

USTRUCT(BlueprintType)
struct FMechaStats : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats, meta = (ToolTip = "Boosts weapon damage and strength-based abilities" ))
	int32 Power = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats, meta = (ToolTip = "Affects accuracy, hacking success, and skill activation" ))
	int32 Control = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats, meta = (ToolTip = "Reduces incoming damage and improves shield strength" ))
	int32 Defense = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats, meta = (ToolTip = "Influences movement range and evasion" ))
	int32 Mobility = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats, meta = (ToolTip = "Reduces Technic cooldowns and boosts heat/energy efficiency" ))
	int32 Cooling = 10;

	// --- Constructors ---

	// Default constructor
	FMechaStats() {}

	// Constructor: set all stats to the same value
	FMechaStats(int32 InValue)
		: Power(InValue), Control(InValue), Defense(InValue), Mobility(InValue), Cooling(InValue)
	{}

	// Constructor: set each stat individually
	FMechaStats(int32 InPower, int32 InControl, int32 InDefense, int32 InMobility, int32 InCooling)
		: Power(InPower), Control(InControl), Defense(InDefense), Mobility(InMobility), Cooling(InCooling)
	{}
	
};

USTRUCT(BlueprintType)
struct FSecondaryMechaStats : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SecondaryStats)
	TArray<ETileType> ValidTileTypes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SecondaryStats)
	TArray<int32> AvailableAttacks = TArray<int32>();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SecondaryStats)
	int32 MP_Current = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SecondaryStats)
	int32 MP_Max = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SecondaryStats)
	int32 HP_Current = 50;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SecondaryStats)
	int32 HP_Max = 50;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SecondaryStats)
	int32 AP_Current = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SecondaryStats)
	int32 AP_Max = 3;
};

USTRUCT(BlueprintType)
struct FMechaData : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	FName MechaName = FName("MechaName");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	FMechaAssets MechaAssets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	FMechaStats MechaStats;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	FSecondaryMechaStats SecondaryMechaStats;
};
