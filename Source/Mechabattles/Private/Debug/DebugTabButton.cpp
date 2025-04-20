// Neko Creative Technologies


#include "Debug/DebugTabButton.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"

void UDebugTabButton::NativePreConstruct()
{
	Super::NativePreConstruct();

	Text->SetText(TextValue);
}

void UDebugTabButton::NativeConstruct()
{
	Super::NativeConstruct();
	
	Button->OnClicked.AddDynamic(this, &UDebugTabButton::HandleButtonClicked);
}

void UDebugTabButton::UpdateButtonState(bool bIsActive)
{
	FLinearColor BgColor = bIsActive ? TabIsSelectedColor : TabIsNotSelectedColor;
	Button->SetBackgroundColor(BgColor);
}

void UDebugTabButton::HandleButtonClicked()
{
	OnTabSelected.Broadcast(TabIndex);
}



