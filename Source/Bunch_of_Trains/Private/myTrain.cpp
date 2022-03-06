// Fill out your copyright notice in the Description page of Project Settings.

#include "myTrain.h"

// Sets default values
AmyTrain::AmyTrain()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Velocity = 0.0f;
	forwardDirection = -1;

	//Set's up the actor's mesh
	SetupMesh(FVector(0.0f, 0.0f, 0.0f));

	lockedAxis = 3;
	//lockedAxisVal = GetLockedAxis(lockedAxis);
}

//AmyTrain::AmyTrain(float vel, /*int verticalAxis,*/ int forward, FVector pos)
AmyTrain::AmyTrain(float vel, int forward, FVector pos)
{
	Velocity = vel;
	//lockedAxis = verticalAxis;
	forwardDirection = forward;
	SetupMesh(pos);
	BlockAxis(forward);
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
	//If there is time, get this working in stead of using axis locking
	/*if (GetLockedAxis(lockedAxis) > lockedAxisVal + 250.0f || GetLockedAxis(lockedAxis) < lockedAxisVal - 250.0f)
	{
		//myMesh->AddImpulse(ImpulseVector(-4.9f) * myMesh->GetMass());
		myMesh->AddImpulse(FVector(-Velocity, 0.0f, -4.9f) * myMesh->GetMass());
	}
	else if (GetLockedAxis(lockedAxis) > lockedAxisVal + 500.0f || GetLockedAxis(lockedAxis) < lockedAxisVal - 500.0f)
	{ /*myMesh->AddImpulse(ImpulseVector(-9.8f) * myMesh->GetMass());  */
	//myMesh->AddImpulse(FVector(-Velocity, 0.0f, -9.8f) * myMesh->GetMass()); }
	//else { /* myMesh->AddImpulse(ImpulseVector(0.0f) * myMesh->GetMass()); */ 
	//myMesh->AddImpulse(FVector(-Velocity, 0.0f, 0.0f) * myMesh->GetMass()); }
	if (GetActorLocation().X < Player->GetActorLocation().X + 250 || GetActorLocation().X > Player->GetActorLocation().X - 250) { Velocity = 10.0f; }
	int x = 1;
	if (forwardDirection < 0) { x = -1; }
	myMesh->AddImpulse(FVector(Velocity * x, Velocity * x, Velocity * x) * myMesh->GetMass());
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

void AmyTrain::BlockAxis(int forward)
{
	myMesh->BodyInstance.bLockXTranslation = true;
	myMesh->BodyInstance.bLockYTranslation = true;
	myMesh->BodyInstance.bLockZTranslation = true;
	myMesh->BodyInstance.bLockXRotation = true;
	myMesh->BodyInstance.bLockYRotation = true;
	myMesh->BodyInstance.bLockZRotation = true;
	switch (abs(forward))
	{
	case 1:
		myMesh->BodyInstance.bLockXTranslation = false;
	case 2:
		myMesh->BodyInstance.bLockYTranslation = false;
	case 3:
		myMesh->BodyInstance.bLockZTranslation = false;
	}
	return;
}

void AmyTrain::SetupMesh(FVector trans)
{
	myMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("trainMesh"));
	myMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> myMeshFinder(TEXT("/Game/Bunch_of_Trains/Meshes/Train.Train")); //Obtains the static mesh from the content browser
	if (myMeshFinder.Succeeded()) //If mesh exists, then...
	{
		myMesh->SetStaticMesh(myMeshFinder.Object); //Applies mesh
		//Adjusts mesh properties
		myMesh->SetRelativeLocation(trans);
		myMesh->SetWorldScale3D(FVector(1.f));
		myMesh->SetSimulatePhysics(true);
		BlockAxis(forwardDirection);
		//myMesh->SetEnableGravity(true);
		//myMesh->AddImpulse(FVector(1.0f, 0.0f, 0.0f));
	}
	return;
}