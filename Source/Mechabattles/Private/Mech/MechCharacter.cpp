// Developed by Neko


#include "Mech/MechCharacter.h"

#include "Mech/MechUnitComponent.h"

// Sets default values
AMechCharacter::AMechCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMechCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMechCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Initialize the MechUnitComponent
	MechUnitComponent = CreateDefaultSubobject<UMechUnitComponent>(TEXT("MechUnitComponent"));

	// Setup character movement inputs

}

// Called to bind functionality to input
void AMechCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMechCharacter::MoveForward(float Value)
{
}

void AMechCharacter::MoveRight(float Value)
{
}

void AMechCharacter::PerformAction()
{
}

void AMechCharacter::EquipItem(EMechSlot Slot, UEquipmentItem* Item)
{
}

void AMechCharacter::ScrapItem(UEquipmentItem* Item)
{
}

