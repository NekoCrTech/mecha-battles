// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "MechaData.generated.h"

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
struct FEquipmentData : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Equipment)
	FName EquipmentID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Equipment)
	EEquipmentSlot EquipmentSlot = EEquipmentSlot::Head;
};

USTRUCT(BlueprintType)
struct FMechaAssets
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Assets)
	USkeletalMesh* Mesh = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Assets)
	TSubclassOf<UAnimInstance> AnimInstance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Assets)
	UTexture2D* Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Assets)
	UMaterialInstance* HeadMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Assets)
	UMaterialInstance* LegsMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Assets)
	UMaterialInstance* TorsoMaterial;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Assets)
	FLinearColor Color;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Assets)
	FLinearColor EmissiveColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Assets)
	UTextureRenderTarget2D* RenderTarget;
	
};

USTRUCT(BlueprintType)
struct FMechaData : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	FName MechaName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	FMechaAssets MechaAssets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	FMechaEquipment MechaEquipment;
	
};
