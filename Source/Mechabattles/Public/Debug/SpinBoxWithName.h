// Neko Creative Technologies

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SpinBoxWithName.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSpinBoxValueChanged, float, NewValue);

class USpinBox;
class UTextBlock;
/**
 * 
 */
UCLASS()
class MECHABATTLES_API USpinBoxWithName : public UUserWidget
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget), Category = "Components")
	UTextBlock* SpinBoxName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget), Category = "Components")
	USpinBox* SpinBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	FText Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	FVector2D MinMaxSlider;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	FVector2D MinMaxValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	FIntPoint MinMaxFractionalDigits;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	float Value;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	bool bAlwaysSnap;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	float Delta;

	UPROPERTY(BlueprintAssignable, Category = "SpinBox")
	FOnSpinBoxValueChanged OnSpinBoxValueChanged;

	UFUNCTION(BlueprintCallable, Category = "SpinBox")
	void SetValue(float NewValue);

protected:
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;

	UFUNCTION()
	void HandleValueChanged(float NewValue);

private:
	void SetInitialValues();
};
