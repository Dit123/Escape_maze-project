#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

int Renderer_Init(const char* title, int width, int height);
SDL_Texture* Renderer_LoadTexture(const char* filename);
void Renderer_Clear();
void Renderer_DrawTexture(SDL_Texture* texture, int x, int y);
void Renderer_DrawText(SDL_Renderer* renderer, const char* text, int x, int y);
void Renderer_Render();
void Renderer_Close();
int Renderer_InitFont(const char* fontFile, int fontSize);

#endif
