// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "UnrealGameJam2019GameMode.h"
#include "UnrealGameJam2019PlayerController.h"
#include "UnrealGameJam2019Pawn.h"

AUnrealGameJam2019GameMode::AUnrealGameJam2019GameMode()
{
	// no pawn by default
	DefaultPawnClass = AUnrealGameJam2019Pawn::StaticClass();
	// use our own player controller class
	PlayerControllerClass = AUnrealGameJam2019PlayerController::StaticClass();
}
