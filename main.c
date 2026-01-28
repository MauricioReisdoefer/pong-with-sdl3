#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>

const int HEIGHT = 500;
const int WIDTH = 500;

int main(int argc, char *argv[])
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("SDL_Init Failed!");
        return -1;
    }
    SDL_Window *window;
    window = SDL_CreateWindow("", WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);

    // Clears Screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Create a White Pixel
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderPoint(renderer, WIDTH / 2, HEIGHT / 2);

    SDL_RenderPresent(renderer);

    SDL_Delay(5000);
    SDL_Quit();

    free(window);
}
