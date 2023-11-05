#ifndef CONFIG_H
#define CONFIG_H

typedef struct {
    int screenWidth;
    int screenHeight;
    int soundEnabled;
} Config;

extern Config gameConfig;

int LoadConfig(const char* filename);
int SaveConfig(const char* filename);

#endif

