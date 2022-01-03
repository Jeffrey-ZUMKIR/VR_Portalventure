// Fill out your copyright notice in the Description page of Project Settings.


#include "GrabbableObject.h"

// Sets default values
AGrabbableObject::AGrabbableObject()
{
	//this->SetMobility(EComponentMobility::Movable);
	//TheRoot = CreateDefaultSubObject<USceneComponent>(TEXT("Root"));
	//TheRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	//TheRoot->SetupAttachment(GetRootComponent());

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetSimulatePhysics(true);
	SetRootComponent(Mesh);

	isGrabbed = false;
	//Mesh->SetupAttachment(TheRoot);
}

// Called when the game starts or when spawned
void AGrabbableObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGrabbableObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

UStaticMeshComponent* AGrabbableObject::GetMesh(){
	return this->Mesh;
}

void AGrabbableObject::SetMeshPhysic(bool hisPhysic){
	Mesh->SetSimulatePhysics(hisPhysic);
	//Mesh->SetEnableGravity(hisPhysic);
}



