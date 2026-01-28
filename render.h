#ifndef RENDER_H
#define RENDER_H

#include <SDL3/SDL.h>
#include "color.h"

void render(SDL_Renderer *renderer, const Color *backgroundColor);

#endif