#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>

// Initialize the graphics system
int Renderer_Init(const char* title, int width, int height);

// Load a texture from an image file
SDL_Texture* Renderer_LoadTexture(const char* filename);

// Clear the screen
void Renderer_Clear();

// Draw a texture on the screen
void Renderer_DrawTexture(SDL_Texture* texture, int x, int y);

// Update the screen
void Renderer_Render();

// Clean up and close the graphics system
void Renderer_Close();

#endif // RENDERER_H

