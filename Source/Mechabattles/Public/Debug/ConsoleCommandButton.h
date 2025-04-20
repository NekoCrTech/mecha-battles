// Neko Creative Technologies

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ConsoleCommandButton.generated.h"

class UTextBlock;
class UButton;
/**
 * 
 */
UCLASS()
class MECHABATTLES_API UConsoleCommandButton : public UUserWidget
{
	GENERATED_BODY()

protected:
	// The button widget
	UPROPERTY(meta = (BindWidget))
	UButton* CommandButton;

	// The text block for button label
	UPROPERTY(meta = (BindWidget))
	UTextBlock* ButtonText;

	// Console command to execute (set in editor)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Console Command")
	FString ConsoleCommand;

	// Button label (set in editor)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Console Command")
	FText CommandLabel;

	// Function to handle button click
	UFUNCTION()
	void         OnButtonClicked();
	
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;
};
