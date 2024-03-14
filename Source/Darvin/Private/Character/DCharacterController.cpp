// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/DCharacterController.h"

// Sets default values
ADCharacterController::ADCharacterController()
{
// Создание компонента Spring Arm и настройка его параметров
SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
SpringArmComponent->SetupAttachment(RootComponent);
SpringArmComponent->TargetArmLength = 300.0f;
SpringArmComponent->bUsePawnControlRotation = true;

// Создание компонента камеры и настройка его параметров
CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
CameraComponent->SetupAttachment(SpringArmComponent);
CameraComponent->SetRelativeLocation(FVector(-300.0f, 0, 160.0f));
CameraComponent->SetRelativeRotation(FRotator(0, 0, 0));
CameraComponent->bUsePawnControlRotation = true;
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
    PlayerInputComponent->BindAxis("Turn", this, &ADCharacterController::AddControllerYawInput);
    PlayerInputComponent->BindAxis("LookUp", this, &ADCharacterController::AddControllerPitchInput);
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