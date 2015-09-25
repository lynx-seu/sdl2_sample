#include "SDL.h"

int main(int argc, char *argv[])
{
    SDL_Window *window = 0;
    SDL_Renderer *render = 0;


    if (SDL_Init(SDL_INIT_EVERYTHING ^ SDL_INIT_HAPTIC) < 0) {
        fprintf(stderr, "SDL init failed\n");
        return -1;
    }

    window = SDL_CreateWindow("test",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              640, 480, SDL_WINDOW_SHOWN);
    if (window == 0) {
        fprintf(stderr, "Create Window failed");
        return -1;
    }

    render = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
    SDL_RenderClear(render);
    SDL_RenderPresent(render);

    SDL_Delay(5000);

    return 0;
}
