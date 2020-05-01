// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()
	

public:
	/* Constructor */
	AMovingPlatform();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, Category = "Setup")
	float MovementSpeed = 20.f;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true), Category = "Setup")
	FVector TargetLocation; 

	void AddActiveTrigger();
	void RemoveActiveTrigger();

private:
	FVector GlobalStartLocation;
	FVector GlobalTargetLocation;
	float DistanceToTravel;
	float FindDistanceToTravel();

	bool IsAtTarget(FVector CurrentLocation);
	void SwitchDirections();

	int32 ActiveTriggers = 1;
};
