// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BattleCameraPawn.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class MECHABATTLES_API ABattleCameraPawn : public APawn
{
	GENERATED_BODY()

public:
	ABattleCameraPawn();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComponent;

protected:
	virtual void BeginPlay() override;
	
};
