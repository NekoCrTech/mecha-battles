// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TechnicComponent.generated.h"


class UTechnicDataAsset;

UCLASS( Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MECHABATTLES_API UTechnicComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UTechnicComponent();

	UFUNCTION(BlueprintCallable)
	void AwardTechnicPoint(int32 TechnicPoints);

	UFUNCTION(BlueprintCallable)
	void SpendTechnicPoint(int32 TechnicPoints);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool QueryTechnicPoints(int32 Query) const;

	UFUNCTION(BlueprintCallable)
	void LearnTechnic(UTechnicDataAsset* Technic);

	UFUNCTION(BlueprintCallable)
	void AddTechnicIdea(UTechnicDataAsset* Technic);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool QueryTechnic(UTechnicDataAsset* Technic) const;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Technic", meta = (AllowPrivateAccess = "true"))
	int32 TechnicPointsAvailable = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Technic", meta = (AllowPrivateAccess = "true"))
	TArray<UTechnicDataAsset*> KnownTechnics;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Technic", meta = (AllowPrivateAccess = "true"))
	TArray<UTechnicDataAsset*> TechnicIdeas;
};
