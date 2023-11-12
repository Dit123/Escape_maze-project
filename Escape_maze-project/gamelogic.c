#include "gamelogic.h"
#include <math.h>
#include "structs.h"

void initializeGame(struct PlayerCharacter *player, struct Maze *gameMaze, struct Enemy *enemy) {
    // Initialize player, maze, and enemy here
    player->x = 100;
    player->y = 100;
    player->health = 100;

    // Initialize the maze elements and properties
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            gameMaze->cells[i][j] = EMPTY;
        }
    }
    gameMaze->cells[2][2] = WALL;
    gameMaze->cells[3][3] = WALL;

    enemy->x = 200;
    enemy->y = 200;
    enemy->health = 50;
}

void updateGame(struct PlayerCharacter *player, struct Maze *gameMaze, struct Enemy *enemy) {
    // Implement your game logic updates here
    if (gameMaze->cells[player->x][player->y] == WALL) {
        // Handle player collision with a wall
        player->health -= 10;
    }

    if (gameMaze->cells[enemy->x][enemy->y] == WALL) {
        // Handle enemy collision with a wall
        enemy->health -= 5;
    }

    // Update player position
    player->x += 5;
    player->y += 5;

    // Update enemy behavior
    // For example, you can make the enemy move toward the player
    int dx = player->x - enemy->x;
    int dy = player->y - enemy->y;
    double distance = sqrt(dx * dx + dy * dy);

    if (distance > 0) {
        dx = dx / distance;
        dy = dy / distance;
    }

    enemy->x += dx * enemySpeed;
    enemy->y += dy * enemySpeed;
}
