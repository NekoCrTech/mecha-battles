// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputMappingContext.h"
#include "BattleCameraPawn.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class MECHABATTLES_API ABattleCameraPawn : public APawn
{
	GENERATED_BODY()

public:
	ABattleCameraPawn();

	virtual void NotifyControllerChanged() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE float GetMoveSpeed() const { return MoveSpeed; }
	UFUNCTION(BlueprintCallable)
	FORCEINLINE void SetMoveSpeed(const float Value) { MoveSpeed = Value; }
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE float GetMoveInterpSpeed() const { return MoveInterpSpeed; }
	UFUNCTION(BlueprintCallable)
	FORCEINLINE void SetMoveInterpSpeed(const float Value) { MoveInterpSpeed = Value; }
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE float GetRotateStep() const { return RotateStep.Yaw; }
	UFUNCTION(BlueprintCallable)
	FORCEINLINE void SetRotateStep(const float Value) { RotateStep.Yaw = Value; }
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE float GetRotateInterpSpeed() const { return RotateInterpSpeed; }
	UFUNCTION(BlueprintCallable)
	FORCEINLINE void SetRotateInterpSpeed(const float Value) { RotateInterpSpeed = Value; }
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE float GetZoomSpeed() const { return ZoomSpeed; }
	UFUNCTION(BlueprintCallable)
	FORCEINLINE void SetZoomSpeed(const float Value) { ZoomSpeed = Value; }
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE float GetMinZoom() const { return MinZoom; }
	UFUNCTION(BlueprintCallable)
	FORCEINLINE void SetMinZoom(const float Value) { MinZoom = Value; }
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE float GetMaxZoom() const { return MaxZoom; }
	UFUNCTION(BlueprintCallable)
	FORCEINLINE void SetMaxZoom(const float Value) { MaxZoom = Value; }
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE float GetZoomInterpSpeed() const { return ZoomInterpSpeed; }
	UFUNCTION(BlueprintCallable)
	FORCEINLINE void SetZoomInterpSpeed(const float Value) { ZoomInterpSpeed = Value; }
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Zoom(const FInputActionValue& Value);
	void Move(const FInputActionValue& Value);
	void Rotate(const FInputActionValue& Value);
	void EnableMore(const FInputActionValue& Value);
	void DisableMore(const FInputActionValue& Value);
	void ResetZoom(const FInputActionValue& Value);
	void ResetRotate(const FInputActionValue& Value);


private:

	/** Components */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* Root;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Camera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Input Actions */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* ZoomAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* RotateAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* EnableMoreAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* ResetZoomAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* ResetRotateAction;
	
	/** Settings **/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings | Move", meta = (AllowPrivateAccess = "true"))
	float MoveSpeed = 20.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings | Move", meta = (AllowPrivateAccess = "true"))
	float MoveInterpSpeed = 5.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings | Rotate", meta = (AllowPrivateAccess = "true"))
	FRotator RotateStep = FRotator(0.f,45.f,0.f);
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings | Rotate", meta = (AllowPrivateAccess = "true"))
	FRotator DefaultRotation = GetActorRotation();
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings | Rotate", meta = (AllowPrivateAccess = "true"))
	float RotateInterpSpeed = 2.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings | Zoom", meta = (AllowPrivateAccess = "true"))
	float ZoomSpeed = 100.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings | Zoom", meta = (AllowPrivateAccess = "true"))
	float MinZoom = 100.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings | Zoom", meta = (AllowPrivateAccess = "true"))
	float MaxZoom = 5000.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings | Zoom", meta = (AllowPrivateAccess = "true"))
	float DefaultZoom = 3500.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings | Zoom", meta = (AllowPrivateAccess = "true"))
	float ZoomInterpSpeed = 2.f;
	
	FRotator RotationDesired = GetActorRotation();
	float ZoomDesired = DefaultZoom;
	FVector LocationDesired = GetActorLocation();
	bool bMoreIsEnabled = false;
};
