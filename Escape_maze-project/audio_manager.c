#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>  // Include SDL2_mixer for audio

// Initialize SDL2's audio system
if (SDL_Init(SDL_INIT_AUDIO) < 0) {
    printf("SDL couldn't be initialized: %s\n", SDL_GetError());
    // Handle the error appropriately
} else {
    // Initialize SDL2_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("SDL_mixer couldn't be initialized: %s\n", Mix_GetError());
        // Handle the error appropriately
    }
}

// Load background music
Mix_Music *backgroundMusic = Mix_LoadMUS("background_music.mp3");
if (!backgroundMusic) {
    printf("Failed to load background music: %s\n", Mix_GetError());
    // Handle the error appropriately
} else {
    // Play background music indefinitely (-1)
    Mix_PlayMusic(backgroundMusic, -1);
}

// Load a sound effect
Mix_Chunk *soundEffect = Mix_LoadWAV("explosion.wav");
if (!soundEffect) {
    printf("Failed to load sound effect: %s\n", Mix_GetError());
    // Handle the error appropriately
} else {
    // Play the sound effect on channel -1 (auto-assign)
    Mix_PlayChannel(-1, soundEffect, 0);
}

// Wait for a moment to hear the audio (e.g., use SDL_Delay)
SDL_Delay(5000);  // 5 seconds

// Free loaded audio resources
Mix_FreeMusic(backgroundMusic);
Mix_FreeChunk(soundEffect);

// Close SDL2's audio system
Mix_CloseAudio();

// Quit SDL
SDL_Quit();

