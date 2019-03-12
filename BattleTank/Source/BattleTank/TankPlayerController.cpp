// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Math/Vector2D.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	//
	UE_LOG(LogTemp, Warning, TEXT("Playercontroller Begin Play"));
	
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayController not possesing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Playercontroller possesing: %s"), *(ControlledTank->GetName()));
	}

}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	FVector HitLocation; //Out parameter
	if (GetSightRayHitLocation(HitLocation))
	{
		/*UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *HitLocation.ToString());*/
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	
	auto ScreenLocation = FVector2D((ViewportSizeX * CrossHairXLocation), (ViewportSizeY * CrossHairYLocation));
	
	return true;
}
