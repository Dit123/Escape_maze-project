#include "player.h"
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
#include "renderer.h"
#include "score.h"
#include "timer.h"
#include "utilities.h"
#include "volume.h"
#include "main.h"
#include "globals.h"

#define MAZE_HEIGHT 11
#define MAZE_WIDTH 21


// Declare an instance of the Enemy struct
struct Enemy enemy;

int gameState;

void handleCollision(struct Player* player) {
    decreaseHealth(player, 10);
    initPlayer(player, 0, 0);
}

void handleInput(SDL_Event event, int* quit, int* moveDirection);
void updateGameState(int moveDirection, struct Player* player, const char maze[MAZE_HEIGHT][MAZE_WIDTH], const struct Enemy *enemy);
void renderGameState(const struct PlayerCharacter *player, const char maze[MAZE_HEIGHT][MAZE_WIDTH], const struct Enemy *enemy);
int CheckCollision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);
int isGameOver(const struct PlayerCharacter *player, const struct Enemy *enemy);

#define PLAYER_WIDTH 40
#define PLAYER_HEIGHT 40

void initializeSDL();
int runAuthCode();
int configureGame();
int menuGame();
int playerGame();
int rendererGame();
int scoreGame();
int timerGame();
int utilitiesGame();
int volumeGame();
int cleanupSDL();


int main() {
    initializeSDL();
    runAuthCode();
    configureGame();
    menuGame();
    playerGame();
    rendererGame();
    scoreGame();
    timerGame();
    utilitiesGame();
    volumeGame();
    cleanupSDL();

    // Initialize SDL and other components
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        fprintf(stderr, "SDL initialization failed: %s\n", SDL_GetError());
        return 1;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        fprintf(stderr, "SDL_Mixer initialization failed: %s\n", Mix_GetError());
        SDL_Quit();
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
        updateGameState(moveDirection, &player, &maze, &enemy);

        // Render game state
        Renderer_Clear();
        renderGameState(&player, &maze, &enemy);
        Renderer_Render();


        // Update timer
        updateTimer(&gameTimer);

        // Other game logic (collision detection, scoring, etc.)
        int collisionResult = CheckCollision(player.x, player.y, PLAYER_WIDTH, PLAYER_HEIGHT, 0, 0, 0, 0);
        if (collisionResult) {
            // Handle collision
            handleCollision(&player);
        }

        // Your scoring logic here
        increaseScore(&player, 10);

        // Check for game over condition
        if (isGameOver(&player, &enemy)) {
            gameState = GAME_OVER;
        }
    }
    cleanupSDL();
    return 0;
}

void initializeSDL() {
    // Initialize SDL and other components
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        fprintf(stderr, "SDL initialization failed: %s\n", SDL_GetError());
        exit(1);
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        fprintf(stderr, "SDL_Mixer initialization failed: %s\n", Mix_GetError());
        SDL_Quit();
        exit(1);
    }
}

int cleanupSDL() {
    // Cleanup and exit
    Renderer_Close();
    Mix_CloseAudio();
    SDL_Quit();

    return 0;
}
