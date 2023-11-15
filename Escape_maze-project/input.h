#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>

#define MOVE_UP 0
#define MOVE_DOWN 1
#define MOVE_LEFT 2
#define MOVE_RIGHT 3

void initInput();
void handleInput(SDL_Event event, int* quit, int* moveDirection);
void cleanUpInput();

#endif  // INPUT_H