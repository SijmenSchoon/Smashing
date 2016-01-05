#include "Graphics.h"
#include <stdexcept>
#include <SDL.h>

SDL_Renderer *Graphics::Renderer;
SDL_Window *Graphics::Window;
int Graphics::Scale;

void Graphics::Init(const std::string &title, const int scale)
{
    Scale = scale;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        throw std::runtime_error("SDL_Init error: " + GetSDLError());

    Window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
        NATIVE_WIDTH * scale, NATIVE_HEIGHT * scale, SDL_WINDOW_SHOWN);
    if (Window == nullptr)
    {
        std::string error = GetSDLError();
        SDL_Quit();
        throw std::runtime_error("SDL_CreateWindow error: " + error);
    }

    Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (Renderer == nullptr)
    {
        std::string error = GetSDLError();
        SDL_DestroyWindow(Window);
        SDL_Quit();
        throw std::runtime_error("SDL_DestroyWindow error: " + error);
    }
}

void Graphics::Destroy()
{
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    SDL_Quit();
}