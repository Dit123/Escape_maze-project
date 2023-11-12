#include <stdio.h>
#include <stdlib.h>
#include "maze.h"
#include "timer.h"

#define MAZE_WIDTH 21
#define MAZE_HEIGHT 11

#define WALL '#'
#define EMPTY ' '
#define EXIT 'E'

// Function to initialize the maze with walls
void initializeMaze(char maze[MAZE_HEIGHT][MAZE_WIDTH]) {
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            maze[i][j] = WALL;
        }
    }
}

// Function to create a horizontal wall segment
void createHorizontalWall(char maze[MAZE_HEIGHT][MAZE_WIDTH], int x, int y, int length) {
    for (int i = 0; i < length; i++) {
        maze[y][x + i] = EMPTY;
    }
}

// Function to create a vertical wall segment
void createVerticalWall(char maze[MAZE_HEIGHT][MAZE_WIDTH], int x, int y, int length) {
    for (int i = 0; i < length; i++) {
        maze[y + i][x] = EMPTY;
    }
}

// Recursive division algorithm to generate the maze
void recursiveDivision(char maze[MAZE_HEIGHT][MAZE_WIDTH], int x, int y, int width, int height) {
    if (width < 2 || height < 2) {
        return;
    }

    // Choose a random point to create a wall
    int wallX = x + 1 + rand() % (width - 2);
    int wallY = y + 1 + rand() % (height - 2);

    // Create horizontal or vertical wall
    if (width > height) {
        createVerticalWall(maze, wallX, y, height);
        int passageX = x + rand() % (wallX - x + 1);
        maze[wallY][passageX] = EMPTY;
        recursiveDivision(maze, x, y, wallX - x + 1, height);
        recursiveDivision(maze, wallX, y, x + width - wallX, height);
    } else {
        createHorizontalWall(maze, x, wallY, width);
        int passageY = y + rand() % (wallY - y + 1);
        maze[passageY][wallX] = EMPTY;
        recursiveDivision(maze, x, y, width, wallY - y + 1);
        recursiveDivision(maze, x, wallY, width, y + height - wallY);
    }
}

// Generate the maze using the recursive division algorithm
void generateMaze(char maze[MAZE_HEIGHT][MAZE_WIDTH]) {
    initializeMaze(maze);
    recursiveDivision(maze, 1, 1, MAZE_WIDTH - 2, MAZE_HEIGHT - 2);
    maze[0][1] = EXIT;  // Set the entrance
    maze[MAZE_HEIGHT - 1][MAZE_WIDTH - 2] = EXIT;  // Set the exit
}


