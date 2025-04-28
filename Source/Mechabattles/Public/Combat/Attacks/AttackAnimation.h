// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AttackAnimation.generated.h"

class AGrid;

UCLASS()
class MECHABATTLES_API AAttackAnimation : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAttackAnimation();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "References", meta = (ExposeOnSpawn = "true"))
	AGrid* Grid = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Location", meta = (ExposeOnSpawn = "true"))
	FIntPoint OriginIndex = FIntPoint(-999,-999);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Location", meta = (ExposeOnSpawn = "true"))
	TArray<FIntPoint> TargetIndexes = TArray<FIntPoint>();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
