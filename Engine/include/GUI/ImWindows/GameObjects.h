#include "ImGui/ImWindow.h"

namespace Engine
{
	class GameObjects : public ImWindow
	{
	public:
		GameObjects() : ImWindow("Game Objects", 0, 19, 172, 334, true, DockSide::LEFT_BOTTOM)
		{

		}

		void OnRender() override
		{
			
		}
	};
}
