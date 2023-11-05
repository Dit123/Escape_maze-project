#ifndef AUDIO_MANAGER_H
#define AUDIO_MANAGER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

// Function to initialize the audio manager
int AudioManager_Init();

// Function to load and play background music
Mix_Music* AudioManager_LoadBackgroundMusic(const char* filename);
void AudioManager_PlayBackgroundMusic(Mix_Music* music, int loops);

// Function to load and play sound effects
Mix_Chunk* AudioManager_LoadSoundEffect(const char* filename);
void AudioManager_PlaySoundEffect(Mix_Chunk* chunk, int channel, int loops);

// Function to pause audio playback
void AudioManager_PauseAudio();

// Function to resume audio playback
void AudioManager_ResumeAudio();

// Function to halt audio playback
void AudioManager_HaltAudio();

// Function to free loaded audio resources
void AudioManager_FreeMusic(Mix_Music* music);
void AudioManager_FreeSoundEffect(Mix_Chunk* chunk);

// Function to close the audio manager
void AudioManager_Close();

#endif // AUDIO_MANAGER_H

