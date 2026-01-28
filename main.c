#include <SDL3/SDL.h>
#include <stdio.h>

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

    SDL_Delay(5000);
    SDL_Quit();

    free(window);
}
