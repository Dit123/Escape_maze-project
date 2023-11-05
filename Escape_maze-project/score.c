#include "score.h"

// Initialize a score object
struct Score initScore() {
    struct Score score;
    score.points = 0;
    return score;
}

// Update the player's score
void updateScore(struct Score *score, int points) {
    score->points += points;
}

// Get the player's current score
int getScore(struct Score *score) {
    return score->points;
}

// Display the player's score
void displayScore(struct Score *score) {
    printf("Score: %d\n", score->points);
}

