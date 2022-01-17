// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "Engine/StaticMesh.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"
#include "PressableObject.generated.h"

/*Faire deux objects comme ça dans une autre classe pour un qui fait + et l'autre qui fait -*/

UCLASS()
class VR_PORTALVENTURE_API APressableObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APressableObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void IsPressed();

	UFUNCTION()
	void OnEnterUpBox(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnExitUpBox(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void OnEnterDownBox(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnExitDownBox(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	void AddToN_val(int add_val);

	int32 GetN_val();

	//void SetHisParent(AChest* parent);

	void SetIsCodeFound(bool IsCode);

private:
	UPROPERTY()
	class USceneComponent* TheRoot;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent * UpMesh;

	UPROPERTY(EditAnywhere)
	class UBoxComponent* UpBox;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent * DownMesh;

	UPROPERTY(EditAnywhere)
	class UBoxComponent* DownBox;

	UPROPERTY()
	int32 n_val;

	UPROPERTY(EditAnywhere)
		UTextRenderComponent* ValCadena;

	/*UPROPERTY(EditAnywhere)
		AChest *HisParent;*/

	bool UpBoxEnter;
	bool DownBoxEnter;

	bool IsCodeFound;

};
