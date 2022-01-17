// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "Engine/StaticMesh.h"
#include "PressableObject.h"
#include "IsRotable.h"
#include "Components/ActorComponent.h"
#include "Ambry.generated.h"

UCLASS()
class VR_PORTALVENTURE_API AAmbry : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAmbry();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UIsRotable* PivotAmbry1;

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UIsRotable* PivotAmbry2;*/

private:
	UPROPERTY()
		class USceneComponent* TheRoot;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* AmbryMesh;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* AmbryDoorMesh1;

	UPROPERTY(EditAnywhere)
		class USceneComponent* PivotAmbry2;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* AmbryDoorMesh2;

};
