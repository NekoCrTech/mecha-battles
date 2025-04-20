// Neko Creative Technologies


#include "Debug/ConsoleCommandButton.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"

void UConsoleCommandButton::NativePreConstruct()
{
	Super::NativePreConstruct();
	// Set button text
	if (ButtonText)
	{
		ButtonText->SetText(CommandLabel);
	}
}

void UConsoleCommandButton::NativeConstruct()
{
	Super::NativeConstruct();
	// Bind the button click event
	if (CommandButton)
	{
		CommandButton->OnClicked.AddDynamic(this, &UConsoleCommandButton::OnButtonClicked);
	}
}

void UConsoleCommandButton::OnButtonClicked()
{
	if (!ConsoleCommand.IsEmpty())
	{
		// Execute the console command
		APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		if (PC)
		{
			PC->ConsoleCommand(ConsoleCommand, true);
		}
	}
}


