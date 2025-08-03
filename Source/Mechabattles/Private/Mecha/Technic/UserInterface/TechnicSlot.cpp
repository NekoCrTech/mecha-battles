// Developed by Neko


#include "Mecha/Technic/UserInterface/TechnicSlot.h"

void UTechnicSlot::SetTechnic(UTechnicDataAsset* InTechnicData)
{
	TechnicData = InTechnicData;
	SetMaterial();
}
