#include <stdio.h>
#include "timer.h"

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

int timerGame() {
    // Create a Timer object and initialize it
    struct Timer myTimer = initTimer();

    // Display the initial game time
    printf("Initial Game Time: %d seconds\n", getGameTime(&myTimer));

    // Update the game time (simulate being in a game loop)
    for (int i = 0; i < 5; i++) {
        updateTimer(&myTimer);
        printf("Updated Game Time: %d seconds\n", getGameTime(&myTimer));
    }

    return 0;
}
