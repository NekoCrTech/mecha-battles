// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Grid/Grid.h"
#include "CombatSystem.generated.h"


class AMechaActor;

UCLASS()
class MECHABATTLES_API ACombatSystem : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ACombatSystem();
	virtual void Tick(float DeltaTime) override;


	

protected:
	
	virtual void BeginPlay() override;
	

};
