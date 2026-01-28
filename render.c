#include <SDL3/SDL.h>
#include <stdio.h>
#include "color.h"
#include "render.h"

void render(SDL_Renderer *renderer, const Color *backgroundColor)
{
    SDL_SetRenderDrawColor(
        renderer,
        backgroundColor->red,
        backgroundColor->green,
        backgroundColor->blue,
        backgroundColor->alpha);

    SDL_RenderClear(renderer);
}