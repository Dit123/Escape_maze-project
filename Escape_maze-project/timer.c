#include "timer.h"

struct Timer {
    int gameTime;  // Game time in seconds
};

// Initialize a timer
struct Timer initTimer() {
    struct Timer timer;
    timer.gameTime = 0;  // Initialize game time to zero
    return timer;
}

// Update the game time (e.g., call this function in your game loop)
void updateTimer(struct Timer *timer) {
    timer->gameTime++;  // Increment game time by one second
}

// Get the current game time
int getGameTime(struct Timer *timer) {
    return timer->gameTime;
}

