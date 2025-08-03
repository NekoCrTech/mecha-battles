// Developed by Neko


#include "Mecha/Technic/TechnicComponent.h"

UTechnicComponent::UTechnicComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UTechnicComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UTechnicComponent::AwardTechnicPoint(const int32 TechnicPoints)
{
	TechnicPointsAvailable += TechnicPoints;
}

void UTechnicComponent::SpendTechnicPoint(const int32 TechnicPoints)
{
	if (QueryTechnicPoints(TechnicPoints))
	{
		TechnicPointsAvailable -= TechnicPoints;
	}
}

bool UTechnicComponent::QueryTechnicPoints(const int32 Query) const
{
	return TechnicPointsAvailable >= Query;
}

void UTechnicComponent::LearnTechnic(UTechnicDataAsset* Technic)
{
	KnownTechnics.Add(Technic);
}

void UTechnicComponent::AddTechnicIdea(UTechnicDataAsset* Technic)
{
	TechnicIdeas.Add(Technic);
}

bool UTechnicComponent::QueryTechnic(UTechnicDataAsset* Technic) const
{
	return KnownTechnics.Contains(Technic);
}




