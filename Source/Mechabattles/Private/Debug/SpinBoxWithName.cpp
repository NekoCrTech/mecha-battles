// Neko Creative Technologies


#include "Debug/SpinBoxWithName.h"

#include "Components/SpinBox.h"
#include "Components/TextBlock.h"



void USpinBoxWithName::NativePreConstruct()
{
	Super::NativePreConstruct();
	SetInitialValues();
}

void USpinBoxWithName::NativeConstruct()
{
	Super::NativeConstruct();
	if (SpinBox)
	{
		SpinBox->OnValueChanged.AddDynamic(this, &USpinBoxWithName::HandleValueChanged);
	}
}

void USpinBoxWithName::HandleValueChanged(float NewValue)
{
	Value = NewValue;
	SpinBox->SetValue(NewValue);
	OnSpinBoxValueChanged.Broadcast(NewValue);
}

void USpinBoxWithName::SetValue(float NewValue)
{
	Value = NewValue;
	SpinBox->SetValue(NewValue);
}

void USpinBoxWithName::SetInitialValues()
{
	SpinBoxName->SetText(Name);

	SpinBox->SetMinSliderValue(MinMaxSlider.X);
	SpinBox->SetMaxSliderValue(MinMaxSlider.Y);
	SpinBox->SetMinValue(MinMaxValue.X);
	SpinBox->SetMaxValue(MinMaxValue.Y);
	SpinBox->SetMinFractionalDigits(MinMaxFractionalDigits.X);
	SpinBox->SetMaxFractionalDigits(MinMaxFractionalDigits.Y);
	SpinBox->SetValue(Value);
	SpinBox->SetAlwaysUsesDeltaSnap(bAlwaysSnap);
	SpinBox->SetDelta(Delta);
}
