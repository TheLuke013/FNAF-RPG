#include "Core/GameApplication.h"

namespace Engine
{
	GameApplication::GameApplication()
		: imguiManager(ImGuiManager::Get())
	{
		isRunning = true;
		restartImGui = false;
		clearColor = ImVec4(0.40f, 0.55f, 0.60f, 1.00f);

		REGISTER_EVENT_LISTENER(this);

		CreateWindowMaximized();
		glContext.Init(*window.Get());
		ActivateImGui();
	}

	GameApplication::~GameApplication()
	{

	}

	//IMGUI
	void GameApplication::ActivateImGui()
	{
		imguiManager.Init(window.Get(), &glContext.GetContext());
	}

	void GameApplication::DisableImGui()
	{
		imguiManager.Disable();
	}

	void GameApplication::CreateWindowMaximized()
	{
		window.properties.isMaximized = true;
		if (!window.Create()) { Quit(); }
	}

	void GameApplication::DisableApplication()
	{
		DisableImGui();
		window.Destroy();
	}

	void GameApplication::Run()
	{
		OnReady();

		while (isRunning)
		{
			imguiManager.CreateNewFrame();

			//IMGUI DOCKSPACE
			imguiManager.BeginDockspace();
			if (imguiManager.IsEnabled())
			{
				OnDockspaceUpdate();
				OnMenuBarRender();
			}
			imguiManager.EndDockspace();

			//render client-application imgui
			if (imguiManager.IsEnabled())
			{
				OnImGuiRender();
			}

			//Resart ImGui
			if (restartImGui)
			{
				imguiManager.Restart();
				restartImGui = false;
			}

			glContext.Clear(clearColor);
			OnUpdate(); //updates client-application
			imguiManager.Render();
			window.Update();
		}
	}

	void GameApplication::Quit()
	{
		isRunning = false;
	}

	void GameApplication::_OnEvent(Event e)
	{
		OnEvent(e);

		if (e.type_ == EventType::CLOSE_APPLICATION)
		{
			Quit();
		}
		else if (e.type_ == EventType::RESTART_IMGUI)
		{
			restartImGui = true;
		}
	}
}