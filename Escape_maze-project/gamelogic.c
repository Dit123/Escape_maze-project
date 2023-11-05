#include "structs.h"

int main() {
    // Declare and initialize a player character using the defined struct
    struct PlayerCharacter player;
    player.x = 100;
    player.y = 100;
    player.health = 100;

    // Declare and initialize a maze using the defined struct
    struct Maze gameMaze;

    // Initialize the maze elements and properties
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            gameMaze.cells[i][j] = EMPTY;
        }
    }
    gameMaze.cells[2][2] = WALL;
    gameMaze.cells[3][3] = WALL;

    struct Enemy enemy;
    enemy.x = 200;
    enemy.y = 200;
    enemy.health = 50;

    // Other game logic using these structures
    // For example, you can implement collision detection
    if (gameMaze.cells[player.x][player.y] == WALL) {
        // Handle player collision with a wall
        player.health -= 10;
    }

    if (gameMaze.cells[enemy.x][enemy.y] == WALL) {
        // Handle enemy collision with a wall
        enemy.health -= 5;
    }

    // Update player position
    player.x += 5;
    player.y += 5;

    // Update enemy behavior
    // For example, you can make the enemy move toward the player
    int dx = player.x - enemy.x;
    int dy = player.y - enemy.y;
    double distance = sqrt(dx * dx + dy * dy);

    if (distance > 0) {
        dx = dx / distance;
        dy = dy / distance;
    }

    enemy.x += dx * enemySpeed;
    enemy.y += dy * enemySpeed;

    return 0;
}
