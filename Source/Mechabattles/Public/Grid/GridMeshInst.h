// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "GridShapeData.h"
#include "GameFramework/Actor.h"
#include "GridMeshInst.generated.h"

UCLASS()
class MECHABATTLES_API AGridMeshInst : public AActor
{
	GENERATED_BODY()
	
public:	
	AGridMeshInst();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UInstancedStaticMeshComponent* InstancedStaticMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FIntPoint> InstanceIndexes;

	UFUNCTION(BlueprintCallable)
	void InitializeGridMeshInst(FGridShapeData GridShapeData, FVector Color, ECollisionEnabled::Type Collision);

	UFUNCTION(BlueprintCallable)
	void AddInstance(FTransform Transform, FIntPoint Index);

	UFUNCTION(BlueprintCallable)
	void RemoveInstance(FIntPoint IndexToRemove);

	UFUNCTION(BlueprintCallable)
	void ClearInstances();

protected:
	virtual void BeginPlay() override;
};
