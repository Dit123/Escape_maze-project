#ifndef MAZE_H
#define MAZE_H

void initializeMaze(char maze[MAZE_HEIGHT][MAZE_WIDTH]);
void createHorizontalWall(char maze[MAZE_HEIGHT][MAZE_WIDTH], int x, int y, int length);
void createVerticalWall(char maze[MAZE_HEIGHT][MAZE_WIDTH], int x, int y, int length);
void recursiveDivision(char maze[MAZE_HEIGHT][MAZE_WIDTH], int x, int y, int width, int height);
void generateMaze(char maze[MAZE_HEIGHT][MAZE_WIDTH]);


#endif
