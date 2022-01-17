// Fill out your copyright notice in the Description page of Project Settings.


#include "TopChest.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values for this component's properties
UTopChest::UTopChest()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	/*PrimaryComponentTick.bCanEverTick = true;

	Pivot = CreateDefaultSubobject<USceneComponent>(TEXT("Pivot"));
	FVector LocPivot = FVector(0.0f, -40.0f, 52.0f);
	Pivot->SetRelativeLocation(LocPivot);

	TopChest = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TheMesh"));
	//TopChest->SetStaticMesh(TheMesh);
	TopChest->SetupAttachment(Pivot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> TopChestMesh(TEXT("StaticMesh'/Game/AlchemistsHouse/Assets/Models/Chest_cover.Chest_cover'"));

	if (TopChestMesh.Succeeded()) {
		TopChest->SetStaticMesh(TopChestMesh.Object);
	}*/
	// ...
}

// Called when the game starts
void UTopChest::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void UTopChest::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}