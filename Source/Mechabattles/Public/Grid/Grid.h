// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "GridShapeData.h"
#include "TileData.h"
#include "GameFramework/Actor.h"
#include "Grid.generated.h"

class AGridVisual;

UCLASS()
class MECHABATTLES_API AGrid : public AActor
{
	GENERATED_BODY()
	
public:	
	AGrid();
	virtual void Tick(float DeltaTime) override;
	virtual void OnConstruction(const FTransform& Transform) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UChildActorComponent> ChildActorGridVisual;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Data")
	TSubclassOf<AActor> GridVisualClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "GridData")
	TObjectPtr<AGridVisual> GridVisual;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "GridData")
	FGridShapeData GridShapeData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GridData")
	TMap<FIntPoint, FTileData> GridTiles;

	UFUNCTION(BlueprintCallable)
	void SpawnGrid(FVector CenterLocation, FVector TileSize, FIntPoint TileCount, bool bUseEnvironment);
	
	UFUNCTION(BlueprintCallable)
	void DestroyGrid();

	UFUNCTION(BlueprintCallable)
	void CalculateCenterAndBottomLeft(FVector& Center, FVector& BottomLeft);

	UFUNCTION(BlueprintCallable)
	FVector GetTileLocationFromGridIndex(FIntPoint GridIndex);

	UFUNCTION(BlueprintCallable)
	bool TraceForGround(FVector& InLocation, FVector& HitLocation, ETileType& TileType);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GridData")
	FVector GridCenterLocation = FVector(0, 0, 0);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GridData")
	FVector GridTileSize = FVector(200, 200, 100);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GridData")
	FIntPoint GridTileCount = FIntPoint(10, 10);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GridData")
	FVector GridBottomLeftCorner = FVector(0, 0, 0);

	UFUNCTION(BlueprintCallable)
	void GetCursorLocationOnGrid();

	UFUNCTION()
	void SpawnInstance(FIntPoint Index, bool bUseEnvironment);

	UFUNCTION()
	void AddGridTile(FTileData Data);

	UFUNCTION()
	int32 AdjustForOdd(int32 GridCount);

protected:
	virtual void BeginPlay() override;
	
	
	

};
