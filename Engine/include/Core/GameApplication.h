#ifndef GAME_APPLICATION_H
#define GAME_APPLICATION_H

#include "Core/Log.h"
#include "Core/Event.h"
#include "Core/Window.h"
#include "Core/GLContext.h"
#include "ImGui/ImGuiManager.h"

namespace Engine
{
	class GameApplication : public EventListener
	{
	public:
		GameApplication();
		virtual ~GameApplication();

		virtual void OnEvent(Event e) = 0;
		virtual void OnReady() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnImGuiRender() = 0;
		virtual void OnMenuBarRender() = 0;
		virtual void OnDockspaceUpdate() = 0;

		void ActivateImGui();
		void DisableImGui();
		void CreateWindowMaximized();
		void DisableApplication();

		Window& GetWindow() { return window; }

		void Run();
		void Quit();

	private:
		bool isRunning;
		bool restartImGui;
		Window window;
		GLContext glContext;
		ImGuiManager& imguiManager;
		ImVec4 clearColor;

		void _OnEvent(Event e) override;
	};

	GameApplication* CreateApplication();
}

#endif