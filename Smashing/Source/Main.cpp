#include <SDL.h>
#include <iostream>
#include <stdlib.h>
#include "Graphics/Graphics.h"

int main(int argc, char **argv)
{
    Graphics::Init("Smashing", 768, 720);

    while (true)
    {
        SDL_RenderClear(Graphics::Renderer);

        SDL_RenderPresent(Graphics::Renderer);
    }

    Graphics::Destroy();
}
