// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "GridShapeData.h"
#include "TileData.h"
#include "GameFramework/Actor.h"
#include "Grid.generated.h"

UCLASS()
class MECHABATTLES_API AGrid : public AActor
{
	GENERATED_BODY()
	
public:	
	AGrid();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UInstancedStaticMeshComponent> InstancedStaticMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "GridData")
	FGridShapeData GridShapeData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GridData")
	float OffsetFromGround = 2.f;

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

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GridData")
	FVector GridCenterLocation = FVector(0, 0, 0);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GridData")
	FVector GridTileSize = FVector(200, 200, 100);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GridData")
	FIntPoint GridTileCount = FIntPoint(10, 10);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GridData")
	FVector GridBottomLeftCorner = FVector(0, 0, 0);

private:

	UFUNCTION()
	void SpawnInstance(FIntPoint Index, bool bUseEnvironment);

	UFUNCTION()
	void AddGridTile(FTileData Data);

	int32 AdjustForOdd(int32 GridCount);

	void SetGridOffsetFromGround(float Offset = 2.f);

	bool IsTileTypeWalkable(ETileType InTileType);


};
