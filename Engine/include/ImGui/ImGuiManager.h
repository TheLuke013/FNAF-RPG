#ifndef IMGUI_MANAGER_H
#define IMGUI_MANAGER_H

#include "Core/Window.h"
#include "ImGui/Font.h"

#include <ImGui/imgui.h>
#include <ImGui/imgui_impl_sdl2.h>
#include <ImGui/imgui_impl_opengl2.h>
#include <ImGui/imgui_internal.h>
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>

namespace Engine
{
	struct DockSides
	{
		ImGuiID dock_main;
		ImGuiID dock_left;
		ImGuiID dock_right;
		ImGuiID dock_down;
		ImGuiID dock_left_top;
		ImGuiID dock_left_bottom;
	};

	class ImGuiManager
	{
	public:
		static ImGuiManager& Get();

		void Init(SDL_Window* window, SDL_GLContext* glContext);
		void Disable();
		void Restart();
		void CreateNewFrame();
		void Render();
		void LoadFont(Font* font);

		void BeginDockspace();
		void EndDockspace();

		bool IsEnabled() const { return isEnabled; }

		ImGuiID GetDockspaceID() { return dockspaceID; }
		DockSides& GetDockSides() { return dockSides; }

		int DetectGLContextVersion();

	private:
		ImGuiManager();
		~ImGuiManager();

		SDL_Window* window;
		SDL_GLContext* glContext;
		bool isEnabled;
		bool newFrameIsCalled;
		ImGuiID dockspaceID;
		DockSides dockSides;
		Font* loadedFont;

	};
}

#endif                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   