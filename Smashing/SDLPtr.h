#pragma once

#include <SDL.h>
#include <memory>

template<typename T, typename Del>
using sdl_ptr = std::unique_ptr<T, Del>;


using SDL_WindowPtr = sdl_ptr<SDL_Window, decltype(SDL_DestroyWindow)*>;
using SDL_TexturePtr = sdl_ptr<SDL_Texture, decltype(SDL_DestroyTexture)*>;
using SDL_RendererPtr = sdl_ptr<SDL_Renderer, decltype(SDL_DestroyRenderer)*>;
using SDL_SurfacePtr = sdl_ptr<SDL_Surface, decltype(SDL_FreeSurface)*>;


auto make_window_ptr(SDL_Window* win) -> SDL_WindowPtr
{
	return SDL_WindowPtr(win, SDL_DestroyWindow);
}


auto make_texture_ptr(SDL_Texture* tex) -> SDL_TexturePtr
{
	return SDL_TexturePtr(tex, SDL_DestroyTexture);
}


auto make_renderer_ptr(SDL_Renderer* ren) -> SDL_RendererPtr
{
	return SDL_RendererPtr(ren, SDL_DestroyRenderer);
}


auto make_surface_ptr(SDL_Surface* surf) -> SDL_SurfacePtr
{
	return SDL_SurfacePtr(surf, SDL_FreeSurface);
}