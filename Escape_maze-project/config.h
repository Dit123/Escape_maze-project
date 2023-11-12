#ifndef CONFIG_H
#define CONFIG_H

// Define the Config struct
typedef struct {
    int screenWidth;
    int screenHeight;
    int soundEnabled;
} Config;

// Function prototypes for loading and saving configuration
int LoadConfig(const char* filename);
int SaveConfig(const char* filename);

#endif // CONFIG_H

