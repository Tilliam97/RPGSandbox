// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "RPGSandboxGameMode.generated.h"

UCLASS(minimalapi)
class ARPGSandboxGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ARPGSandboxGameMode();

private:
	void SetPlayer();
};



