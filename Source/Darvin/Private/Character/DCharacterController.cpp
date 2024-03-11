// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/DCharacterController.h"

// Sets default values
ADCharacterController::ADCharacterController()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADCharacterController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADCharacterController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADCharacterController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
    PlayerInputComponent->BindAxis("MoveForward", this, &ADCharacterController::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ADCharacterController::MoveRight);
}

void ADCharacterController::MoveForward(float Value)
{
    if ((Controller != nullptr) && (Value != 0.0f))
    {
        // Найти направление взгляда
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);

        // Найти вектор направления вперед
        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
        // Двигать персонажа вперед
        AddMovementInput(Direction, Value);
    }
}

void ADCharacterController::MoveRight(float Value)
{
    if ((Controller != nullptr) && (Value != 0.0f))
    {
        // Найти направление взгляда
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);

        // Найти вектор направления вправо
        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
        // Двигать персонажа вправо
        AddMovementInput(Direction, Value);
    }
}