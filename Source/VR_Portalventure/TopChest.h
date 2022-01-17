// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IsRotable.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "TopChest.generated.h"

/**
 * 
 */
UCLASS()
class VR_PORTALVENTURE_API UTopChest : public UIsRotable
{
	GENERATED_BODY()
	
public:
	// Sets default values for this component's properties
	UTopChest();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	/*UPROPERTY(EditAnywhere)
		class USceneComponent* Pivot;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* TopChest;*/
};
