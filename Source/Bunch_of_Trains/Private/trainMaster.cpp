// Fill out your copyright notice in the Description page of Project Settings.


#include "trainMaster.h"

// Sets default values
AtrainMaster::AtrainMaster()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

}

void AtrainMaster::SpawnTrain(FTransform Trans, float Velocity, bool Active)
{

}
