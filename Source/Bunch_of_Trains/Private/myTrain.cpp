// Fill out your copyright notice in the Description page of Project Settings.

#include "myTrain.h"

// Sets default values
AmyTrain::AmyTrain()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//myMesh->CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GeneratedMesh"));
	//RootComponent = myMesh;
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

