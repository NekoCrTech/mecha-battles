// Neko Creative Technologies

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SpinBoxWithNameVector3.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSpinBoxXValueChanged, float, NewValueX);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSpinBoxYValueChanged, float, NewValueY);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSpinBoxZValueChanged, float, NewValueZ);

class USpinBox;
class UTextBlock;
/**
 * 
 */
UCLASS()
class MECHABATTLES_API USpinBoxWithNameVector3 : public UUserWidget
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget), Category = "Components")
	UTextBlock* SpinBoxName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget), Category = "Components")
	USpinBox* SpinBoxX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget), Category = "Components")
	USpinBox* SpinBoxY;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget), Category = "Components")
	USpinBox* SpinBoxZ;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	FText Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	FVector2D MinMaxSlider;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	FVector2D MinMaxValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	FIntPoint MinMaxFractionalDigits;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	FVector Value;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	bool bAlwaysSnap;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	float Delta;

	UPROPERTY(BlueprintAssignable, Category = "SpinBox")
	FOnSpinBoxXValueChanged OnSpinBoxXValueChanged;
	UPROPERTY(BlueprintAssignable, Category = "SpinBox")
	FOnSpinBoxYValueChanged OnSpinBoxYValueChanged;
	UPROPERTY(BlueprintAssignable, Category = "SpinBox")
	FOnSpinBoxZValueChanged OnSpinBoxZValueChanged;

	UFUNCTION(BlueprintCallable, Category = "SpinBox")
	void SetValue(FVector NewValue);

protected:
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;

	UFUNCTION()
	void HandleValueXChanged(float NewValueX);
	UFUNCTION()
	void HandleValueYChanged(float NewValueY);
	UFUNCTION()
	void HandleValueZChanged(float NewValueZ);

private:
	void SetInitialValues();
};
