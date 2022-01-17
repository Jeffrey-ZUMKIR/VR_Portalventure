// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/KismetMathLibrary.h"
#include "IsRotable.h"

// Sets default values for this component's properties
UIsRotable::UIsRotable()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	/*Pivot = CreateDefaultSubobject<USceneComponent>(TEXT("Pivot"));

	TopChest = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TheMesh"));
	//TopChest->SetStaticMesh(TheMesh);
	TopChest->SetupAttachment(Pivot);*/

	/*TArray<USceneComponent*> TabSceneComp;

	GetComponents(TabSceneComp);*/


	Pivot = CreateDefaultSubobject<USceneComponent>(TEXT("Pivot"));

	rotate = false;

	rotateX = false;
	rotateY = false;
	rotateZ = false;

	IsCodeFound = false;

	/*minX = Pivot->GetRelativeRotation().Roll;
	maxX = 0.0f;

	minY = 0.0f;
	maxY = 0.0f;

	minZ = 0.0f;
	maxZ = 0.0f;*/

	// ...
}


// Called when the game starts
void UIsRotable::BeginPlay()
{
	Super::BeginPlay();

	scPos = Pivot->GetComponentLocation();

	InitialYaw = GetOwner()->GetActorRotation().Yaw;
	UE_LOG(LogTemp, Warning, TEXT("%f"), InitialYaw);
	//minZ += InitialYaw;
	//maxZ += InitialYaw;
	// ...
	
}


// Called every frame
void UIsRotable::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (rotate && IsCodeFound) {
		if (rotateX) {
			//UE_LOG(LogTemp, Warning, TEXT("Rotate"));
			SetNewAngleX();
		}

		if (rotateY) {

		}

		if (rotateZ) {
			SetNewAngleZ();
		}
	}

	// ...
}

USceneComponent* UIsRotable::GetSceneComp()
{
	return Pivot;
}

bool UIsRotable::GetRotateState()
{
	return rotate;
}

void UIsRotable::SetScenePosition(float x, float y, float z)
{
	FVector newPosition(x, y, z);
	Pivot->SetRelativeLocation(newPosition);
}

void UIsRotable::SetVectHand(FVector newHandPos)
{
	this->handPos = newHandPos;
}



void UIsRotable::SetRotate(bool newRotate)
{
	this->rotate = newRotate;
}

void UIsRotable::SetRotateX(bool newRotate)
{
	this->rotateX = newRotate;
}

void UIsRotable::SetRotateY(bool newRotate)
{
	this->rotateY = newRotate;
}

void UIsRotable::SetRotateZ(bool newRotate)
{
	this->rotateZ = newRotate;
}

void UIsRotable::SetMinX(float newX)
{
	this->minX = newX;
}

void UIsRotable::SetMaxX(float newX)
{
	this->maxX = newX;
}

void UIsRotable::SetMinY(float newY)
{
	this->minY = newY;
}

void UIsRotable::SetMaxY(float newY)
{
	this->maxY = newY;
}

void UIsRotable::SetMinZ(float newZ)
{
	this->minZ = newZ;
}

void UIsRotable::SetMaxZ(float newZ)
{
	this->maxZ = newZ;
}

void UIsRotable::SetNewAngleX()
{
	float newAngle = UKismetMathLibrary::DegAtan((handPos.Z - scPos.Z) / UKismetMathLibrary::Sqrt(UKismetMathLibrary::Square(handPos.X - scPos.X) + UKismetMathLibrary::Square(handPos.Y - scPos.Y)))*-1;

	if (newAngle <= minX && newAngle >= maxX) {
		FRotator scRot = Pivot->GetComponentRotation();
		scRot.Roll = newAngle;
		Pivot->SetWorldRotation(scRot);
	}
}

void UIsRotable::SetNewAngleZ()
{
	float newAngle = UKismetMathLibrary::DegAtan((handPos.Y - scPos.Y) / (handPos.X - scPos.X));
	UE_LOG(LogTemp, Warning, TEXT("%f"), newAngle);

	//newAngle += InitialYaw;

	if (newAngle <= minZ && newAngle >= maxZ) {
		FRotator scRot = Pivot->GetComponentRotation();
		scRot.Yaw = newAngle;
		//scRot.Yaw += InitialYaw;
		UE_LOG(LogTemp, Warning, TEXT("%f"), scRot.Yaw);
		Pivot->SetRelativeRotation(scRot);
	}
}

void UIsRotable::SetIsCodeFound(bool IsCode)
{
	this->IsCodeFound = IsCode;
}

