#ifndef COLLISION_H
#define COLLISION_H

#include <SDL2/SDL.h>

// Declare the function to check collision
int Collision_CheckCollision(const SDL_Rect* rectA, const SDL_Rect* rectB);

#endif