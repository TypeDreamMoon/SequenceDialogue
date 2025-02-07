// Copyright 2022 - 2025 Dream Moon Team. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "SequenceDialogueSettings.generated.h"

class UDialogueWidget;
/**
 * 
 */
UCLASS(Config=SequenceDialogueSettings, DefaultConfig)
class SEQUENCEDIALOGUE_API USequenceDialogueSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	USequenceDialogueSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	virtual FName GetCategoryName() const override { return TEXT("Plugins"); }
	virtual FName GetContainerName() const override { return TEXT("Project"); }
	virtual FName GetSectionName() const override { return TEXT("SequenceDialogue"); }

public:
	UPROPERTY(EditAnywhere, Config, Category = "SequenceDialogue", meta = (DisplayName = "Dialogue Widget Class"))
	TSoftClassPtr<UDialogueWidget> DialogueWidgetClass;

public:
	static void Register();
	static void Unregister();

	static USequenceDialogueSettings* Get();

	TSubclassOf<UDialogueWidget> GetDialogueWidgetClass() const;
};
