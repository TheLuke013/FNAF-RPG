#include "ImGui/ImWindow.h"

namespace Engine
{
	class DetailsPanel : public ImWindow
	{
	public:
		DetailsPanel() : ImWindow("Details Panel", 1184, 19, 182, 578, true, DockSide::RIGHT)
		{

		}

		void OnRender() override
		{
			
		}
	};
}
