#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

// Define game states
enum GameState {
    MENU,
    PLAYING,
    GAME_OVER
};

// Function to start a new game
void StartNewGame();

// Function to update the game
void UpdateGame();

// Function to handle game over
void HandleGameOver();

#endif

