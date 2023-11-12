#include <SDL2/SDL.h>

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL2 initialization failed: %s\n", SDL_GetError());
        return 1;
    }

    // SDL2 is successfully initialized
    SDL_Quit();
    return 0;
}

