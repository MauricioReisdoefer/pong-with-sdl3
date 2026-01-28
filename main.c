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
const float BASE_SPEED = 300.0f;

const Color WHITE = {255, 255, 255, 255};
const Color BLACK = {0, 0, 0, 255};

int main(int argc, char *argv[])
{
    Player player1 = {
        .x = 20.0f,
        .y = 200.0f,
        .width = 10.0f,
        .height = 80.0f,
        .speed = 300.0f};

    Player player2 = {
        .x = WIDTH - 30.0f,
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

    SDL_Window *window = SDL_CreateWindow(
        "Pong SDL3",
        WIDTH,
        HEIGHT,
        SDL_WINDOW_RESIZABLE);

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

        /* PLAYER 1 (W / S) */
        if (keys[SDL_SCANCODE_W])
            player1.y -= player1.speed * deltaTime;
        if (keys[SDL_SCANCODE_S])
            player1.y += player1.speed * deltaTime;

        /* PLAYER 2 (↑ / ↓) */
        if (keys[SDL_SCANCODE_UP])
            player2.y -= player2.speed * deltaTime;
        if (keys[SDL_SCANCODE_DOWN])
            player2.y += player2.speed * deltaTime;

        /* MOVIMENTO DA BOLA */
        ball.x += ball.dx * deltaTime;
        ball.y += ball.dy * deltaTime;

        /* COLISÃO COM PAREDES */
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
            ball.x = WIDTH / 2.0f;
            ball.y = HEIGHT / 2.0f;
            ball.dx = 200.0f;
        }

        if (ball.x + ball.width >= WIDTH)
        {
            ball.x = WIDTH / 2.0f;
            ball.y = HEIGHT / 2.0f;
            ball.dx = -200.0f;
        }

        /* COLISÃO COM PLAYER 1 */
        if (check_collision_rect(
                ball.x, ball.y, ball.width, ball.height,
                player1.x, player1.y, player1.width, player1.height))
        {
            ball.x = player1.x + player1.width;
            ball.dx *= -1;

            float hitPos =
                (ball.y + ball.height / 2) -
                (player1.y + player1.height / 2);

            ball.dy = hitPos * 5.0f;
        }

        /* COLISÃO COM PLAYER 2 */
        if (check_collision_rect(
                ball.x, ball.y, ball.width, ball.height,
                player2.x, player2.y, player2.width, player2.height))
        {
            ball.x = player2.x - ball.width;
            ball.dx *= -1;

            float hitPos =
                (ball.y + ball.height / 2) -
                (player2.y + player2.height / 2);

            ball.dy = hitPos * 5.0f;
        }

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
                running = 0;
        }

        render(renderer, &BLACK);
        draw_rect(renderer, &player1, &WHITE);
        draw_rect(renderer, &player2, &WHITE);
        draw_ball(renderer, &ball, &WHITE);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
