// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "MovieSceneDialogueTrack.h"
#include "MovieSceneDialogueSection.h"
#include "MovieSceneDialogueTemplate.h"

#define LOCTEXT_NAMESPACE "MovieSceneDialogueTrack"

FMovieSceneEvalTemplatePtr UMovieSceneDialogueTrack::CreateTemplateForSection(const UMovieSceneSection& InSection) const
{
	return FMovieSceneDialogueSectionTemplate(*CastChecked<UMovieSceneDialogueSection>(&InSection)); //UHAMovieSceneSection UMovieSceneBoolSection
}


bool UMovieSceneDialogueTrack::IsEmpty() const
{
	return Sections.Num() == 0;
}


void UMovieSceneDialogueTrack::AddSection(UMovieSceneSection& Section)
{
	Sections.Add(&Section);
}


void UMovieSceneDialogueTrack::RemoveSection(UMovieSceneSection& Section)
{
	Sections.Remove(&Section);
}


UMovieSceneSection* UMovieSceneDialogueTrack::CreateNewSection()
{
	UMovieSceneDialogueSection* new_section = NewObject<UMovieSceneDialogueSection>(this, UMovieSceneDialogueSection::StaticClass(), NAME_None, RF_Transactional);

	return new_section;
}

const TArray<UMovieSceneSection*>& UMovieSceneDialogueTrack::GetAllSections() const
{
	return Sections;
}

bool UMovieSceneDialogueTrack::HasSection(const UMovieSceneSection& Section) const
{
	return Sections.Contains(&Section);
}

UMovieSceneDialogueSection* UMovieSceneDialogueTrack::GetSectionByID(int id)
{
	for (UMovieSceneSection* curSection : Sections)
	{
		UMovieSceneDialogueSection* dialogueSection = Cast<UMovieSceneDialogueSection>(curSection);

		if (dialogueSection && dialogueSection->GetUniqueID() == id)
		{
			return dialogueSection;
		}
	}

	return nullptr;
}
#if WITH_EDITORONLY_DATA
FText UMovieSceneDialogueTrack::GetDefaultDisplayName() const
{
	return LOCTEXT("DisplayName", "Dialogue");
}
#endif

#undef LOCTEXT_NAMESPACE
