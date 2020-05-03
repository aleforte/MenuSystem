// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzlePlatformsGameInstance.h"
#include "Engine/Engine.h"
#include "GameFramework/PlayerController.h"
#include "UObject/ConstructorHelpers.h"
#include "PlatformTrigger.h"
#include "Blueprint/UserWidget.h"
#include "PuzzlePlatforms/MainSystem/MainMenu.h"


UPuzzlePlatformsGameInstance::UPuzzlePlatformsGameInstance(const FObjectInitializer& ObjectInitializer)
{
	ConstructorHelpers::FClassFinder<UUserWidget> MenuBPClass(TEXT("/Game/MenuSystem/WBP_MainMenu"));
	if (MenuBPClass.Class == nullptr) return;
	
	MenuClass = MenuBPClass.Class;
}

void UPuzzlePlatformsGameInstance::Init()
{
	Super::Init();
	if (MenuClass == nullptr) return;

	UE_LOG(LogTemp, Warning, TEXT("Found Class %s"), *MenuClass->GetName());
}

void UPuzzlePlatformsGameInstance::LoadMenu()
{
	if (MenuClass == nullptr) return;
	Menu = CreateWidget<UMainMenu>(this, MenuClass, FName("MainMenu")); // load menu
	Menu->SetMenuInterface(this); // Set this, since it now implements IMenuInterface
}

void UPuzzlePlatformsGameInstance::Host()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Cyan, TEXT("Hosting..."));
	}

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;
	World->ServerTravel("/Game/Maps/ThirdPersonExampleMap?listen");
}

void UPuzzlePlatformsGameInstance::Join(const FString& address)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Cyan, FString::Printf(TEXT("Joining %s..."), *address));
	}


	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;
	PlayerController->ClientTravel(address, ETravelType::TRAVEL_Absolute);
}
