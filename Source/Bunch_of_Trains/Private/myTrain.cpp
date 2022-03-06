// Fill out your copyright notice in the Description page of Project Settings.

#include "myTrain.h"

// Sets default values
AmyTrain::AmyTrain()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Velocity = 20.0f;

	//Set's up the actor's mesh
	/*UStaticMeshComponent* */myMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("trainMesh"));
	myMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> myMeshFinder(TEXT("/Game/Bunch_of_Trains/Meshes/Train.Train")); //Obtains the static mesh from the content browser
	if (myMeshFinder.Succeeded()) //If mesh exists, then...
	{
		myMesh->SetStaticMesh(myMeshFinder.Object); //Applies mesh
		//Adjusts mesh properties
		myMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		myMesh->SetWorldScale3D(FVector(1.f));
		myMesh->SetSimulatePhysics(true);
		myMesh->SetEnableGravity(true);
		//myMesh->AddImpulse(FVector(1.0f, 0.0f, 0.0f));
	}
	lockedAxis = "z";
	lockedAxisVal = GetLockedAxis(lockedAxis);
}

AmyTrain::AmyTrain(float vel, FString VerticalAxis)
{
	Velocity = vel;
	lockedAxis = VerticalAxis;
	lockedAxisVal = GetLockedAxis(lockedAxis);
	//LockedAxis
}

// Called when the game starts or when spawned
void AmyTrain::BeginPlay()
{
	Super::BeginPlay();
	//myMesh->AddImpulse(FVector(2.0f, 1.0f, 1.0f) * myMesh->GetMass());

}

// Called every frame
void AmyTrain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetLockedAxis(lockedAxis) > lockedAxisVal + 500.0f || GetLockedAxis(lockedAxis) < lockedAxisVal - 250.0f)
	{
		myMesh->AddImpulse(FVector(-Velocity, 0.0f, -4.9f) * myMesh->GetMass());
	}
	else if (GetLockedAxis(lockedAxis) > lockedAxisVal + 1000.0f || GetLockedAxis(lockedAxis) < lockedAxisVal - 500.0f)
	{ myMesh->AddImpulse(FVector(-Velocity, 0.0f, -9.8f) * myMesh->GetMass()); }
	else { myMesh->AddImpulse(FVector(-Velocity, 0.0f, 0.0f) * myMesh->GetMass()); }
}

float AmyTrain::GetLockedAxis(FString Axis)
{
	if (Axis == "z")
	{
		return GetActorLocation().Z;
	}
	else if (Axis == "y")
	{
		return GetActorLocation().Y;
	}
	else
	{
		return GetActorLocation().X;
	}
}