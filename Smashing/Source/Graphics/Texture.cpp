#include "Texture.h"

void Texture::load(const std::string &file)
{
    SDL_Surface *loadedImage = SDL_LoadBMP(file.c_str());
    if (loadedImage != nullptr)
    {
        texture = SDL_CreateTextureFromSurface(Graphics::Renderer, loadedImage);
        SDL_FreeSurface(loadedImage);

        if (texture == nullptr)
        {
            // TODO: Make a new exception for this
            throw std::runtime_error("SDL_CreateTextureFromSurface failed (" + Graphics::GetSDLError() + ")");
        }
    }
    else
    {
        // TODO: Make a new exception for this
        throw std::runtime_error("SDL_LoadBMP failed (" + Graphics::GetSDLError() + ")");
    }
}

void Texture::destroy()
{
    if (texture != nullptr)
        SDL_DestroyTexture(texture);
}


void Texture::render(int x, int y)
{
    SDL_Rect dst = { x, y };
    SDL_QueryTexture(texture, nullptr, nullptr, &dst.w, &dst.h);
    SDL_RenderCopy(Graphics::Renderer, texture, nullptr, &dst);
}