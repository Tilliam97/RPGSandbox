// Copyright Epic Games, Inc. All Rights Reserved.

#include "Actors/RPGSandboxGameMode.h"
#include "Actors/RPGSandboxCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARPGSandboxGameMode::ARPGSandboxGameMode()
{
	// set default pawn class to our Blueprinted character
	SetPlayer();
}

//void ARPGSandboxGameMode::SetPlayer()
//{
//	UWorld* World = GetWorld();
//	if (World)
//	{
//		FString Map = World->GetMapName();
//		for (size_t i = 0; i < 19; i++)
//		{
//			if (Map[i] == 'W') //BlueprintWarriorMap
//			{
//				static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/Actors/BP_Warrior"));
//				if (PlayerPawnBPClass.Class != NULL)
//				{
//					DefaultPawnClass = PlayerPawnBPClass.Class;
//				}
//			}
//			else if (Map[i] == 'M') //BlueprintMageMap
//			{
//				static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/Actors/BP_Mage"));
//				if (PlayerPawnBPClass.Class != NULL)
//				{
//					DefaultPawnClass = PlayerPawnBPClass.Class;
//				}
//			}
//			else if (Map[i] == 'B') //BlueprintBruteMap
//			{
//				static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/Actors/BP_Brute"));
//				if (PlayerPawnBPClass.Class != NULL)
//				{
//					DefaultPawnClass = PlayerPawnBPClass.Class;
//				}
//			}
//			else if (Map[i] == 'T') //BlueprintThiefMap
//			{
//				static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/Actors/BP_Thief"));
//				if (PlayerPawnBPClass.Class != NULL)
//				{
//					DefaultPawnClass = PlayerPawnBPClass.Class;
//				}
//			}
//		}
//	}
//}

void ARPGSandboxGameMode::SetPlayer() // more elegeant
{
	UWorld* World = GetWorld();
	if (World)
	{
		FString Map = World->GetMapName();
		FString CharacterName = FPackageName::GetShortName(Map);
	
		if (CharacterName.Contains("Warrior")) //BlueprintWarriorMap or CodeWarriorMap
		{
			static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/Actors/BP_Warrior"));
			if (PlayerPawnBPClass.Class != NULL )
			{
				DefaultPawnClass = PlayerPawnBPClass.Class;
			}
		}
		else if (CharacterName.Contains("Mage")) //BlueprintMageMap or CodeMageMap
		{
			static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/Actors/BP_Mage"));
			if (PlayerPawnBPClass.Class != NULL)
			{
				DefaultPawnClass = PlayerPawnBPClass.Class;
			}
		}
		else if (CharacterName.Contains("Brute")) //BlueprintBruteMap or CodeBruteMap
		{
			static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/Actors/BP_Brute"));
			if (PlayerPawnBPClass.Class != NULL)
			{
				DefaultPawnClass = PlayerPawnBPClass.Class;
			}
		}
		else if (CharacterName.Contains("Thief")) //BlueprintThiefMap or CodeThiefMap
		{
			static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/Actors/BP_Thief"));
			if (PlayerPawnBPClass.Class != NULL)
			{
				DefaultPawnClass = PlayerPawnBPClass.Class;
			}
		}
	}
}