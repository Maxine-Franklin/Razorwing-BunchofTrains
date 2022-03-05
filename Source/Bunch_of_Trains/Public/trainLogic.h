// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "trainLogic.generated.h"

UCLASS()
class BUNCH_OF_TRAINS_API AtrainLogic : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AtrainLogic();
	UPROPERTY(EditAnywhere)
		UStaticMesh* Train; //Static mesh used for the train model

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void SpawnTrain(FTransform Trans, float Velocity, bool Active = 1);

};
