#ifndef IM_WINDOW_MANAGER_H
#define IM_WINDOW_MANAGER_H

#include "ImGui/ImWindow.h"

#include <string>
#include <vector>
#include <unordered_map>

namespace Engine
{
	class ImWindowManager
	{
	public:
		static ImWindowManager& Get();

		void Register(ImWindow* imWindow_);
		void UpdateAllWindows();
		void UpdateAllWindowsDockspace(ImGuiManager& imguiManager);
		void SetWindowVisible(const std::string& windowName, bool visible);

	private:
		ImWindowManager() {}

		std::vector<ImWindow*> windows;
		std::unordered_map<std::string, ImWindow*> windowsMap;
	};
}

#define UPDATE_ALL_IM_WINDOW() Engine::ImWindowManager::Get().UpdateAllWindows();
#define UPDATE_ALL_IM_WINDOW_DOCKSPACE(imguiManager) Engine::ImWindowManager::Get().UpdateAllWindowsDockspace(imguiManager);
#define REGISTER_IM_WINDOW(imWindow_) Engine::ImWindowManager::Get().Register(imWindow_);
#define SET_IM_WINDOW_VISIBLE(windowName, visible) Engine::ImWindowManager::Get().SetWindowVisible(windowName, visible);

#endif
