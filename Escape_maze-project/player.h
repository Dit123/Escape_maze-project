#ifndef PLAYER_H
#define PLAYER_H

#define MAZE_HEIGHT 11
#define MAZE_WIDTH 21

// Define player structure
struct Player;

void initPlayer(struct Player *player, int startX, int startY);
int checkPlayerCollision(struct Player *player, const char maze[MAZE_HEIGHT][MAZE_WIDTH]);
void movePlayer(struct Player *player, int deltaX, int deltaY);
void increaseScore(struct Player *player, int points);
void decreaseHealth(struct Player *player, int damage);
int isPlayerAlive(struct Player *player);
int getPlayerX(struct Player *player);
int getPlayerY(struct Player *player);
int getPlayerScore(struct Player *player);
int getPlayerHealth(struct Player *player);

#endif

