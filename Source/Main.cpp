#include <SDL.h>
#include <iostream>
#include <stdlib.h>
#include "Graphics/Graphics.h"
#include "Graphics/Texture.h"

int main(int argc, char **argv)
{
    Graphics::Init("Smashing", 3);

    Texture texture("Data/Characters/mario.png");

    SDL_SetRenderDrawColor(Graphics::Renderer, 255, 0, 255, SDL_ALPHA_OPAQUE);
    while (true)
    {
        SDL_RenderClear(Graphics::Renderer);
        texture.render(0, 0);
        SDL_RenderPresent(Graphics::Renderer);
    }

    Graphics::Destroy();
}
