// Copyright 2022 - 2025 Dream Moon Team. All Rights Reserved.


#include "SequenceDialogueSettings.h"
#include "DialogueWidget.h"

#if WITH_EDITOR
#include "ISettingsModule.h"
#endif

#define LOCTEXT_NAMESPACE "USequenceDialogueSettings"

USequenceDialogueSettings::USequenceDialogueSettings(const FObjectInitializer& ObjectInitializer)
{
	DialogueWidgetClass = UDialogueWidget::StaticClass();
}

void USequenceDialogueSettings::Register()
{
#if WITH_EDITOR
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "SequenceDialogue",
		                                 LOCTEXT("SequenceDialogueSettingsName", "SequenceDialogue"),
		                                 LOCTEXT("SequenceDialogueSettingsDescription", "Configure the SequenceDialogue plugin."),
		                                 Get());
	}
#endif
}

void USequenceDialogueSettings::Unregister()
{
#if WITH_EDITOR
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "SequenceDialogue");
	}
#endif
}

USequenceDialogueSettings* USequenceDialogueSettings::Get()
{
	return GetMutableDefault<USequenceDialogueSettings>();
}

TSubclassOf<UDialogueWidget> USequenceDialogueSettings::GetDialogueWidgetClass() const
{
	return DialogueWidgetClass.LoadSynchronous();
}


#undef LOCTEXT_NAMESPACE
