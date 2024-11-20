#ifndef GL_CONTEXT_H
#define GL_CONTEXT_H

#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>

#include "ImGui/imgui.h"

namespace Engine
{
    class GLContext
    {
    public:
        static void Init(SDL_Window& window);
        static void Clear();

        static SDL_GLContext& GetContext() {   return glContext;   }
        static ImVec4& GetClearColor() {   return clearColor;   }

    private:
        static SDL_GLContext glContext;
        static ImVec4 clearColor;
    };
}

#endif