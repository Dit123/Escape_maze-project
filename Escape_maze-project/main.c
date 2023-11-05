#include <stdio.h>
#include <SDL2/SDL.h>
#include "game.h"  // Include your game-related header files
#include "menu.h"
#include "renderer.h"
#include "audio_manager.h"  // Include your audio manager
#include "enums.h"

int main() {
    // Initialize SDL2 and game components
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "SDL initialization failed: %s\n", SDL_GetError());
        return 1;
    }

    // Create a window and renderer
    if (InitializeSDL() != 0) {
        fprintf(stderr, "SDL initialization failed\n");
        return 1;
    }

    SDL_Window* window = CreateWindow("Your Game Window", screenWidth, screenHeight);
    SDL_Renderer* renderer = CreateRenderer(window);

    // Initialize the audio manager
    if (InitializeAudio() != 0) {
        fprintf(stderr, "Audio manager initialization failed\n");
        return 1;
    }

    // Load game assets and initialize game variables
    if (LoadGameAssets() != 0) {
        fprintf(stderr, "Failed to load game assets\n");
        return 1;
    }

    // Initialize game state
    enum GameState gameState = MENU;
    int quit = 0;

    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            }

            // Pass input events to your input manager
            HandleInputEvent(event, &gameState);
        }

        // Update the game based on its current state
        switch (gameState) {
            case MENU:
                HandleMenu();
                break;

            case PLAYING:
                UpdateGame();
                break;

            case GAME_OVER:
                HandleGameOver();
                break;
        }

        // Render the game using your rendering functions
        RenderGame(renderer);
    }

    // Cleanup and quit
    QuitAudio();  // Close audio resources
    SDL_Quit();   // Quit SDL

    return 0;
}

