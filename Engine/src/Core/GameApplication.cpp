#include "Core/GameApplication.h"

namespace Engine
{
	GameApplication::GameApplication()
		: imguiManager(ImGuiManager::Get())
	{
		isRunning = true;
		restartImGui = false;

		REGISTER_EVENT_LISTENER(this);

		CreateWindowMaximized();
		GLContext::Init(*window.Get());
		ActivateImGui();
	}

	GameApplication::~GameApplication()
	{

	}

	void GameApplication::ActivateImGui()
	{
		imguiManager.Init(window.Get(), &GLContext::GetContext());
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
		//load imgui font
		std::shared_ptr<Font> imguiFont = std::make_shared<Font>("Roboto Regular", "../assets/fonts/Roboto-Regular.ttf", 16.f);
		imguiManager.LoadFont(imguiFont.get());

		OnReady();

		while (isRunning)
		{
			imguiManager.CreateNewFrame();

			imguiManager.BeginDockspace();
			if (imguiManager.IsEnabled())
			{
				UPDATE_ALL_IM_WINDOW_DOCKSPACE(imguiManager);
				OnDockspaceUpdate();
				OnMenuBarRender();
			}
			imguiManager.EndDockspace();

			if (imguiManager.IsEnabled())
			{
				OnImGuiRender();
				UPDATE_ALL_IM_WINDOW();
			}

			if (restartImGui)
			{
				imguiManager.Restart();
				restartImGui = false;
			}

			GLContext::Clear();
			OnUpdate();
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