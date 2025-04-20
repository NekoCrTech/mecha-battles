// Neko Creative Technologies

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DebugUserWidget.generated.h"

class UDebugTabButton;
class UWidgetSwitcher;
/**
 * 
 */
UCLASS()
class MECHABATTLES_API UDebugUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget), Category = "Debug User Widget")
	UWidgetSwitcher* TabContents;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Components")
	TArray<UDebugTabButton*> DebugTabButtons;

	UFUNCTION()
	void OnTabSelected(int32 TabIndex);
	
protected:

	virtual void NativeConstruct() override;
	
};
