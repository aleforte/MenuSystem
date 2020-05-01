// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation); // convert to global location (vs relative)
	DistanceToTravel = FindDistanceToTravel();

	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}
}


void AMovingPlatform::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (HasAuthority() && ActiveTriggers > 0)
	{
		FVector CurrLocation = GetActorLocation();
		if (IsAtTarget(CurrLocation)) { SwitchDirections(); }
		
		FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
		FVector Move = Direction * MovementSpeed * DeltaSeconds;
		SetActorLocation(CurrLocation + Move);
	}

}


float AMovingPlatform::FindDistanceToTravel() { return (GlobalTargetLocation - GlobalStartLocation).Size(); }

bool AMovingPlatform::IsAtTarget(FVector CurrentLocation) { return (CurrentLocation - GlobalStartLocation).Size() > DistanceToTravel; } // distance traveled > distanceTo...

void AMovingPlatform::SwitchDirections()
{
	FVector CurrentLocation = GlobalTargetLocation;
	GlobalTargetLocation = GlobalStartLocation;
	GlobalStartLocation = CurrentLocation;
	DistanceToTravel = FindDistanceToTravel();
}


void AMovingPlatform::AddActiveTrigger()
{
	ActiveTriggers++;
}

void AMovingPlatform::RemoveActiveTrigger()
{
	if (ActiveTriggers == 0) return;
	ActiveTriggers--;
}
