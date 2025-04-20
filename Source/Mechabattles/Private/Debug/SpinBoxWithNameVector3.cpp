// Neko Creative Technologies


#include "Debug/SpinBoxWithNameVector3.h"

#include "Components/SpinBox.h"
#include "Components/TextBlock.h"



void USpinBoxWithNameVector3::NativePreConstruct()
{
	Super::NativePreConstruct();
	SetInitialValues();
}

void USpinBoxWithNameVector3::NativeConstruct()
{
	Super::NativeConstruct();
	if (SpinBoxX && SpinBoxY && SpinBoxZ)
	{
		SpinBoxX->OnValueChanged.AddDynamic(this, &USpinBoxWithNameVector3::HandleValueXChanged);
		SpinBoxY->OnValueChanged.AddDynamic(this, &USpinBoxWithNameVector3::HandleValueYChanged);
		SpinBoxZ->OnValueChanged.AddDynamic(this, &USpinBoxWithNameVector3::HandleValueZChanged);
	}
}

void USpinBoxWithNameVector3::HandleValueXChanged(float NewValueX)
{
	Value.X = NewValueX;
	SpinBoxX->SetValue(NewValueX);
	SetValue(Value);
	OnSpinBoxXValueChanged.Broadcast(NewValueX);
}

void USpinBoxWithNameVector3::HandleValueYChanged(float NewValueY)
{
	Value.Y = NewValueY;
	SpinBoxY->SetValue(NewValueY);
	SetValue(Value);
	OnSpinBoxYValueChanged.Broadcast(NewValueY);
}

void USpinBoxWithNameVector3::HandleValueZChanged(float NewValueZ)
{
	Value.Z = NewValueZ;
	SpinBoxZ->SetValue(NewValueZ);
	SetValue(Value);
	OnSpinBoxZValueChanged.Broadcast(NewValueZ);
}

void USpinBoxWithNameVector3::SetValue(FVector NewValue)
{
	Value = NewValue;
	SpinBoxX->SetValue(NewValue.X);
	SpinBoxY->SetValue(NewValue.Y);
	SpinBoxZ->SetValue(NewValue.Z);
}

void USpinBoxWithNameVector3::SetInitialValues()
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

	SpinBoxZ->SetMinSliderValue(MinMaxSlider.X);
	SpinBoxZ->SetMaxSliderValue(MinMaxSlider.Y);
	SpinBoxZ->SetMinValue(MinMaxValue.X);
	SpinBoxZ->SetMaxValue(MinMaxValue.Y);
	SpinBoxZ->SetMinFractionalDigits(MinMaxFractionalDigits.X);
	SpinBoxZ->SetMaxFractionalDigits(MinMaxFractionalDigits.Y);
	SpinBoxZ->SetValue(Value.Z);
	SpinBoxZ->SetAlwaysUsesDeltaSnap(bAlwaysSnap);
	SpinBoxZ->SetDelta(Delta);
}
