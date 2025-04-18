// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Mech/MechData.h"
#include "Mech/EquipmentItem.h"
#include "MechCharacter.generated.h"

class UMechUnitComponent;

UCLASS()
class MECHABATTLES_API AMechCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMechCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UMechUnitComponent* MechUnitComponent;

	// Movement
	void MoveForward(float Value);
	void MoveRight(float Value);

	// Action for the mech (e.g., attack, special moves)
	void PerformAction();

	// Equipment interaction
	void EquipItem(EMechSlot Slot, UEquipmentItem* Item);
	void ScrapItem(UEquipmentItem* Item);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
