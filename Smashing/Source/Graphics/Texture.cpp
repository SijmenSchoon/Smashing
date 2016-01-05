#include "Texture.h"
#include <iostream> 

void Texture::load(const std::string &file)
{
    SDL_Surface *loadedImage = SDL_LoadBMP(file.c_str());
    SDL_PixelFormat *format = loadedImage->format;
    SDL_Surface *scaledImage = SDL_CreateRGBSurface(0, loadedImage->w * Graphics::Scale,
        loadedImage->h * Graphics::Scale, format->BitsPerPixel, format->Rmask, format->Gmask,
        format->Bmask, format->Amask);

    for (int y = 0; y < scaledImage->h; y++)
    {
        for (int x = 0; x < scaledImage->w; x++)
        {
            int yy = y / Graphics::Scale;
            int xx = x / Graphics::Scale;

            ((uint32_t *)scaledImage->pixels)[y * scaledImage->w + x] =
                ((uint32_t *)loadedImage->pixels)[yy * loadedImage->w + xx];
        }
    }
    
    SDL_FreeSurface(loadedImage);

    if (loadedImage != nullptr)
    {
        texture = SDL_CreateTextureFromSurface(Graphics::Renderer, scaledImage);
        SDL_FreeSurface(scaledImage);

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