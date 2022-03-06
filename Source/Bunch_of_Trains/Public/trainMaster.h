// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
//#include "myTrain.h"
#include "trainMaster.generated.h"

UCLASS()
class BUNCH_OF_TRAINS_API AtrainMaster : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AtrainMaster();
	//UPROPERTY(EditAnywhere)
	//	UStaticMesh* Train; //Static mesh used for the train model
	
	UPROPERTY(EditAnywhere, Category = "TrainStart")
		TArray<AActor*> LaneStarts;
	UPROPERTY(EditAnywhere, Category = "Setup")
		float Velocity;
	UPROPERTY(EditAnywhere, Category = "Setup")
		/// -+1 = -+x, -+2 = -+y, -+3 = -+z
		int forwardDirection;
	UPROPERTY(EditAnywhere, Category = "Setup")
		AActor* Player;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//TArray<AmyTrain> Trains;
	//AmyTrain Train;
	//TSubclassOf<AActor> myTrainActor;
	void SpawnTrain(int Lane, float vel, bool Active, bool Starting);
	UStaticMeshComponent* myMesh;

};
