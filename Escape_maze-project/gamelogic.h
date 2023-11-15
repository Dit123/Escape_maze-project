// gamelogic.h
#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "struct.h"

// Function to initialize the game logic
void initializeGame(struct PlayerCharacter *player, struct Maze *gameMaze, struct Enemy *enemy);
// Function to update the game logic
void updateGame(struct PlayerCharacter *player, struct Maze *gameMaze, struct Enemy *enemy);
int isGameOver(const struct PlayerCharacter *player, const struct Enemy *enemy);
void renderGameState(const struct PlayerCharacter *player, const struct Maze *gameMaze, const struct Enemy *enemy);

#endif // GAMELOGIC_H
