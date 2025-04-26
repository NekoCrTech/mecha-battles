// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Grid/TileData.h"
#include "Grid/Grid_Bugged.h"
#include "Grid/GridMeshInst.h"
#include "GridVisual.generated.h"


UCLASS()
class MECHABATTLES_API AGridVisual : public AActor
{
	GENERATED_BODY()
	
public:	
	AGridVisual();
	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TObjectPtr<USceneComponent> Scene;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TObjectPtr<UChildActorComponent> ChildActor;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Data")
	TSubclassOf<AActor> GridMeshInstClass;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Data")
	AGridMeshInst* GridMeshInst;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Grid")
	AGrid_Bugged* Grid;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Parameters")
	float OffsetFromGround = 2.f;

	UFUNCTION(BLueprintCallable)
	void InitializeGridVisual(AGrid_Bugged* InGrid);

	UFUNCTION(BlueprintCallable)
	void DestroyGridVisual() const;

	UFUNCTION(BlueprintCallable)
	void UpdateTileVisual(FTileData TileData);

	UFUNCTION(BlueprintCallable)
	void SetOffsetFromGround(float Offset);

protected:
	virtual void BeginPlay() override;
	
};
