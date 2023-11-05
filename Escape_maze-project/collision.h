#ifndef COLLISION_H
#define COLLISION_H

#include <SDL2/SDL.h>

// Define a structure for representing rectangular objects
typedef struct {
    int x;
    int y;
    int width;
    int height;
} Rect;

// Check for collision between two rectangular objects
int Collision_CheckCollision(const Rect* rectA, const Rect* rectB);

#endif // COLLISION_H

