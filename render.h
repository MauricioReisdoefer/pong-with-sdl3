#ifndef RENDER_H
#define RENDER_H

#include <SDL3/SDL.h>
#include "color.h"
#include "player.h"

void render(SDL_Renderer *renderer, const Color *backgroundColor);
void draw_rect(SDL_Renderer *renderer, Player *player, const Color *color);

#endif