// Neko Creative Technologies

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DebugActor.generated.h"

class UDebugUserWidget;

UCLASS()
class MECHABATTLES_API ADebugActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ADebugActor();

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Debug")
	TSubclassOf<UDebugUserWidget> DebugUserWidgetClass;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Debug", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UDebugUserWidget> DebugUserWidget;
	
};
