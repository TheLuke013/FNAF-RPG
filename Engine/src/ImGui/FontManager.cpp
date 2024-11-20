#include "ImGui/FontManager.h"
#include "ImGui/Font.h"
#include "Core/IO/IOUtils.h"

namespace Engine
{
	FontManager& FontManager::Get()
	{
		static FontManager* instance = new FontManager();
		return *instance;
	}

	void FontManager::AddFont(Font* font)
	{
		fonts.push_back(font);
		fontsMap[font->properties.name] = font;
	}

	void FontManager::FindFonts(const std::string& directoryPath, const std::string& fontType)
	{
		std::vector<std::string> fontsPath = IOUtils::GetFilesWithExtension(directoryPath, fontType);
		for (const std::string& fontPath : fontsPath)
    	{
			std::string name = fontPath;
        	Font* font = new Font(fontPath, name, 16.f);
			AddFont(font);
    	}
	}
}