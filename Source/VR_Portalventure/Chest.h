// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "Engine/StaticMesh.h"
#include "PressableObject.h"
#include "IsRotable.h"
//#include "TopChest.h"
#include "Components/ActorComponent.h"
#include "Chest.generated.h"

UCLASS()
class VR_PORTALVENTURE_API AChest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void CheckCode();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UIsRotable* PivotChest;

private:
	UPROPERTY()
		class USceneComponent* TheRoot;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* BottomChest;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* TopChest;

	UPROPERTY(EditAnywhere)
		TArray<APressableObject*> Cadenas;



	UPROPERTY(EditAnywhere)
		TArray<int32> Code;

	UPROPERTY(EditAnywhere)
		TArray<int32> TempCode;
			
	bool IsCodeFound;

	bool Lock;
};
