// Neko Creative Technologies


#include "Debug/DebugActor.h"
#include "Debug/DebugUserWidget.h"
#include "Blueprint/UserWidget.h"


// Sets default values
ADebugActor::ADebugActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void ADebugActor::BeginPlay()
{
	Super::BeginPlay();
	
	if (DebugUserWidgetClass)
	{
		// Create the widget
		DebugUserWidget = CreateWidget<UDebugUserWidget>(GetWorld(), DebugUserWidgetClass);

		if (DebugUserWidget)
		{
			// Add to viewport or attach to the actor if needed
			DebugUserWidget->AddToViewport();
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to create DebugUserWidget"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("DebugUserWidgetClass is not set on DebugActor"));
	}
}

// Called every frame
void ADebugActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

