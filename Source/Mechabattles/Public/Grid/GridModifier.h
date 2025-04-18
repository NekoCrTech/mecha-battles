// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "TileData.h"
#include "GameFramework/Actor.h"
#include "GridModifier.generated.h"

UCLASS()
class MECHABATTLES_API AGridModifier : public AActor
{
	GENERATED_BODY()
	
public:	
	AGridModifier();
	UPROPERTY(EditAnywhere)
	ETileType TileType = ETileType::Obstacle;

protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Modifier Mesh")
	TObjectPtr<UStaticMesh> ModifierMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Modifier Mesh")
	TObjectPtr<UMaterialInstance> ModifierMaterial;

private:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Components", meta=(AllowPrivateAccess=true))
	TObjectPtr<USceneComponent> Root;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Components", meta=(AllowPrivateAccess=true))
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;

	UFUNCTION(BlueprintCallable)
	void SetGridModifier();

};
