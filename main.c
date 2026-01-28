#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>

struct Color
{
    int red;
    int green;
    int blue;
    int alpha;
};

void draw_pixel(SDL_Renderer *renderer, int x, int y, struct Color *color)
{
    SDL_SetRenderDrawColor(renderer, color->red, color->green, color->blue, color->alpha);
    SDL_RenderPoint(renderer, x, y);
}

const int HEIGHT = 500;
const int WIDTH = 500;
struct Color WHITE = {255, 255, 255, 255};

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
    draw_pixel(renderer, WIDTH / 2, HEIGHT / 2, &WHITE);

    SDL_RenderPresent(renderer);

    SDL_Delay(5000);
    SDL_Quit();

    free(window);
}
