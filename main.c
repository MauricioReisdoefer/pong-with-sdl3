#include <SDL3/SDL.h>

#include <stdio.h>
#include <stdlib.h>

#include "color.h"
#include "render.h"
#include "player.h"
#include "ball.h"
#include "collision.h"

const int HEIGHT = 500;
const int WIDTH = 750;
const Color WHITE = {255, 255, 255, 255};
const Color BLACK = {0, 0, 0, 0};

int main(int argc, char *argv[])
{
    Player player = {
        .x = 20.0f,
        .y = 200.0f,
        .width = 10.0f,
        .height = 80.0f,
        .speed = 300.0f};

    Ball ball = {
        .x = WIDTH / 2.0f - 5.0f,
        .y = HEIGHT / 2.0f - 5.0f,
        .width = 10.0f,
        .height = 10.0f,
        .dx = 200.0f,
        .dy = 200.0f};

    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("SDL_Init Failed!");
        return -1;
    }
    SDL_Window *window;
    window = SDL_CreateWindow("", WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);

    int running = 1;
    SDL_Event event;

    Uint64 lastTime = SDL_GetTicks();
    float deltaTime;

    while (running)
    {

        Uint64 currentTime = SDL_GetTicks();
        deltaTime = (currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;

        const bool *keys = SDL_GetKeyboardState(NULL);

        if (keys[SDL_SCANCODE_S] == true)
        {
            player.y += player.speed * deltaTime;
        }

        if (keys[SDL_SCANCODE_W] == true)
        {
            player.y -= player.speed * deltaTime;
        }

        ball.x += ball.dx * deltaTime;
        ball.y += ball.dy * deltaTime;

        if (ball.y <= 0)
        {
            ball.y = 0;
            ball.dy *= -1;
        }

        if (ball.y + ball.height >= HEIGHT)
        {
            ball.y = HEIGHT - ball.height;
            ball.dy *= -1;
        }

        if (ball.x <= 0)
        {
            ball.x = 0;
            ball.dx *= -1;
        }

        if (ball.x + ball.width >= WIDTH)
        {
            ball.x = WIDTH - ball.width;
            ball.dx *= -1;
        }

        if (check_collision_rect(
                ball.x, ball.y, ball.width, ball.height,
                player.x, player.y, player.width, player.height))
        {
            ball.x = player.x + player.width;
            ball.dx *= -1;
            float hitPos = (ball.y + ball.height / 2) - (player.y + player.height / 2);
            ball.dy = hitPos * 5.0f;
        }

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
                running = 0;
        }
        render(renderer, &BLACK);
        draw_rect(renderer, &player, &WHITE);
        draw_ball(renderer, &ball, &WHITE);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
