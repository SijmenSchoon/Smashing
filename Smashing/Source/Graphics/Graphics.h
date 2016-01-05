#pragma once
#include <string>
#include <SDL.h>

class Graphics
{
    static SDL_Window *Window;

public:
    static SDL_Renderer *Renderer;

    static void Init(const std::string &title, int width, const int height);
    static void Destroy();

    static std::string GetSDLError() { return SDL_GetError(); };
};