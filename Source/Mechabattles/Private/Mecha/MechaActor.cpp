// Developed by Neko


#include "Mecha/MechaActor.h"
#include "Components/SceneCaptureComponent2D.h"

// Sets default values
AMechaActor::AMechaActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;
	
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>("Mesh");
	Mesh->SetupAttachment(Root);

	CaptureComponent = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("CaptureComponent"));
	CaptureComponent->SetupAttachment(Root);
	CaptureComponent->SetRelativeLocation(FVector(150,0,90));
	CaptureComponent->SetRelativeRotation(FRotator(0,180,0));

}

// Called when the game starts or when spawned
void AMechaActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMechaActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

