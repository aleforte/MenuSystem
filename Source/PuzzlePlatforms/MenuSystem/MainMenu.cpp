// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"
#include "Engine/World.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/EditableTextBox.h"


bool UMainMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	if (!ensure(MMHostButton != nullptr)) return false;
	if (!ensure(MMJoinButton != nullptr)) return false;
	if (!ensure(JMJoinButton != nullptr)) return false;
	if (!ensure(JMBackButton != nullptr)) return false;

	// =========== Register Delegates =============

	// Main Menu Buttons
	MMHostButton->OnClicked.AddDynamic(this, &UMainMenu::HostServer);
	MMJoinButton->OnClicked.AddDynamic(this, &UMainMenu::OpenJoinMenu);
	// Join Menu Buttons
	JMJoinButton->OnClicked.AddDynamic(this, &UMainMenu::JoinServer);
	JMBackButton->OnClicked.AddDynamic(this, &UMainMenu::OpenMainMenu);

	return true;
}

void UMainMenu::OpenJoinMenu()
{
	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(JoinMenu != nullptr)) return;

	UE_LOG(LogTemp, Warning, TEXT("Switching Menu..."));
	MenuSwitcher->SetActiveWidget(JoinMenu);
}

void UMainMenu::HostServer()
{
	if (MenuInterface != nullptr)
	{
		MenuInterface->Host();
		// UE_LOG(LogTemp, Warning, TEXT("Hosting..."));
	}
}

void UMainMenu::OpenMainMenu()
{
	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(MainMenu != nullptr)) return;

	UE_LOG(LogTemp, Warning, TEXT("Switching Menu..."));
	MenuSwitcher->SetActiveWidget(MainMenu);
}

void UMainMenu::JoinServer()
{
	if (MenuInterface != nullptr)
	{		
		if (!ensure(AddressField != nullptr)) return;
		const FText Address = AddressField->GetText();
		MenuInterface->Join(FString(Address.ToString()));
	}
}
