// Fill out your copyright notice in the Description page of Project Settings.


#include "HandController.h"

#include "Animation/SkeletalMeshActor.h"
#include "Components/SkeletalMeshComponent.h"



// Sets default values
AHandController::AHandController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("Motion controller"));
	SetRootComponent(MotionController);
	MotionController->bDisplayDeviceModel = true;

    MySkelMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Hand skel"));
    MySkelMesh->SetupAttachment(MotionController);

    ScHand = CreateDefaultSubobject<USceneComponent>(TEXT("ScHand"));
    ScHand->SetupAttachment(MySkelMesh);
}

// Called when the game starts or when spawned
void AHandController::BeginPlay()
{
	Super::BeginPlay();
    UE_LOG(LogTemp, Warning, TEXT("Hello"));
    ASkeletalMeshActor *Skel = Cast<ASkeletalMeshActor>(this);
    if (Skel != nullptr)
    {
        UE_LOG(LogTemp, Warning, TEXT("Get skelet"));
        MyMesh = Skel->GetSkeletalMeshComponent();
        if (MyMesh != nullptr)
        {
            UE_LOG(LogTemp, Warning, TEXT("Get mesh"));
        }
   }
	
}

// Called every frame
void AHandController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHandController::GrabObject(AHandController *otherController){
    UE_LOG(LogTemp, Warning, TEXT("Grab right"));
	TArray<AActor*> outoverlap;
	this->GetOverlappingActors(outoverlap);

	if(outoverlap.Num() > 0){
		//UE_LOG(LogTemp, Warning, TEXT("Object overlap %s"), *outoverlap[0]->GetName());

		bool bFindObject = false;
		int check = outoverlap.Num()-1;
		AGrabbableObject* trycast = nullptr;
		while (bFindObject == false)
		{
			trycast = dynamic_cast<AGrabbableObject*>(outoverlap[check]);
			if(trycast != nullptr || check <= 0){
				bFindObject = true;
			}
			check--;
		}
		
		//AGrabbableObject* trycast = dynamic_cast<AGrabbableObject*>(outoverlap[0]);
		UE_LOG(LogTemp, Warning, TEXT("%d"), outoverlap.Num());
		if(trycast != nullptr){
			if(trycast->isGrabbed == true){
				otherController->thingGrabbed = nullptr;
			}
			UE_LOG(LogTemp, Warning, TEXT("Object overlap %s"), *trycast->GetName());
			trycast->SetMeshPhysic(false);
			trycast->AttachToComponent(this->GetSkelMesh(),FAttachmentTransformRules::KeepWorldTransform);
			thingGrabbed = trycast;
			trycast->isGrabbed = true;
		}
	}
}

void AHandController::LetGoObject(){
	if(thingGrabbed != nullptr){
		thingGrabbed->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		thingGrabbed->SetMeshPhysic(true);
		thingGrabbed->isGrabbed = false;
		thingGrabbed = nullptr;
	}
}

