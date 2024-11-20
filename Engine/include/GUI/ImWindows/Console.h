#include "ImGui/ImWindow.h"

namespace Engine
{
	class Console : public ImWindow
	{
	public:
		Console() : ImWindow("Console", 0, 599, 1366, 98, true, DockSide::DOWN)
		{

		}

		void OnRender() override
		{
			
		}
	};
}
