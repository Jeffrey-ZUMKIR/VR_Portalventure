// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/SceneComponent.h"
#include "Engine/StaticMesh.h"
#include "IsRotable.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VR_PORTALVENTURE_API UIsRotable : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UIsRotable();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	USceneComponent* GetSceneComp();

	bool GetRotateState();

	void SetScenePosition(float x, float y, float z);

	void SetVectHand(FVector newHandPos);

	void SetRotate(bool newRotate);

	void SetRotateX(bool newRotate);
	void SetRotateY(bool newRotate);
	void SetRotateZ(bool newRotate);

	void SetMinX(float newX);
	void SetMaxX(float newX);

	void SetMinY(float newY);
	void SetMaxY(float newY);

	void SetMinZ(float newZ);
	void SetMaxZ(float newZ);

	void SetNewAngleX();

	void SetNewAngleZ();

	//float CalculateNewAngle();

	void SetIsCodeFound(bool IsCode);

private:
	UPROPERTY(EditAnywhere)
		class USceneComponent* Pivot;

	FVector scPos;

	/*UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* TopChest;*/

	/*UPROPERTY(EditAnywhere)
		class UStaticMesh* TheMesh;*/

	FVector handPos;

	bool rotate;

	bool rotateX;
	bool rotateY;
	bool rotateZ;

	float minX;
	float maxX;

	float minY;
	float maxY;

	UPROPERTY(EditAnywhere)
	float minZ;
	UPROPERTY(EditAnywhere)
	float maxZ;

	UPROPERTY(EditAnywhere)
	float InitialYaw;

	bool IsCodeFound;
};
