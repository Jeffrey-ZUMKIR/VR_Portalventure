// Fill out your copyright notice in the Description page of Project Settings.


#include "Lockers.h"
#include "Internationalization/Text.h"
#include "GameFramework/Actor.h"
#include "HandController.h"

// Sets default values for this component's properties
ULockers::ULockers()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	UpMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("UpMesh"));
	//UpMesh->SetupAttachment(TheRoot);

	UpBox = CreateDefaultSubobject<UBoxComponent>(TEXT("UpBox"));
	UpBox->SetupAttachment(UpMesh);

	DownMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DownMesh"));
	//DownMesh->SetupAttachment(TheRoot);

	DownBox = CreateDefaultSubobject<UBoxComponent>(TEXT("DownBox"));
	DownBox->SetupAttachment(DownMesh);

	ValCadena = CreateDefaultSubobject<UTextRenderComponent>(TEXT("ValCadena"));
	//ValCadena->SetupAttachment(TheRoot);

	n_val = 0;
	// ...
}


// Called when the game starts
void ULockers::BeginPlay()
{
	Super::BeginPlay();

	UpBox->OnComponentBeginOverlap.AddDynamic(this, &ULockers::OnEnterUpBox);
	UpBox->OnComponentEndOverlap.AddDynamic(this, &ULockers::OnExitUpBox);

	DownBox->OnComponentBeginOverlap.AddDynamic(this, &ULockers::OnEnterDownBox);
	DownBox->OnComponentEndOverlap.AddDynamic(this, &ULockers::OnExitDownBox);

	ValCadena->SetText(FText::AsNumber(n_val));

	IsCodeFound = false;
	// ...
	
}


// Called every frame
void ULockers::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void ULockers::IsPressed()
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

void ULockers::OnEnterUpBox(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Enter"));
	if (OtherActor->IsA(AHandController::StaticClass())) {
		UpBoxEnter = true;
	}
}

void ULockers::OnExitUpBox(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->IsA(AHandController::StaticClass())) {
		UpBoxEnter = false;
	}
}

void ULockers::OnEnterDownBox(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA(AHandController::StaticClass())) {
		DownBoxEnter = true;
	}
}

void ULockers::OnExitDownBox(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->IsA(AHandController::StaticClass())) {
		DownBoxEnter = false;
	}
}

void ULockers::AddToN_val(int add_val)
{
	this->n_val = this->n_val + add_val;
	if (this->n_val < 0) {
		this->n_val = 9;
	}
	else if (this->n_val > 9) {
		this->n_val = 0;
	}
}

int32 ULockers::GetN_val()
{
	return n_val;
}

void ULockers::SetIsCodeFound(bool IsCodeCorrect)
{
	this->IsCodeFound = IsCodeCorrect;
}

