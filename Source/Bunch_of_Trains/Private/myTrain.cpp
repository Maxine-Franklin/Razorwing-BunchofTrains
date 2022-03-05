// Fill out your copyright notice in the Description page of Project Settings.

#include "myTrain.h"

// Sets default values
AmyTrain::AmyTrain()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*myMesh->CreateDefaultSubobject<UStaticMeshComponent>(TEXT("myMesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> FoundMesh(TEXT("/Game/Bunch_of_Trains/Meshes/Train.Mesh"));
	if (FoundMesh.Succeeded())
	{
		myMesh->SetStaticMesh(FoundMesh.Object);
	}
	RootComponent = myMesh;*/

	UStaticMeshComponent* myMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("trainMesh"));
	myMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> myMeshFinder(TEXT("/Game/Bunch_of_Trains/Meshes/Train.Train"));
	if (myMeshFinder.Succeeded())
	{
		myMesh->SetStaticMesh(myMeshFinder.Object);
		myMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		myMesh->SetWorldScale3D(FVector(1.f));
	}

}

// Called when the game starts or when spawned
void AmyTrain::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AmyTrain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

