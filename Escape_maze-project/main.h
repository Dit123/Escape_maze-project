#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "auth.h"
#include "collision.h"
#include "config.h"
#include "enums.h"
#include "gamelogic.h"
#include "maze.h"
#include "menu.h"
#include "player.h"
#include "renderer.h"
#include "score.h"
#include "timer.h"
#include "utilities.h"
#include "volume.h"

extern int gameState;
extern SDL_Event event;
extern int quit;

void handleCollision(struct Player* player);
void handleInput(SDL_Event event, int* quit, int* moveDirection);
void updateGameState(int moveDirection, struct Player* player, const char maze[MAZE_HEIGHT][MAZE_WIDTH], const struct Enemy *enemy);
void renderGameState(const struct PlayerCharacter *player, const char maze[MAZE_HEIGHT][MAZE_WIDTH], const struct Enemy *enemy);
int CheckCollision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);
int isGameOver(const struct PlayerCharacter *player, const struct Enemy *enemy);
void initializeSDL();
int cleanupSDL();
#endif // MAIN_H