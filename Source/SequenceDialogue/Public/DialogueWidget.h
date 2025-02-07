// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DialogueWidget.generated.h"

/**
 * 
 */
UCLASS()
class SEQUENCEDIALOGUE_API UDialogueWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	bool SetDialogueInfo(const FText& InText);
	bool SetSpeakerName(const FText& InText);

public:
	UFUNCTION(BlueprintImplementableEvent, DisplayName = "Set Dialogue Content")
	void BP_SetDialogueContent(const FText& InText);

	UFUNCTION(BlueprintImplementableEvent, DisplayName = "Set Speaker Name")
	void BP_SetDialogueSpeakerName(const FText& InText);
};
