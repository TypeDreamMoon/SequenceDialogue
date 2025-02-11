// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "SequenceDialogue.h"

#include "SequenceDialogueSettings.h"

#define LOCTEXT_NAMESPACE "FSequenceDialogueModule"

void FSequenceDialogueModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	USequenceDialogueSettings::Register();
}

void FSequenceDialogueModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	USequenceDialogueSettings::Unregister();
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FSequenceDialogueModule, SequenceDialogue)
