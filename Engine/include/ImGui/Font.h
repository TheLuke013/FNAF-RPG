#ifndef FONT_H
#define FONT_H

#include <string>

namespace Engine
{
	struct FontProperties
	{
		std::string name;
		std::string filePath;
		float size;
	};

	class Font
	{
	public:
		Font(const std::string& name, const std::string& path, float size);

		void SetSize(float size);

		FontProperties properties;
	};
}

#endif
