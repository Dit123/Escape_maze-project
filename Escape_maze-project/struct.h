// structs.h
#ifndef STRUCTS_H
#define STRUCTS_H

#define MAZE_HEIGHT 11
#define MAZE_WIDTH 21

struct PlayerCharacter {
    int x;
    int y;
    int health;
    int score;
};

struct Maze {
    char cells[MAZE_HEIGHT][MAZE_WIDTH];
};

struct Enemy {
    int x;
    int y;
    int health;
};

#endif