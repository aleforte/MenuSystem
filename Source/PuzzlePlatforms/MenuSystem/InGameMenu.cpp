// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameMenu.h"
#include "Components/Button.h"

bool UInGameMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	if (!ensure(CloseButton != nullptr)) return false;
	if (!ensure(QuitButton != nullptr)) return false;

	// Main Menu Buttons
	CloseButton->OnClicked.AddDynamic(this, &UInGameMenu::HideMenu);
	QuitButton->OnClicked.AddDynamic(this, &UInGameMenu::QuitGame);

	return true;
}

void UInGameMenu::QuitGame()
{
	UE_LOG(LogTemp, Log, TEXT("Quitting game..."));
	MenuInterface->LoadMainMenu();
}
