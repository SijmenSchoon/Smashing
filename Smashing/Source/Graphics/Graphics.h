#pragma once
#include <string>
#include <SDL.h>

class Graphics
{
    static const int NATIVE_WIDTH = 256;
    static const int NATIVE_HEIGHT = 240;

    static SDL_Window *Window;

public:
    static SDL_Renderer *Renderer;
    static int Scale;

    static void Init(const std::string &title, const int scaling);
    static void Destroy();

    static std::string GetSDLError() { return SDL_GetError(); };
};