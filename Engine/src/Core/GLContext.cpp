#include "Core/GLContext.h"

namespace Engine
{
    SDL_GLContext GLContext::glContext;
    ImVec4 GLContext::clearColor;

    void GLContext::Init(SDL_Window& window)
    {
        clearColor = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
        SDL_GLContext gl_context = SDL_GL_CreateContext(&window);
        SDL_GL_MakeCurrent(&window, gl_context);
        SDL_GL_SetSwapInterval(1); // Enable vsync
    }

    void GLContext::Clear()
    {
        glViewport(0, 0, (int)ImGui::GetIO().DisplaySize.x, (int)ImGui::GetIO().DisplaySize.y);
        glClearColor(clearColor.x * clearColor.w, clearColor.y * clearColor.w, clearColor.z * clearColor.w, clearColor.w);
        glClear(GL_COLOR_BUFFER_BIT);
    }
}