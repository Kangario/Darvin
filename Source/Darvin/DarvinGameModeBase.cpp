// Copyright Epic Games, Inc. All Rights Reserved.


#include "DarvinGameModeBase.h"

ADarvinGameModeBase::ADarvinGameModeBase()
{
    // Установка класса персонажа по умолчанию
    DefaultPawnClass = ADCharacterController::StaticClass();
}