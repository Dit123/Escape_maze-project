#include <stdio.h>
#include "player.h"
#include "maze.h"

struct Player {
    int x;
    int y;
    int health;
    int score;
};

// Initialize a player
void initPlayer(struct Player *player, int startX, int startY) {
    player->x = startX;
    player->y = startY;
    player->health = 100; // Set an initial health value
    player->score = 0;   // Set an initial score value
}

int checkPlayerCollision( struct Player* player, const char maze[MAZE_HEIGHT][MAZE_WIDTH]) {
    int nextX = player->x;
    int nextY = player->y;
    if (nextX < 0 || nextX >= MAZE_WIDTH || nextY < 0 || nextY >= MAZE_HEIGHT) {
        return 1;
    }
    if (maze[nextY][nextX] == '#') {
        return 1; // Collision with a wall
    }
    player->x = nextX;
    player->y = nextY;

    return 0;
}

// Move the player
void movePlayer(struct Player *player, int deltaX, int deltaY) {
    player->x += deltaX;
    player->y += deltaY;
}

// Increase the player's score
void increaseScore(struct Player *player, int points) {
    player->score += points;
}

// Decrease the player's health
void decreaseHealth(struct Player *player, int damage) {
    player->health -= damage;
}

// Check if the player is alive
int isPlayerAlive(struct Player *player) {
    return player->health > 0;
}

// Get the player's X coordinate
 int getPlayerX(struct Player *player){
    return player->x;
}

// Get the player's Y coordinate
int getPlayerY(struct Player *player) {
    return player->y;
}

// Get the player's score
int getPlayerScore(struct Player *player) {
    return player->score;
}

// Get the player's health
int getPlayerHealth(struct Player *player) {
    return player->health;
}

int main() {
    // Create a player
    struct Player player;
    initPlayer(&player, 0, 0); // Initialize the player at position (0, 0)

    // Example usage of player functions
    movePlayer(&player, 1, 0); // Move the player right
    increaseScore(&player, 10); // Increase player's score by 10
    decreaseHealth(&player, 20); // Decrease player's health by 20

    // Display player information
    printf("Player Position: (%d, %d)\n", getPlayerX(&player), getPlayerY(&player));
    printf("Player Score: %d\n", getPlayerScore(&player));
    printf("Player Health: %d\n", getPlayerHealth(&player));

    // Check if the player is alive
    if (isPlayerAlive(&player)) {
        printf("Player is alive!\n");
    } else {
        printf("Player is not alive.\n");
    }

    return 0;
}