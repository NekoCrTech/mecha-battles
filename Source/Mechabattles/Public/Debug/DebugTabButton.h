// Neko Creative Technologies

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DebugTabButton.generated.h"

// Declare a multicast delegate for broadcasting TabIndex
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTabSelected, int32, TabIndex);

class UTextBlock;
class UButton;

UCLASS()
class MECHABATTLES_API UDebugTabButton : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget), Category = "Components")
	UButton* Button;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget), Category = "Components")
	UTextBlock* Text;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	FText TextValue = FText::FromString("Tab 1");
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	int32 TabIndex = -1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	FLinearColor TabIsSelectedColor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	FLinearColor TabIsNotSelectedColor;

	UPROPERTY(BlueprintAssignable, Category = "Tab")
	FOnTabSelected OnTabSelected;

	UFUNCTION(BlueprintCallable, Category = "Tab")
	void UpdateButtonState(bool bIsActive);

	UFUNCTION()
	void HandleButtonClicked();

protected:
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;
};
