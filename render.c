#include <SDL3/SDL.h>
#include <stdio.h>
#include "color.h"
#include "render.h"
#include "player.h"
#include "ball.h"

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

void draw_rect(SDL_Renderer *renderer, Player *player, const Color *color)
{
    SDL_FRect rect = {
        player->x,
        player->y,
        player->width,
        player->height};

    SDL_SetRenderDrawColor(
        renderer,
        color->red,
        color->green,
        color->blue,
        color->alpha);

    SDL_RenderFillRect(renderer, &rect);
}

void draw_ball(SDL_Renderer *renderer, Ball *ball, const Color *color)
{
    SDL_FRect ballRect = {
        ball->x,
        ball->y,
        ball->width,
        ball->height};

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &ballRect);
}