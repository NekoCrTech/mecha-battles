// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AttackAnimation.generated.h"

class AGrid;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAttackAnimationHitTile, AAttackAnimation*, AttackAnim, FIntPoint, TargetIndex);

UCLASS(Blueprintable)
class MECHABATTLES_API AAttackAnimation : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAttackAnimation();

	UPROPERTY(BlueprintAssignable, Category = "Combat")
	FOnAttackAnimationHitTile OnAttackAnimationHitTile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "References", meta = (ExposeOnSpawn = "true"))
	AGrid* Grid = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Location", meta = (ExposeOnSpawn = "true"))
	FIntPoint OriginIndex = FIntPoint(-999,-999);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Location", meta = (ExposeOnSpawn = "true"))
	FIntPoint TargetIndex = FIntPoint(-999,-999);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Location", meta = (ExposeOnSpawn = "true"))
	TArray<FIntPoint> AttackedIndexes = TArray<FIntPoint>();

	UFUNCTION(BlueprintCallable, Category = "Combat")
	void AttackAnimationHitTile(AAttackAnimation* Animation, FIntPoint Index);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
