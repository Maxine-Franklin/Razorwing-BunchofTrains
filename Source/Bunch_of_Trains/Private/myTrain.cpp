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
	lockedAxis = 3;
	lockedAxisVal = GetLockedAxis(lockedAxis);
}

AmyTrain::AmyTrain(float vel, int VerticalAxis, int Forward)
{
	Velocity = vel;
	lockedAxis = VerticalAxis;
	forwardDirection = Forward;
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
	if (GetLockedAxis(lockedAxis) > lockedAxisVal + 250.0f || GetLockedAxis(lockedAxis) < lockedAxisVal - 250.0f)
	{
		//myMesh->AddImpulse(ImpulseVector(-4.9f) * myMesh->GetMass());
		myMesh->AddImpulse(FVector(-Velocity, 0.0f, -4.9f) * myMesh->GetMass());
	}
	else if (GetLockedAxis(lockedAxis) > lockedAxisVal + 500.0f || GetLockedAxis(lockedAxis) < lockedAxisVal - 500.0f)
	{ /*myMesh->AddImpulse(ImpulseVector(-9.8f) * myMesh->GetMass()); */ myMesh->AddImpulse(FVector(-Velocity, 0.0f, -9.8f) * myMesh->GetMass()); }
	else { /* myMesh->AddImpulse(ImpulseVector(0.0f) * myMesh->GetMass()); */ myMesh->AddImpulse(FVector(-Velocity, 0.0f, 0.0f) * myMesh->GetMass()); }
}

float AmyTrain::GetLockedAxis(int Axis)
{
	switch (Axis)
	{
		case 1:
			return GetActorLocation().X;
		case 2:
			return GetActorLocation().Y;
		case 3:
			return GetActorLocation().Z;
		default:
			return GetActorLocation().Z;
	}
}

FVector AmyTrain::ImpulseVector(float Gravity)
{
	int x = 1;
	FVector rv = FVector(0.0f, 0.0f, 0.0f);
	if (Gravity != 0)
	{
		switch (lockedAxis)
		{
		case 1:
			rv.X = Gravity;
		case 2:
			rv.Y = Gravity;
		case 3:
			rv.Z = Gravity;
		}
	}
	if (forwardDirection < 0) { x = -1; }
	switch (abs(forwardDirection))
	{
	case 1:
		rv.X = x * Velocity;
	case 2:
		rv.Y = x * Velocity;
	case 3:
		rv.Z = x * Velocity;
	}
	return rv;
}