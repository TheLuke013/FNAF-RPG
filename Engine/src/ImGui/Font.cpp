#include "ImGui/Font.h"

namespace Engine
{
	Font::Font(const std::string& name, const std::string& path, float size)
	{
		properties.name = name;
		properties.filePath = path;
		properties.size = size;
	}

	void Font::SetSize(float size)
	{
		properties.size = size;
	}
}