// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/PrimitiveComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "myTrain.generated.h"

UCLASS()
class BUNCH_OF_TRAINS_API AmyTrain : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AmyTrain();

	//UStaticMeshComponent* myMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("trainMesh"));

	UStaticMeshComponent* myMesh;

	//UPROPERTY(BlueprintReadWrite)
		//UStaticMeshComponent* myMesh;

	/** Root component */
	//UPROPERTY()
		//TSubobjectPtr<USceneComponent> Root;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	float Velocity;
	FTransform Transform;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};