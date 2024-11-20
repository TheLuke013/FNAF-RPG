#include "ImGui/ImWindow.h"

namespace Engine
{
	class ContentBrowser : public ImWindow
	{
	public:
		ContentBrowser() : ImWindow("Content Browser", 0, 355, 172, 242, true, DockSide::LEFT_TOP)
		{

		}

		void OnRender() override
		{
			
		}
	};
}
