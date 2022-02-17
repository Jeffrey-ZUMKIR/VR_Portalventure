// Fill out your copyright notice in the Description page of Project Settings.


#include "ColorBulb.h"

// Sets default values
AColorBulb::AColorBulb()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TheColor = 0;

}

// Called when the game starts or when spawned
void AColorBulb::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AColorBulb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

