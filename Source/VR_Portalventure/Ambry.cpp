// Fill out your copyright notice in the Description page of Project Settings.


#include "Ambry.h"

// Sets default values
AAmbry::AAmbry()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TheRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(TheRoot);

	AmbryMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AmbryMesh"));
	AmbryMesh->SetupAttachment(TheRoot);

	PivotAmbry1 = CreateDefaultSubobject<UIsRotable>(TEXT("PivotAmbry1"));
	PivotAmbry1->SetScenePosition(TheRoot->GetRelativeLocation().X - 60, TheRoot->GetRelativeLocation().Y + 33, TheRoot->GetRelativeLocation().Z + 50);
	PivotAmbry1->SetRotateZ(true);
	PivotAmbry1->SetMinZ(90);
	PivotAmbry1->SetMaxZ(0);
	this->AddOwnedComponent(PivotAmbry1);

	AmbryDoorMesh1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AmbryDoorMesh1"));
	AmbryDoorMesh1->SetupAttachment(PivotAmbry1->GetSceneComp());

	PivotAmbry2 = CreateDefaultSubobject<USceneComponent>(TEXT("Pivot2"));
	PivotAmbry2->SetupAttachment(TheRoot);
	/*PivotAmbry2 = CreateDefaultSubobject<UIsRotable>(TEXT("PivotAmbry2"));
	PivotAmbry2->SetScenePosition(TheRoot->GetRelativeLocation().X + 60, TheRoot->GetRelativeLocation().Y + 37, TheRoot->GetRelativeLocation().Z + 51);
	PivotAmbry2->SetRotateZ(true);
	PivotAmbry2->SetMinZ(0);
	PivotAmbry2->SetMaxZ(-90);
	this->AddOwnedComponent(PivotAmbry2);*/

	AmbryDoorMesh2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AmbryDoorMesh2"));
	//AmbryDoorMesh2->SetupAttachment(PivotAmbry2->GetSceneComp());
	AmbryDoorMesh2->SetupAttachment(PivotAmbry2);
}

// Called when the game starts or when spawned
void AAmbry::BeginPlay()
{
	Super::BeginPlay();
	
	PivotAmbry1->SetIsCodeFound(true);
	//PivotAmbry2->SetIsCodeFound(true);

}

// Called every frame
void AAmbry::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PivotAmbry1->GetRotateState() == true) {
		//UE_LOG(LogTemp, Warning, TEXT("Pivot 1 rotate"));
	}
	/*if (PivotAmbry2->GetRotateState() == true) {
		//UE_LOG(LogTemp, Warning, TEXT("Pivot 2 rotate"));
	}*/
}

