#ifndef MAZE_H
#define MAZE_H

#define MAZE_HEIGHT 11
#define MAZE_WIDTH  21

#define WALL '#'
#define EMPTY ' '
#define EXIT 'E'

void initializeMaze(char maze[MAZE_HEIGHT][MAZE_WIDTH]);
void createHorizontalWall(char maze[MAZE_HEIGHT][MAZE_WIDTH], int x, int y, int length);
void createVerticalWall(char maze[MAZE_HEIGHT][MAZE_WIDTH], int x, int y, int length);
void recursiveDivision(char maze[MAZE_HEIGHT][MAZE_WIDTH], int x, int y, int width, int height);
void generateMaze(char maze[MAZE_HEIGHT][MAZE_WIDTH]);


#endif
