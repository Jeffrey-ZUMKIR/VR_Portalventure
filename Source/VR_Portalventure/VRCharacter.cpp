// Fill out your copyright notice in the Description page of Project Settings.


#include "VRCharacter.h"

#include "Components/InputComponent.h"
#include "MotionControllerComponent.h"
#include "HandController.h"
//#include "Animation/SkeletalMeshActor.h"
#include "Components/SkeletalMeshComponent.h"
//#include "Animation/AnimSingleNodeInstance.h"
#include "Engine/StaticMeshActor.h"
#include "GameFramework/Actor.h"

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

	PlayerInputComponent->BindAxis(TEXT("MoveRightHandGrab"), this, &AVRCharacter::moveRightHandFingerGrab);
	PlayerInputComponent->BindAxis(TEXT("MoveLeftHandGrab"), this, &AVRCharacter::moveLeftHandFingerGrab);

	PlayerInputComponent->BindAxis(TEXT("MoveRightHandTrig"), this, &AVRCharacter::moveRightHandFingerTrig);
	PlayerInputComponent->BindAxis(TEXT("MoveLeftHandTrig"), this, &AVRCharacter::moveLeftHandFingerTrig);

	PlayerInputComponent->BindAction(TEXT("GrabLeft"), IE_Pressed, this, &AVRCharacter::grabLeftHand);
	PlayerInputComponent->BindAction(TEXT("GrabLeft"), IE_Released, this, &AVRCharacter::releaseLeftHand);

	PlayerInputComponent->BindAction(TEXT("GrabRight"), IE_Pressed, this, &AVRCharacter::grabRightHand);
	PlayerInputComponent->BindAction(TEXT("GrabRight"), IE_Released, this, &AVRCharacter::releaseRightHand);

	PlayerInputComponent->BindAction(TEXT("PressLeft"), IE_Pressed, this, &AVRCharacter::pressLeft);
	PlayerInputComponent->BindAction(TEXT("PressRight"), IE_Pressed, this, &AVRCharacter::pressRight);
}

void AVRCharacter::moveForwardBackward(float moveY){
	AddMovementInput(Camera->GetForwardVector(),moveY/2);
}

void AVRCharacter::moveRightLeft(float moveX){
	AddMovementInput(Camera->GetRightVector(),moveX/2);
}

void AVRCharacter::moveRightHandFingerGrab(float moveF){
	TheRightController->handPowerGrab = (moveF / 10) * 8;
	TheRightController->handPower = TheRightController->handPowerGrab + TheRightController->handPowerTrig;
}

void AVRCharacter::moveLeftHandFingerGrab(float moveF){
	TheLeftController->handPowerGrab = (moveF / 10) * 8;
	TheLeftController->handPower = TheLeftController->handPowerGrab + TheLeftController->handPowerTrig;
}

void AVRCharacter::moveRightHandFingerTrig(float moveF) {
	TheRightController->handPowerTrig = (moveF / 10) * 2;
	TheRightController->handPower = TheRightController->handPowerGrab + TheRightController->handPowerTrig;
}

void AVRCharacter::moveLeftHandFingerTrig(float moveF) {
	TheLeftController->handPowerTrig = (moveF / 10) * 2;
	TheLeftController->handPower = TheLeftController->handPowerGrab + TheLeftController->handPowerTrig;
}

void AVRCharacter::grabLeftHand(){
	TheLeftController->GrabObject(TheRightController);
	UE_LOG(LogTemp, Warning, TEXT("Grab left"));
}

void AVRCharacter::releaseLeftHand(){
	TheLeftController->LetGoObject();
	UE_LOG(LogTemp, Warning, TEXT("Release left"));
}

void AVRCharacter::grabRightHand(){
	TheRightController->GrabObject(TheLeftController);
	
}

void AVRCharacter::releaseRightHand(){
	TheRightController->LetGoObject();
	UE_LOG(LogTemp, Warning, TEXT("Release right"));
}

void AVRCharacter::pressLeft(){
	TheLeftController->PressObject();
	UE_LOG(LogTemp, Warning, TEXT("Press left"));
}

void AVRCharacter::pressRight(){
	TheRightController->PressObject();
	UE_LOG(LogTemp, Warning, TEXT("Press right"));
}

