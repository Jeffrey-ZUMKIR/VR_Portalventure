// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MotionControllerComponent.h"
#include "GrabbableObject.h"
#include "IsGrabbable.h"
#include "IsPressable.h"
#include "PressableObject.h"
#include "IsRotable.h"
#include "Engine/EngineTypes.h"
#include "HandController.generated.h"

UCLASS()
class VR_PORTALVENTURE_API AHandController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHandController();

	void SetHand(EControllerHand Hand){
		MotionController->SetTrackingSource(Hand);
	}

	USkeletalMeshComponent* GetSkelMesh(){
		return MySkelMesh;
	}

	USceneComponent* GetScHand(){
		return ScHand;
	}

	void GrabObject(AHandController *otherController);

	void LetGoObject();

	void PressObject();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float handPower = 0.f;

	float handPowerGrab = 0.f;
	float handPowerTrig = 0.f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere)
	class UMotionControllerComponent* MotionController;

	UPROPERTY(EditAnywhere)
	USkeletalMeshComponent *MySkelMesh;

	UPROPERTY(EditAnywhere)
	class USceneComponent *ScHand;

	UPROPERTY()
	USkeletalMeshComponent *MyMesh;

	UPROPERTY()
	AGrabbableObject* thingGrabbed;

	UPROPERTY()
		UIsRotable* thingRotate;

	UPROPERTY()
		UIsGrabbable* thingGrabbed2;
};
