// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ColorBulb.h"
#include "ControlPanel.generated.h"


UCLASS()
class VR_PORTALVENTURE_API AControlPanel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AControlPanel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void CheckCode();

	UFUNCTION(BlueprintCallable)
		void PanelActivate(bool Activate);

	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> ClassToFind;

private:
	UPROPERTY(EditAnywhere)
		TArray<AColorBulb*> ColorBulb;

	UPROPERTY(EditAnywhere)
		TArray<int32> CodeColor;

	bool IsCodeFound;

};
