// Developed by Neko


#include "Combat/CombatSystem.h"

#include "Mecha/MechaActor.h"


ACombatSystem::ACombatSystem()
{
 	
	PrimaryActorTick.bCanEverTick = true;

}

void ACombatSystem::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACombatSystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



