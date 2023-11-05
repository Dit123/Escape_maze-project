// structs.h
#ifndef STRUCTS_H
#define STRUCTS_H

struct PlayerCharacter {
    int x;
    int y;
    int health;
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

