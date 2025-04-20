// Neko Creative Technologies

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SpinBoxWithNameVector2.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSpinBoxVector2XValueChanged, float, NewValueX);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSpinBoxVector2YValueChanged, float, NewValueY);

class USpinBox;
class UTextBlock;
/**
 * 
 */
UCLASS()
class MECHABATTLES_API USpinBoxWithNameVector2 : public UUserWidget
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget), Category = "Components")
	UTextBlock* SpinBoxName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget), Category = "Components")
	USpinBox* SpinBoxX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget), Category = "Components")
	USpinBox* SpinBoxY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	FText Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	FVector2D MinMaxSlider;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	FVector2D MinMaxValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	FIntPoint MinMaxFractionalDigits;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	FVector2D Value;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	bool bAlwaysSnap;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	float Delta;

	UPROPERTY(BlueprintAssignable, Category = "SpinBox")
	FOnSpinBoxVector2XValueChanged OnSpinBoxVector2XValueChanged;
	UPROPERTY(BlueprintAssignable, Category = "SpinBox")
	FOnSpinBoxVector2YValueChanged OnSpinBoxVector2YValueChanged;

	UFUNCTION(BlueprintCallable, Category = "SpinBox")
	void SetValue(FVector2D NewValue);
	

protected:
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;

	UFUNCTION()
	void HandleValueXChanged(float NewValueX);
	UFUNCTION()
	void HandleValueYChanged(float NewValueY);

private:
	void SetInitialValues();
};
