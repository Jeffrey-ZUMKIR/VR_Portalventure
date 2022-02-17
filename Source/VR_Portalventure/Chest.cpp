// Fill out your copyright notice in the Description page of Project Settings.


#include "Chest.h"

// Sets default values
AChest::AChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TheRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(TheRoot);

	BottomChest = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BottomChest"));
	BottomChest->SetupAttachment(TheRoot);

	PivotChest = CreateDefaultSubobject<UIsRotable>(TEXT("PivotChest"));
	//TheRoot->GetRelativeLocation().X;
	PivotChest->SetScenePosition(TheRoot->GetRelativeLocation().X + 0, TheRoot->GetRelativeLocation().Y -37, TheRoot->GetRelativeLocation().Z + 51);
	PivotChest->SetRotateX(true);
	PivotChest->SetMinX(0);
	PivotChest->SetMaxX(-90);
	this->AddOwnedComponent(PivotChest);

	TopChest = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TopChest"));
	TopChest->SetupAttachment(PivotChest->GetSceneComp());
}

// Called when the game starts or when spawned
void AChest::BeginPlay()
{
	Super::BeginPlay();
	
	for (size_t i = 0; i < Cadenas.Num(); i++)
	{
		if (Cadenas[i] != nullptr) {
			Cadenas[i]->AttachToComponent(this->GetRootComponent(), FAttachmentTransformRules::KeepWorldTransform);
			//Cadenas[i]->SetHisParent(this);
		}
	}

	IsCodeFound = false;
	Lock = true;
}

// Called every frame
void AChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

void AChest::CheckCode()
{
	bool IsCodeCorrect = true;
	for (size_t i = 0; i < Code.Num(); i++)
	{
		if (Code[i] != Cadenas[i]->GetN_val()) {
			IsCodeCorrect = false;
		}
	}

	Lock = !IsCodeCorrect;
	if (IsCodeCorrect == true) {
		PivotChest->SetIsCodeFound(true);
		for (size_t i = 0; i < Cadenas.Num(); i++)
		{
			if (Cadenas[i] != nullptr) {
				Cadenas[i]->SetIsCodeFound(true);
			}
		}
	}
}

