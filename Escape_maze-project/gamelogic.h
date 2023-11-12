#ifndef GAMELOGIC_H
#define GAMELOGIC_H

// Function to initialize the game logic
void initializeGame(struct PlayerCharacter *player, struct Maze *gameMaze, struct Enemy *enemy);

// Function to update the game logic
void updateGame(struct PlayerCharacter *player, struct Maze *gameMaze, struct Enemy *enemy);

#endif

