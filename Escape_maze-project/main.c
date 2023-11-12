#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "auth.h"
#include "collision.h"
#include "config.h"
#include "enums.h"
#include "gamelogic.h"
#include "input.h"
#include "maze.h"
#include "menu.h"
#include "player.h"
#include "renderer.h"
#include "score.h"
#include "timer.h"
#include "utilities.h"
#include "volume.h"

int main() {
    // Initialize SDL and other components
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        fprintf(stderr, "SDL initialization failed: %s\n", SDL_GetError());
        return 1;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        fprintf(stderr, "SDL_Mixer initialization failed: %s\n", Mix_GetError());
        return 1;
    }

    // Initialize other components (config, timer, etc.)
    Config gameConfig;
    if (!LoadConfig("config.dat")) {
        fprintf(stderr, "Failed to load config file. Using default settings.\n");
    }

    struct Timer gameTimer = initTimer();

    // Initialize SDL Window and Renderer
    if (Renderer_Init("Your Game Title", gameConfig.screenWidth, gameConfig.screenHeight) != 0) {
        fprintf(stderr, "Renderer initialization failed.\n");
        Mix_CloseAudio();
        SDL_Quit();
        return 1;
    }

    // Initialize other components (player, maze, etc.)
    struct Player player;
    initPlayer(&player, 0, 0);

    char maze[MAZE_HEIGHT][MAZE_WIDTH];
    generateMaze(maze);

    // Main game loop
    while (gameState != GAME_OVER) {
        // Handle input
        int moveDirection = 0;
        handleInput(event, &quit, &moveDirection);

        // Update game state based on input
        updateGameState(moveDirection, &player, maze);

        // Render game state
        Renderer_Clear();
        renderGameState(&player, maze);
        Renderer_Render();

        // Update timer
        updateTimer(&gameTimer);

        // Other game logic (collision detection, scoring, etc.)
        int collisionResult = CheckCollision(player.x, player.y, PLAYER_WIDTH, PLAYER_HEIGHT, 0, 0, 0, 0);
        if (collisionResult) {
            // Handle collision
        }

        // Your scoring logic here
        increaseScore(&player, 10);

        // Check for game over condition
        if (isGameOver(&player)) {
            gameState = GAME_OVER;
        }
    }

    // Cleanup and exit
    Renderer_Close();
    Mix_CloseAudio();
    SDL_Quit();

    return 0;
}