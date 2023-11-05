// player.h

#ifndef PLAYER_H
#define PLAYER_H

// Define player structure
typedef struct {
    int x; // X-coordinate
    int y; // Y-coordinate
    int health; // Player's health
} Player;

// Function to initialize the player
void initPlayer(Player* player, int startX, int startY);

// Function to update the player's position
void updatePlayerPosition(Player* player, int newX, int newY);

// Function to handle player input
void handlePlayerInput(Player* player, char input);

// Function to check if the player has collided with an enemy or obstacle
int checkPlayerCollision(Player* player, const char maze[MAZE_HEIGHT][MAZE_WIDTH]);

#endif

