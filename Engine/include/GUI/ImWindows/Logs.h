#include "ImGui/ImWindow.h"

namespace Engine
{
	class Logs : public ImWindow
	{
	public:
		Logs() : ImWindow("Logs", 0, 599, 1366, 136, true, DockSide::DOWN)
		{

		}

		void OnRender() override
		{
			
		}
	};
}
