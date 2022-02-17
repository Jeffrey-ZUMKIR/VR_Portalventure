// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ChangeBulbColor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBulbEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VR_PORTALVENTURE_API UChangeBulbColor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UChangeBulbColor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable)
		FBulbEvent ChangeColorRequest;

	UPROPERTY(BlueprintAssignable)
		FBulbEvent ChangeMatRequest;

	void ChangeBulbColor();

	void ChangeMatColor();
		
};
