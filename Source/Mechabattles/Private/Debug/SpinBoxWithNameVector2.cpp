// Neko Creative Technologies


#include "Debug/SpinBoxWithNameVector2.h"

#include "Components/SpinBox.h"
#include "Components/TextBlock.h"



void USpinBoxWithNameVector2::NativePreConstruct()
{
	Super::NativePreConstruct();
	SetInitialValues();
}

void USpinBoxWithNameVector2::NativeConstruct()
{
	Super::NativeConstruct();
	if (SpinBoxX && SpinBoxY )
	{
		SpinBoxX->OnValueChanged.AddDynamic(this, &USpinBoxWithNameVector2::HandleValueXChanged);
		SpinBoxY->OnValueChanged.AddDynamic(this, &USpinBoxWithNameVector2::HandleValueYChanged);
	}
}

void USpinBoxWithNameVector2::HandleValueXChanged(float NewValueX)
{
	Value.X = NewValueX;
	SpinBoxX->SetValue(NewValueX);
	SetValue(Value);
	OnSpinBoxVector2XValueChanged.Broadcast(NewValueX);
}

void USpinBoxWithNameVector2::HandleValueYChanged(float NewValueY)
{
	Value.Y = NewValueY;
	SpinBoxY->SetValue(NewValueY);
	SetValue(Value);
	OnSpinBoxVector2YValueChanged.Broadcast(NewValueY);
}

void USpinBoxWithNameVector2::SetValue(FVector2D NewValue)
{
	Value = NewValue;
	SpinBoxX->SetValue(NewValue.X);
	SpinBoxY->SetValue(NewValue.Y);
}



void USpinBoxWithNameVector2::SetInitialValues()
{
	SpinBoxName->SetText(Name);

	SpinBoxX->SetMinSliderValue(MinMaxSlider.X);
	SpinBoxX->SetMaxSliderValue(MinMaxSlider.Y);
	SpinBoxX->SetMinValue(MinMaxValue.X);
	SpinBoxX->SetMaxValue(MinMaxValue.Y);
	SpinBoxX->SetMinFractionalDigits(MinMaxFractionalDigits.X);
	SpinBoxX->SetMaxFractionalDigits(MinMaxFractionalDigits.Y);
	SpinBoxX->SetValue(Value.X);
	SpinBoxX->SetAlwaysUsesDeltaSnap(bAlwaysSnap);
	SpinBoxX->SetDelta(Delta);

	SpinBoxY->SetMinSliderValue(MinMaxSlider.X);
	SpinBoxY->SetMaxSliderValue(MinMaxSlider.Y);
	SpinBoxY->SetMinValue(MinMaxValue.X);
	SpinBoxY->SetMaxValue(MinMaxValue.Y);
	SpinBoxY->SetMinFractionalDigits(MinMaxFractionalDigits.X);
	SpinBoxY->SetMaxFractionalDigits(MinMaxFractionalDigits.Y);
	SpinBoxY->SetValue(Value.Y);
	SpinBoxY->SetAlwaysUsesDeltaSnap(bAlwaysSnap);
	SpinBoxY->SetDelta(Delta);
}
