

using UnrealBuildTool;

public class SequenceDialogue : ModuleRules
{
	public SequenceDialogue(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		//PublicIncludePaths.AddRange(
		//	new string[] {
		//		"SequenceDialogue/Public"
		//		// ... add public include paths required here ...
		//	}
		//	);
				
		
		//PrivateIncludePaths.AddRange(
		//	new string[] {
		//		"SequenceDialogue/Private",
		//		// ... add other private include paths required here ...
		//	}
		//	);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
                "MovieScene",
                "UMG",
                "DeveloperSettings"
				// ... add private dependencies that you statically link with here ...	
			}
			);

        if (Target.bBuildEditor == true)
        {
            PrivateDependencyModuleNames.Add("UnrealEd");
            PrivateDependencyModuleNames.Add("EditorStyle");
            PrivateDependencyModuleNames.Add("Settings");
        }

        DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
