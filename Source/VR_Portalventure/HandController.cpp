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

}

// Called when the game starts or when spawned
void AHandController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHandController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ASkeletalMeshActor *Skel = Cast<ASkeletalMeshActor>(this);
    if (Skel != nullptr)
    {
        MyMesh = Skel->GetSkeletalMeshComponent();
        if (MyMesh != nullptr)
        {
			//MyMesh->GetAnimInstance()
            //MyMesh->PlayAnimation(BlendSpace, true);
           // FVector BlendParams(50.0f, 0.0f, 0.0f);
            //MyMesh->GetSingleNodeInstance()->SetBlendSpaceInput(BlendParams);
        }
   }
}

