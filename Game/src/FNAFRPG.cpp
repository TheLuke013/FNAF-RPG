#include "FNAFRPG.h"

namespace Game
{
	FNAFRPG::FNAFRPG()
	{
		
	}

	FNAFRPG::~FNAFRPG()
	{

	}

	void FNAFRPG::OnReady()
	{
		
	}

	void FNAFRPG::OnUpdate()
	{

	}

	void FNAFRPG::OnEvent(Engine::Event e)
	{
		
	}

	void FNAFRPG::OnImGuiRender()
	{
		
	}

	void FNAFRPG::OnMenuBarRender()
	{
		if (ImGui::BeginMenuBar())
		{
			//FILE
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("Config")) { SET_IM_WINDOW_VISIBLE("Configuration", true); }

				ImGui::Separator();

				if (ImGui::MenuItem("Exit", "Alt+F4")) { Quit(); }
				ImGui::EndMenu();
			}
			ImGui::EndMenuBar();
		}
	}

	void FNAFRPG::OnDockspaceUpdate()
	{
		
	}
}

Engine::GameApplication* Engine::CreateApplication()
{
	return new Game::FNAFRPG();
}