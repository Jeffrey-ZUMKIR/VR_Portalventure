// Fill out your copyright notice in the Description page of Project Settings.


#include "PressableObject.h"
#include "Internationalization/Text.h"
#include "GameFramework/Actor.h"
#include "Math/Color.h"
#include "HandController.h"

// Sets default values
APressableObject::APressableObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TheRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(TheRoot);

	UpMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("UpMesh"));
	UpMesh->SetupAttachment(TheRoot);

	UpBox = CreateDefaultSubobject<UBoxComponent>(TEXT("UpBox"));
	UpBox->SetupAttachment(UpMesh);

	DownMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DownMesh"));
	DownMesh->SetupAttachment(TheRoot);

	DownBox = CreateDefaultSubobject<UBoxComponent>(TEXT("DownBox"));
	DownBox->SetupAttachment(DownMesh);

	ValCadena = CreateDefaultSubobject<UTextRenderComponent>(TEXT("ValCadena"));
	ValCadena->SetupAttachment(TheRoot);

	n_val = 0;

}

// Called when the game starts or when spawned
void APressableObject::BeginPlay()
{
	Super::BeginPlay();
	
	UpBox->OnComponentBeginOverlap.AddDynamic(this, &APressableObject::OnEnterUpBox);
	UpBox->OnComponentEndOverlap.AddDynamic(this, &APressableObject::OnExitUpBox);

	DownBox->OnComponentBeginOverlap.AddDynamic(this, &APressableObject::OnEnterDownBox);
	DownBox->OnComponentEndOverlap.AddDynamic(this, &APressableObject::OnExitDownBox);

	ValCadena->SetText(FText::AsNumber(n_val));

	IsCodeFound = false;

}

// Called every frame
void APressableObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APressableObject::IsPressed()
{
	if (!IsCodeFound) {
		if (UpBoxEnter) {
			UE_LOG(LogTemp, Warning, TEXT("Pressed Up"));
			AddToN_val(1);
			ValCadena->SetText(FText::AsNumber(n_val));
		}

		if (DownBoxEnter) {
			UE_LOG(LogTemp, Warning, TEXT("Pressed Down"));
			AddToN_val(-1);
			ValCadena->SetText(FText::AsNumber(n_val));
		}

	}
}

void APressableObject::OnEnterUpBox(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor->IsA(AHandController::StaticClass())){
		UpBoxEnter = true;
	}
}

void APressableObject::OnExitUpBox(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if(OtherActor->IsA(AHandController::StaticClass())){
		UpBoxEnter = false;
	}
}

void APressableObject::OnEnterDownBox(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor->IsA(AHandController::StaticClass())){
		DownBoxEnter = true;
	}
}

void APressableObject::OnExitDownBox(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if(OtherActor->IsA(AHandController::StaticClass())){
		DownBoxEnter = false;
	}
}

void APressableObject::AddToN_val(int add_val)
{
	this->n_val = this->n_val + add_val;
	if (this->n_val < 0) {
		this->n_val = 9;
	}
	else if (this->n_val > 9) {
		this->n_val = 0;
	}
}

int32 APressableObject::GetN_val()
{
	return n_val;
}

void APressableObject::SetIsCodeFound(bool IsCode)
{
	this->IsCodeFound = IsCode;
	if (IsCode) {
		FColor correctCol(100, 255, 0, 255);
		ValCadena->SetTextRenderColor(correctCol);
	}
}

/*void APressableObject::SetHisParent(AChest* parent)
{
	HisParent = parent;
}*/

