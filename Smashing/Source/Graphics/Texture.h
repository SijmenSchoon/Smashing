#pragma once
#include <string>
#include <SDL.h>
#include "Graphics.h"

class Texture
{
    SDL_Texture *texture;

public:
    Texture() { };
    Texture(const std::string &file) { load(file); };
    ~Texture() { destroy(); };

    void load(const std::string &file);
    void destroy();

    void render(int x, int y);
};