// Fill out your copyright notice in the Description page of Project Settings.


#include "PressableObject.h"

// Sets default values
APressableObject::APressableObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TheRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(TheRoot);

	UpMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("UpMesh"));
	UpMesh->SetupAttachment(TheRoot);

	DownMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DownMesh"));
	DownMesh->SetupAttachment(TheRoot);

}

// Called when the game starts or when spawned
void APressableObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APressableObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

