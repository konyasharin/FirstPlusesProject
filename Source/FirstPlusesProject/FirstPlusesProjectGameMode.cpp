// Copyright Epic Games, Inc. All Rights Reserved.

#include "FirstPlusesProjectGameMode.h"
#include "FirstPlusesProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFirstPlusesProjectGameMode::AFirstPlusesProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
