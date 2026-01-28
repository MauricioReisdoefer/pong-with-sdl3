#ifndef RENDER_H
#define RENDER_H

#include <SDL3/SDL.h>
#include "color.h"
#include "player.h"
#include "ball.h"

void render(SDL_Renderer *renderer, const Color *backgroundColor);
void draw_rect(SDL_Renderer *renderer, Player *player, const Color *color);
void draw_ball(SDL_Renderer *renderer, Ball *ball, const Color *color);

#endif