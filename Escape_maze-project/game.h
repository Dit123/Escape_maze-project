#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "enums.h"

int CheckCollision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);
// Function to start a new game
void StartNewGame();
char GetPlayerInput();
// Function to update the game
void UpdateGame();

// Function to handle game over
void HandleGameOver();

#endif

