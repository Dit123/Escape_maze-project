#include "player.h"

struct Player {
    int x; // Player's X coordinate
    int y; // Player's Y coordinate
    int health; // Player's health
    int score; // Player's score
};

// Initialize a player
struct Player initPlayer(int startX, int startY) {
    struct Player player;
    player.x = startX;
    player.y = startY;
    player.health = 100; // Set an initial health value
    player.score = 0;   // Set an initial score value
    return player;
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
int getPlayerX(struct Player *player) {
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

