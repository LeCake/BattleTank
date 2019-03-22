// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"


void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntentMoveFoward(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
	//TODO Prevent double-speed due to dual control use
}

void UTankMovementComponent::IntentTurnRight(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
	//TODO Prevent double-speed due to dual control use
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	auto TankName = GetOwner()->GetName();
	auto MoveVelocityString = MoveVelocity.ToString();
	UE_LOG(LogTemp, Warning, TEXT("%s vectoring to %s"), *TankName, *MoveVelocityString);
}



