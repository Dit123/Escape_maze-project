#include <SDL2/SDL.h>
#include "input.h"

// Function to initialize input
void initInput() {
    // Initialize SDL subsystems for input
    SDL_InitSubSystem(SDL_INIT_JOYSTICK);
    SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER);
    SDL_InitSubSystem(SDL_INIT_EVENTS);
}

// Function to handle user input
void handleInput(SDL_Event event, int* quit, int* moveDirection) {
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                *quit = 1;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_UP:
                        *moveDirection = MOVE_UP;
                        break;
                    case SDLK_DOWN:
                        *moveDirection = MOVE_DOWN;
                        break;
                    case SDLK_LEFT:
                        *moveDirection = MOVE_LEFT;
                        break;
                    case SDLK_RIGHT:
                        *moveDirection = MOVE_RIGHT;
                        break;
                }
                break;
            default:
                break;
        }
    }
}

// Function to clean up input
void cleanUpInput() {
    SDL_QuitSubSystem(SDL_INIT_JOYSTICK);
    SDL_QuitSubSystem(SDL_INIT_GAMECONTROLLER);
    SDL_QuitSubSystem(SDL_INIT_EVENTS);
}

