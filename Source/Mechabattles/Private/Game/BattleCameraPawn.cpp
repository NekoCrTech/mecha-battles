// Developed by Neko


#include "Game/BattleCameraPawn.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ABattleCameraPawn::ABattleCameraPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	// Create Spring Arm for Camera
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->TargetArmLength = 2000.0f; // Default distance from target

	// Create Camera
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent);

	// Set this pawn to be controlled by the player
	bReplicates = true;

}

// Called when the game starts or when spawned
void ABattleCameraPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABattleCameraPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABattleCameraPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

