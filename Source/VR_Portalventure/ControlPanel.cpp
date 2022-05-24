// Fill out your copyright notice in the Description page of Project Settings.


#include "ControlPanel.h"
#include "ChangeBulbColor.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>

// Sets default values
AControlPanel::AControlPanel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AControlPanel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AControlPanel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AControlPanel::CheckCode()
{
	if (CodeColor.Num() == ColorBulb.Num()) {
		bool IsCodeCorrect = true;
		for (size_t i = 0; i < CodeColor.Num(); i++)
		{
			if (CodeColor[i] != ColorBulb[i]->TheColor) {
				IsCodeCorrect = false;
			}
		}

		if (IsCodeCorrect) {
			UE_LOG(LogTemp, Warning, TEXT("Correct color code"));
			for (AColorBulb* bulb : ColorBulb)
			{
				bulb->IsActivate = false;
				TArray<AActor*> FoundActors;
				UGameplayStatics::GetAllActorsOfClass(GetWorld(), ClassToFind, FoundActors);
				FoundActors[0]->SetActorHiddenInGame(false);

			}
		}
	}
}

void AControlPanel::PanelActivate(bool Activate)
{
	for (AColorBulb* AColorBulb : ColorBulb)
	{
		AColorBulb->IsActivate = Activate;
		AColorBulb->FindComponentByClass<UChangeBulbColor>()->ChangeMatColor();
	}
}

