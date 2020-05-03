// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuWidget.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UMainMenu : public UMenuWidget
{
	GENERATED_BODY()

protected:
	virtual bool Initialize() override;

private:
	// Global Widgets
	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* MenuSwitcher;

	UPROPERTY(meta = (BindWidget))
	class UWidget* MainMenu;

	UPROPERTY(meta = (BindWidget))
	class UWidget* JoinMenu;

	UPROPERTY(meta = (BindWidget))
	class UEditableTextBox* AddressField;

	UPROPERTY(meta = (BindWidget))
	class UButton* ExitButton;

	UFUNCTION()
	void ExitGame();

	// Main Menu Buttons
	UPROPERTY(meta = (BindWidget))
	class UButton* MMHostButton; 

	UPROPERTY(meta = (BindWidget))
	class UButton* MMJoinButton; 

	UFUNCTION()
	void OpenJoinMenu();

	UFUNCTION()
	void HostServer();

	// Join Menu Buttons
	UPROPERTY(meta = (BindWidget))
	class UButton* JMJoinButton; 

	UPROPERTY(meta = (BindWidget))
	class UButton* JMBackButton; 

	UFUNCTION()
	void OpenMainMenu();
	
	UFUNCTION()
	void JoinServer();

};
