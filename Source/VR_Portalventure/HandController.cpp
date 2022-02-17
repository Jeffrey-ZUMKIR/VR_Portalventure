// Fill out your copyright notice in the Description page of Project Settings.


#include "HandController.h"

#include "Animation/SkeletalMeshActor.h"
#include "Components/SkeletalMeshComponent.h"
#include "ChangeBulbColor.h"
#include "Chest.h"
#include "ControlPanel.h"
#include "Kismet/GameplayStatics.h"

#include "Lockers.h"



// Sets default values
AHandController::AHandController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("Motion controller"));
	SetRootComponent(MotionController);
	MotionController->bDisplayDeviceModel = true;

    MySkelMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Hand skel"));
    MySkelMesh->SetupAttachment(MotionController);

    ScHand = CreateDefaultSubobject<USceneComponent>(TEXT("ScHand"));
    ScHand->SetupAttachment(MySkelMesh);
}

// Called when the game starts or when spawned
void AHandController::BeginPlay()
{
	Super::BeginPlay();
    ASkeletalMeshActor *Skel = Cast<ASkeletalMeshActor>(this);
    if (Skel != nullptr)
    {
        UE_LOG(LogTemp, Warning, TEXT("Get skelet"));
        MyMesh = Skel->GetSkeletalMeshComponent();
        if (MyMesh != nullptr)
        {
            UE_LOG(LogTemp, Warning, TEXT("Get mesh"));
        }
   }
	
}

// Called every frame
void AHandController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Si j'ai bien attraper un objet qui peut tourner, j'appelle une fonction de l'actor component qui récupère chaque la position de ma main
	if (thingRotate != nullptr) {
		thingRotate->SetVectHand(this->GetActorLocation());
	}
}

void AHandController::GrabObject(AHandController *otherController){
    UE_LOG(LogTemp, Warning, TEXT("Grab right"));
	TArray<AActor*> outoverlap;
	this->GetOverlappingActors(outoverlap);

	UE_LOG(LogTemp, Warning, TEXT("%d"), outoverlap.Num());
	if(outoverlap.Num() > 0){
		//UE_LOG(LogTemp, Warning, TEXT("Object overlap %s"), *outoverlap[0]->GetName());

		bool bFindObject = false;
		int check = outoverlap.Num()-1;
		//AGrabbableObject* trycast = nullptr;
		UIsGrabbable* trycast = nullptr;
		while (bFindObject == false)
		{
			//trycast = dynamic_cast<AGrabbableObject*>(outoverlap[check]);
			trycast = dynamic_cast<UIsGrabbable*>(outoverlap[check]->FindComponentByClass(UIsGrabbable::StaticClass()));
			if(trycast != nullptr || check <= 0){
				bFindObject = true;
			}
			check--;
		}
		
		//AGrabbableObject* trycast = dynamic_cast<AGrabbableObject*>(outoverlap[0]);
		//UE_LOG(LogTemp, Warning, TEXT("%d"), outoverlap.Num());
		if(trycast != nullptr){
			if(trycast->isGrabbed == true){
				otherController->thingGrabbed2 = nullptr;
			}
			UE_LOG(LogTemp, Warning, TEXT("Object overlap %s"), *trycast->GetOwner()->GetName());
			trycast->SetMeshPhysic(false);
			//trycast->AttachToComponent(this->GetSkelMesh(),FAttachmentTransformRules::KeepWorldTransform);
			trycast->GetOwner()->AttachToComponent(this->GetSkelMesh(), FAttachmentTransformRules::KeepWorldTransform);
			thingGrabbed2 = trycast;
			trycast->isGrabbed = true;
		}

		if (trycast == nullptr) {
			bFindObject = false;
			check = outoverlap.Num() - 1;
			UIsRotable* trycast2 = nullptr;
			while (bFindObject == false)
			{
				trycast2 = dynamic_cast<UIsRotable*>(outoverlap[check]->FindComponentByClass(UIsRotable::StaticClass()));
				if (trycast2 != nullptr || check <= 0) {
					bFindObject = true;
				}
				check--;
			}

			if (trycast2 != nullptr) {
				UE_LOG(LogTemp, Warning, TEXT("Find chets"));
				trycast2->SetRotate(true);
				thingRotate = trycast2;
			}
		}
	}
}

void AHandController::LetGoObject(){
	if(thingGrabbed2 != nullptr){
		thingGrabbed2->GetOwner()->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		if (thingGrabbed2->isGrabbed == true) {
			thingGrabbed2->SetMeshPhysic(true);
			thingGrabbed2->isGrabbed = false;
		}
		thingGrabbed2 = nullptr;
	}

	if (thingRotate != nullptr) {
		thingRotate->SetRotate(false);
		thingRotate = nullptr;
	}
}

void AHandController::PressObject(){
	TArray<AActor*> outoverlap;
	this->GetOverlappingActors(outoverlap);

	if(outoverlap.Num() > 0){
		//UE_LOG(LogTemp, Warning, TEXT("Object overlap %s"), *outoverlap[0]->GetName());

		bool bFindObject = false;
		int check = outoverlap.Num()-1;
		APressableObject* trycast = nullptr;
		//ULockers* trycast = nullptr;
		while (bFindObject == false)
		{
			trycast = dynamic_cast<APressableObject*>(outoverlap[check]);
			//trycast = dynamic_cast<ULockers*>(outoverlap[check]);
			if(trycast != nullptr || check <= 0){
				bFindObject = true;
			}
			check--;
		}

		if(trycast != nullptr){
			trycast->IsPressed();

			TArray<AActor*> AllChests;
			UGameplayStatics::GetAllActorsOfClass(GetWorld(), AChest::StaticClass(), AllChests);
			for (AActor* Actor : AllChests) {
				dynamic_cast<AChest*>(Actor)->CheckCode();
			}
		}

		if (trycast == nullptr) {
			bFindObject = false;
			check = outoverlap.Num() - 1;

			UChangeBulbColor* trycast2 = nullptr;
			while (bFindObject == false) {
				trycast2 = dynamic_cast<UChangeBulbColor*>(outoverlap[check]->FindComponentByClass(UChangeBulbColor::StaticClass()));
				if (trycast2 != nullptr || check <= 0) {
					bFindObject = true;
				}
				check--;
			}

			if (trycast2 != nullptr) {
				UE_LOG(LogTemp, Warning, TEXT("Change color"));
				trycast2->ChangeBulbColor();

				TArray<AActor*> AllPanels;
				UGameplayStatics::GetAllActorsOfClass(GetWorld(), AControlPanel::StaticClass(), AllPanels);
				for (AActor* Actor : AllPanels) {
					dynamic_cast<AControlPanel*>(Actor)->CheckCode();
				}
			}
		}
		
		
	}
}