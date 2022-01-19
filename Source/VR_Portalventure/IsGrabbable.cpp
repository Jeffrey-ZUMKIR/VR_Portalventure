// Fill out your copyright notice in the Description page of Project Settings.


#include "IsGrabbable.h"

// Sets default values for this component's properties
UIsGrabbable::UIsGrabbable()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UIsGrabbable::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UIsGrabbable::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UIsGrabbable::SetMeshPhysic(bool hisPhysic) {
	GetOwner()->FindComponentByClass<UPrimitiveComponent>()->SetSimulatePhysics(hisPhysic);
}

