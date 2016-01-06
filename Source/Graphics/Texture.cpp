#include "Texture.h"
#include <iostream>
#include <SDL_image.h>

void Texture::load(const std::string &file)
{
    SDL_Surface *loadedImage = IMG_Load(file.c_str());
    if (loadedImage == nullptr)
        throw std::runtime_error("IMG_Load error: " + std::string(IMG_GetError()));

    SDL_PixelFormat *format = loadedImage->format;
    if (format->BitsPerPixel != 32)
        throw std::runtime_error("Texture::load error: Texture is not 32 bit!");

    SDL_Surface *scaledImage = SDL_CreateRGBSurface(0, loadedImage->w * Graphics::Scale,
        loadedImage->h * Graphics::Scale, format->BitsPerPixel, format->Rmask, format->Gmask,
        format->Bmask, format->Amask);
    
    if (scaledImage == nullptr)
        throw std::runtime_error("SDL_CreateRGBSurface error: " + Graphics::GetSDLError());

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
    
    texture = SDL_CreateTextureFromSurface(Graphics::Renderer, scaledImage);
    SDL_FreeSurface(scaledImage);

    if (texture == nullptr)
        // TODO: Make a new exception for this
        throw std::runtime_error("SDL_CreateTextureFromSurface error: " + Graphics::GetSDLError());
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
