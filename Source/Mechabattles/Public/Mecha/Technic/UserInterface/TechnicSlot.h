// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TechnicSlot.generated.h"

class UTechnicDataAsset;
class UImage;
class UButton;
/**
 * 
 */
UCLASS()
class MECHABATTLES_API UTechnicSlot : public UUserWidget
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget), category = "Components")
	UButton* Technic_Btn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget), category = "Components")
	UImage* Technic_Img;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Data")
	UTechnicDataAsset* TechnicData = nullptr;
	
	UFUNCTION(BlueprintCallable)
	void SetTechnic(UTechnicDataAsset* InTechnicData);

	UFUNCTION(BlueprintImplementableEvent)
	void SetMaterial();
};
