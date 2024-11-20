#include "ImGui/ImWindow.h"
#include "Core/GLContext.h"

namespace Engine
{
	class Config : public ImWindow
	{
	public:
		Config() : ImWindow("Configuration", 397, 43, 678, 520, false, DockSide::NONE)
		{
			properties.flags = ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse;
		}

		void OnRender() override
		{
			ImGui::ColorEdit3("clear color", (float*)&GLContext::GetClearColor());
		}
	};
}
