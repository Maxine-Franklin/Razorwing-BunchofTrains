// Fill out your copyright notice in the Description page of Project Settings.


#include "trainMaster.h"

// Sets default values
AtrainMaster::AtrainMaster()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	myMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("trainMesh"));
	myMesh->SetupAttachment(RootComponent);

	//static ConstructorHelpers::FClassFinder<UClass> myActorFinder(TEXT("/Script/Bunch_of_Trains/Public/myTrain.myTrain"));
	//if (myActorFinder.Succeeded())
	//{
	//	myTrainActor = myActorFinder.Class;
	//}

	static ConstructorHelpers::FObjectFinder<UStaticMesh> myMeshFinder(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube")); //Obtains the static mesh from the content browser
	if (myMeshFinder.Succeeded()) //If mesh exists, then...
	{
		myMesh->SetStaticMesh(myMeshFinder.Object); //Applies mesh
		SetActorHiddenInGame(true);
		forwardDirection = 1;
		//Adjusts mesh properties
		myMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		myMesh->SetWorldScale3D(FVector(1.0f, 30.0f, 17.75f));
		myMesh->SetSimulatePhysics(true);
		myMesh->SetEnableGravity(false);
		myMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	}

}

// Called when the game starts or when spawned
void AtrainMaster::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AtrainMaster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FTransform Trans = myMesh->BodyInstance.GetUnrealWorldTransform();//.GetLocation();
	FVector Location = Trans.GetLocation();
	switch (abs(forwardDirection))
	{
	case 1:
		Location.X = Player->GetActorLocation().X;
	case 2:
		Location.Y = Player->GetActorLocation().Y;
	case 3:
		Location.Z = Player->GetActorLocation().Z;
	}
	Trans.SetLocation(Location);
	myMesh->SetWorldTransform(Trans);
}

void AtrainMaster::SpawnTrain(int Lane, float vel, bool Active, bool Starting)
{
	if (Starting)
	{
		for (int i = 0; i < 4; i++)
		{
			//float vel, int verticalAxis, int forward, FVector pos
			//Trains.Add(AmyTrain(vel, forwardDirection, LaneStarts[i]->GetActorLocation()));
		}
		//AmyTrain::AmyTrain(vel, forwardDirection, LaneStarts[2]->GetActorLocation());
	}
}
