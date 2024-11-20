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
        void Init(SDL_Window& window);
        void Clear(ImVec4 clearColor);

        SDL_GLContext& GetContext() {   return glContext;   }

    private:
        SDL_GLContext glContext;
    };
}

#endif