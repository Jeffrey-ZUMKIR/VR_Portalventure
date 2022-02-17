// Fill out your copyright notice in the Description page of Project Settings.


#include "ChangeBulbColor.h"

// Sets default values for this component's properties
UChangeBulbColor::UChangeBulbColor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UChangeBulbColor::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UChangeBulbColor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UChangeBulbColor::ChangeBulbColor() {
	ChangeColorRequest.Broadcast();
}

void UChangeBulbColor::ChangeMatColor() {
	ChangeMatRequest.Broadcast();
}

