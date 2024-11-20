#include "ImGui/ImGuiManager.h"
#include "Core/Log.h"
#include "Core/Event.h"

namespace Engine
{
	ImGuiManager::ImGuiManager()
		: isEnabled(false), newFrameIsCalled(false), loadedFont(nullptr), window(nullptr), glContext(nullptr)
	{
	}

	ImGuiManager::~ImGuiManager()
	{
		Disable();
	}

	ImGuiManager &ImGuiManager::Get()
	{
		static ImGuiManager *instance = new ImGuiManager();
		return *instance;
	}

	void ImGuiManager::Init(SDL_Window* window, SDL_GLContext* glContext)
	{
		ImGuiManager::window = window;

		if (!isEnabled)
		{
			// setup imgui context
			ImGui::CreateContext();
			ImGui::StyleColorsDark();

			ImGuiIO &io = ImGui::GetIO();
			(void)io;
			io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
			io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
			io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
			// io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

			ImGuiStyle &style = ImGui::GetStyle();
			if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
			{
				style.WindowRounding = 0.0f;
				style.Colors[ImGuiCol_WindowBg].w = 1.0f;
			}

			// LOAD FONT IF ANY LOADED
			if (loadedFont != nullptr)
			{
				io.Fonts->AddFontFromFileTTF(loadedFont->properties.filePath.c_str(), loadedFont->properties.size);
				io.Fonts->Build();
			}

			ImGui_ImplSDL2_InitForOpenGL(window, glContext);
    		ImGui_ImplOpenGL2_Init();

			isEnabled = true;
			LOG_INFO("ImGui was enabled");
		}
	}

	void ImGuiManager::Disable()
	{
		if (isEnabled)
		{
			ImGui_ImplOpenGL2_Shutdown();
			ImGui_ImplSDL2_Shutdown();
			ImGui::DestroyContext();

			isEnabled = false;
			newFrameIsCalled = false;
			LOG_INFO("ImGui was disabled");
		}
	}

	void ImGuiManager::Restart()
	{
		Disable();
		Init(window, glContext);
	}

	void ImGuiManager::Render()
	{
		if (isEnabled && newFrameIsCalled)
		{
			ImGui::Render();
			ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());

			if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
			{
				SDL_Window *backup_current_window = SDL_GL_GetCurrentWindow();
				SDL_GLContext backup_current_context = SDL_GL_GetCurrentContext();
				ImGui::UpdatePlatformWindows();
				ImGui::RenderPlatformWindowsDefault();
				SDL_GL_MakeCurrent(backup_current_window, backup_current_context);
			}

			newFrameIsCalled = false;
		}
	}

	void ImGuiManager::LoadFont(Font* font)
	{
		loadedFont = font;
		DISPATCH_EVENT(EventType::RESTART_IMGUI);
	}

	void ImGuiManager::BeginDockspace()
	{
		if (isEnabled)
		{
			ImGui::SetNextWindowPos(ImVec2(0, 0));
			ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);
			ImGui::SetNextWindowBgAlpha(0.0f);

			ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse |
											ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
											ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;

			ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));

			ImGui::Begin("MainDockSpace", nullptr, window_flags);
		}
	}

	void ImGuiManager::EndDockspace()
	{
		if (isEnabled)
		{
			ImGuiID dockspaceID = ImGui::GetID("MainDockSpace");
			ImGui::DockSpace(dockspaceID);
			ImGui::End();

			ImGui::PopStyleVar(3);
		}
	}

	void ImGuiManager::CreateNewFrame()
	{
		if (isEnabled)
		{
			ImGui_ImplOpenGL2_NewFrame();
			ImGui_ImplSDL2_NewFrame();
			ImGui::NewFrame();

			newFrameIsCalled = true;
		}
	}
}