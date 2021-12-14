// Fill out your copyright notice in the Description page of Project Settings.


#include "VRCharacter.h"

#include "Components/InputComponent.h"
#include "MotionControllerComponent.h"
#include "HandController.h"
#include "Animation/SkeletalMeshActor.h"
#include "Components/SkeletalMeshComponent.h"
#include "Animation/AnimSingleNodeInstance.h"

// Sets default values
AVRCharacter::AVRCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VRRoot = CreateDefaultSubobject<USceneComponent>(TEXT("VRRoot"));
	VRRoot->SetupAttachment(GetRootComponent());

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(VRRoot);

}

// Called when the game starts or when spawned
void AVRCharacter::BeginPlay()
{
	Super::BeginPlay();

	TheLeftController = GetWorld()->SpawnActor<AHandController>(HandControllerClass);
	if(TheLeftController != nullptr){
		TheLeftController->AttachToComponent(VRRoot, FAttachmentTransformRules::KeepRelativeTransform);
		TheLeftController->SetHand(EControllerHand::Left);
		TheLeftController->SetOwner(this);
		FVector handPosition(1,-1,1);
		TheLeftController->SetActorScale3D(handPosition);
	}else{
		UE_LOG(LogTemp, Warning, TEXT("Nothing"));
	}

	TheRightController = GetWorld()->SpawnActor<AHandController>(HandControllerClass);
	if(TheRightController != nullptr){
		TheRightController->AttachToComponent(VRRoot, FAttachmentTransformRules::KeepRelativeTransform);
		TheRightController->SetHand(EControllerHand::Right);
		TheRightController->SetOwner(this);
	}


	/*ASkeletalMeshActor *Skel = Cast<ASkeletalMeshActor>(TheRightController);
    if (Skel != nullptr)
    {
        MyMesh = Skel->GetSkeletalMeshComponent();
        if (MyMesh != nullptr)
        {
            //MyMesh->PlayAnimation(BlendSpace, true);
           // FVector BlendParams(50.0f, 0.0f, 0.0f);
            //MyMesh->GetSingleNodeInstance()->SetBlendSpaceInput(BlendParams);
        }
   }*/

   
	
}

// Called every frame
void AVRCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

// Called to bind functionality to input
void AVRCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("GoForwardBackward"), this, &AVRCharacter::moveForwardBackward);
	PlayerInputComponent->BindAxis(TEXT("GoRightLeft"), this, &AVRCharacter::moveRightLeft);

	PlayerInputComponent->BindAxis(TEXT("GrabRight"), this, &AVRCharacter::moveRightHandFinger);
	PlayerInputComponent->BindAxis(TEXT("GrabLeft"), this, &AVRCharacter::moveLeftHandFinger);
}

void AVRCharacter::moveForwardBackward(float moveY){
	AddMovementInput(Camera->GetForwardVector(),moveY/2);
}

void AVRCharacter::moveRightLeft(float moveX){
	AddMovementInput(Camera->GetRightVector(),moveX/2);
}

void AVRCharacter::moveRightHandFinger(float moveF){
	TheRightController->handPower = moveF;
	//UE_LOG(LogTemp, Warning, TEXT("%f"), moveF);
	//FVector BlendParams(50.0f, 0.0f, 0.0f);
    //MyMesh->GetSingleNodeInstance()->SetBlendSpaceInput(BlendParams);
}

void AVRCharacter::moveLeftHandFinger(float moveF){
	TheLeftController->handPower = moveF;
	//UE_LOG(LogTemp, Warning, TEXT("%f"), moveF);
	//FVector BlendParams(50.0f, 0.0f, 0.0f);
    //MyMesh->GetSingleNodeInstance()->SetBlendSpaceInput(BlendParams);
}

