// Neko Creative Technologies


#include "Debug/DebugUserWidget.h"

#include "Components/WidgetSwitcher.h"
#include "Debug/DebugTabButton.h"

void UDebugUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	for (UDebugTabButton* TabButton : DebugTabButtons)
	{
		if (TabButton)
		{
			TabButton->OnTabSelected.AddDynamic(this, &UDebugUserWidget::OnTabSelected);
		}
	}

	// Set initial active tab button as disabled
	int32 InitialIndex = TabContents ? TabContents->GetActiveWidgetIndex() : 0;

	for (int32 i = 0; i < DebugTabButtons.Num(); ++i)
	{
		if (DebugTabButtons[i])
		{
			// Disable the button matching the active index, enable others
			bool bIsActive = (i == InitialIndex);
			DebugTabButtons[i]->UpdateButtonState(bIsActive);
		}
	}
}
void UDebugUserWidget::OnTabSelected(int32 TabIndex)
{
	int32 CurrentIndex = TabContents ? TabContents->GetActiveWidgetIndex() : -1;

	// If the active tab is clicked again, switch to index 0
	if (TabIndex == CurrentIndex && TabContents && TabContents->GetNumWidgets() > 0)
	{
		TabContents->SetActiveWidgetIndex(0);
	}
	else if (TabContents && TabContents->GetNumWidgets() > TabIndex)
	{
		// Switch to the selected tab
		TabContents->SetActiveWidgetIndex(TabIndex);
	}

	// Update button states (colors)
	for (int32 i = 0; i < DebugTabButtons.Num(); ++i)
	{
		if (DebugTabButtons[i])
		{
			bool bIsActive = (i == TabContents->GetActiveWidgetIndex());
			DebugTabButtons[i]->UpdateButtonState(bIsActive);
		}
	}

	
}
