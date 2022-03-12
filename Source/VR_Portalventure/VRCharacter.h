// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "Camera/CameraComponent.h"
#include "Animation/BlendSpace1D.h"
#include "GrabbableObject.h"


#include "VRCharacter.generated.h"



UCLASS()
class VR_PORTALVENTURE_API AVRCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AVRCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void moveForwardBackward(float moveY);
	void moveRightLeft(float moveX);

	void moveRightHandFingerGrab(float moveF);
	void moveLeftHandFingerGrab(float moveF);

	void moveRightHandFingerTrig(float moveF);
	void moveLeftHandFingerTrig(float moveF);

	void grabLeftHand();
	void releaseLeftHand();

	void grabRightHand();
	void releaseRightHand();

	void pressLeft();
	void pressRight();

private:
	UPROPERTY()
	class UCameraComponent* Camera;

	UPROPERTY()
	class USceneComponent * VRRoot;

	UPROPERTY()
	class AHandController* TheRightController;

	UPROPERTY()
	class AHandController* TheLeftController;

	UPROPERTY(EditAnywhere, Category = "Anims")
    UBlendSpace1D *BlendSpace;

	UPROPERTY()
	USkeletalMeshComponent *MyMesh;



private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AHandController> HandControllerClass;

};
