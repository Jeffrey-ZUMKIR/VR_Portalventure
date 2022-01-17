// Fill out your copyright notice in the Description page of Project Settings.


#include "IsPressable.h"

// Sets default values for this component's properties
UIsPressable::UIsPressable()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	//PressBox = CreateDefaultSubobject<UBoxComponent>(TEXT("PressBox"));
	//SetRootComponent(PressBox);
	//PressMesh->SetupAttachment(GetOwner());

	// ...
}


// Called when the game starts
void UIsPressable::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UIsPressable::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

