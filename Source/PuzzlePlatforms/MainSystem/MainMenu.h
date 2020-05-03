// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuInterface.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetMenuInterface(IMenuInterface* MenuInterface);

	void SetUp();

protected:
	virtual bool Initialize() override;

	virtual void OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld) override;

private:
	// Widgets
	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* MenuSwitcher;

	UPROPERTY(meta = (BindWidget))
	class UWidget* MainMenu;

	UPROPERTY(meta = (BindWidget))
	class UWidget* JoinMenu;

	UPROPERTY(meta = (BindWidget))
	class UEditableTextBox* AddressField;

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

	IMenuInterface* MenuInterface;

};
