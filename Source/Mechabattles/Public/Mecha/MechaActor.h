// Developed by Neko

#pragma once

#include "CoreMinimal.h"
#include "MechaData.h"
#include "GameFramework/Actor.h"
#include "MechaActor.generated.h"

UCLASS()
class MECHABATTLES_API AMechaActor : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AMechaActor();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FIntPoint IndexOnGrid = FIntPoint(-999, -999);

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Bools)
	bool bIsHovered = false;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Bools)
	bool bIsSelected = false;

protected:
	
	virtual void BeginPlay() override;


private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USkeletalMeshComponent> Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USceneComponent> Root;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Components, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USceneCaptureComponent2D> CaptureComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data, meta = (AllowPrivateAccess = "true"))
	FMechaData Data;

};
