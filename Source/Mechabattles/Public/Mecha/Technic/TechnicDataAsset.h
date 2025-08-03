// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TechnicDataAsset.generated.h"

class UTechnic;
/**
 * 
 */
UCLASS()
class MECHABATTLES_API UTechnicDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Technic")
	FText Name = FText::FromString("Name");

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Technic")
	FText Description = FText::FromString("Description");

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Technic")
	UTexture2D* Texture = nullptr;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Technic")
	TMap<int32,float> Values = {{1,1.0f}};

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Technic")
	TSubclassOf<UTechnic> Technic = nullptr; 
};
