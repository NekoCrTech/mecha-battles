// Developed by Neko


#include "Game/BattleCameraPawn.h"

#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ABattleCameraPawn::ABattleCameraPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);
	
	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = DefaultZoom;
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->SetWorldRotation(FRotator(-60.f,0.f,0.f));

	// Create a camera
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	

}

void ABattleCameraPawn::NotifyControllerChanged()
{
	Super::NotifyControllerChanged();
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

	Super::Tick(DeltaTime);

	CameraBoom->TargetArmLength = FMath::FInterpTo(CameraBoom->TargetArmLength,ZoomDesired,DeltaTime,ZoomInterpSpeed);
	SetActorLocation(FMath::VInterpTo(GetActorLocation(),LocationDesired,DeltaTime,MoveInterpSpeed));
	SetActorRotation(FMath::RInterpTo(GetActorRotation(),RotationDesired,DeltaTime,RotateInterpSpeed));

}

// Called to bind functionality to input
void ABattleCameraPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(EnableMoreAction,ETriggerEvent::Started,this,&ABattleCameraPawn::EnableMore);
		EnhancedInputComponent->BindAction(EnableMoreAction,ETriggerEvent::Completed,this,&ABattleCameraPawn::DisableMore);
		EnhancedInputComponent->BindAction(EnableMoreAction,ETriggerEvent::Canceled,this,&ABattleCameraPawn::DisableMore);

		EnhancedInputComponent->BindAction(ResetZoomAction, ETriggerEvent::Started,this,&ABattleCameraPawn::ResetZoom);
		EnhancedInputComponent->BindAction(ResetRotateAction, ETriggerEvent::Started, this, &ABattleCameraPawn::ResetRotate);
		
		EnhancedInputComponent->BindAction(RotateAction, ETriggerEvent::Triggered,this, &ABattleCameraPawn::Rotate);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ABattleCameraPawn::Move);
		EnhancedInputComponent->BindAction(ZoomAction, ETriggerEvent::Triggered, this, &ABattleCameraPawn::Zoom);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}

}

void ABattleCameraPawn::Zoom(const FInputActionValue& Value)
{
	float ZoomAxis = - Value.Get<float>();

	ZoomDesired = ZoomDesired + ZoomAxis * ZoomSpeed;
	ZoomDesired = FMath::Clamp(ZoomDesired, MinZoom, MaxZoom);
}

void ABattleCameraPawn::Move(const FInputActionValue& Value)
{
	FVector2D MoveAxis = Value.Get<FVector2D>();

	LocationDesired = LocationDesired + MoveAxis.X * MoveSpeed * GetActorForwardVector() + MoveAxis.Y * MoveSpeed * GetActorRightVector();
}

void ABattleCameraPawn::Rotate(const FInputActionValue& Value)
{
	float RotateAxis = Value.Get<float>();
	if (RotateAxis > 0.f)
	{
		RotationDesired = GetActorRotation() + RotateStep;
	}
	else if (RotateAxis < 0.f)
	{
		RotationDesired = GetActorRotation() - RotateStep;
	}
}

void ABattleCameraPawn::EnableMore(const FInputActionValue& Value)
{
	bMoreIsEnabled = true;
}

void ABattleCameraPawn::DisableMore(const FInputActionValue& Value)
{
	bMoreIsEnabled = false;
}

void ABattleCameraPawn::ResetZoom(const FInputActionValue& Value)
{
	if (!bMoreIsEnabled)
	{
		ZoomDesired = DefaultZoom;
	}
}

void ABattleCameraPawn::ResetRotate(const FInputActionValue& Value)
{
	if (bMoreIsEnabled)
	{
		RotationDesired = DefaultRotation;
	}
}

