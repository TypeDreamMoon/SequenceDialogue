// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueWidget.h"

bool UDialogueWidget::SetDialogueInfo(const FText& InText)
{
	BP_SetDialogueContent(InText);
	return true;
}

bool UDialogueWidget::SetSpeakerName(const FText& InText)
{
	BP_SetDialogueSpeakerName(InText);
	return true;
}
