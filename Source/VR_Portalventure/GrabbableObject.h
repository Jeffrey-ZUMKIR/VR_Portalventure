// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "Engine/StaticMeshActor.h"
#include "Engine/StaticMesh.h"
#include "GrabbableObject.generated.h"

UCLASS()
class VR_PORTALVENTURE_API AGrabbableObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGrabbableObject();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UStaticMeshComponent* GetMesh();
	void SetMeshPhysic(bool hisPhysic);

	bool isGrabbed;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

private:
	UPROPERTY()
	class USceneComponent* TheRoot;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent * Mesh;

};
