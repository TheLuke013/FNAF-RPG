#include "Core/Window.h"
#include "Core/Log.h"
#include "Core/Event.h"

#include <ImGui/imgui_impl_sdl2.h>

#include <sstream>

namespace Engine
{
    Window::Window()
        : window(nullptr)
    {
    }

    Window::Window(const std::string &title, int width, int height, bool maximized)
        : window(nullptr)
    {
        properties.title = title;
        properties.width = width;
        properties.height = height;
        properties.isMaximized = maximized;
    }

    Window::~Window()
    {
        Destroy();
    }

    bool Window::Create()
    {
        // INIT SDL
        if (!SDL_Init(SDL_INIT_EVERYTHING) < 0)
        {
            LOG_FATAL("Failed to initialize SDL");
            return false;
        }
        else
        {
            LOG_INFO("Initialized SDL");
        }

        // SET WINDOW HINTS
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
        SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

        // CREATE WINDOW
        window = SDL_CreateWindow(
            properties.title.c_str(),
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            properties.width,
            properties.height,
            properties.flags);

        if (window == NULL)
        {
            Destroy();
            LOG_FATAL("Failed to create window");
            return false;
        }
        else
        {
            LOG_INFO("Window created");
        }

        if (properties.isMaximized)
        {
            SDL_MaximizeWindow(window);
        }

        return true;
    }

    void Window::Update()
    {
        //Update viewport size
        //OpenGLContext::viewport.width = properties.width;
        //OpenGLContext::viewport.height = properties.height;

        //Update window events
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            ImGui_ImplSDL2_ProcessEvent(&event);
            if (event.type == SDL_QUIT)
                DISPATCH_EVENT(EventType::CLOSE_APPLICATION);
            if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(window))
                DISPATCH_EVENT(EventType::CLOSE_APPLICATION);
        }
        if (SDL_GetWindowFlags(window) & SDL_WINDOW_MINIMIZED)
        {
            SDL_Delay(10);
        }

        SDL_GL_SwapWindow(window);
    }

    void Window::Destroy()
    {
        if (window)
        {
            //SDL_GL_DeleteContext(gl_context);
            SDL_DestroyWindow(window);
            SDL_Quit();
        }
    }
}