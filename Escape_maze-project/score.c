#include <stdio.h>
#include "score.h"

// Initialize a score object
Score initScore() {
    Score score;
    score.points = 0;
    return score;
}

// Update the player's score
void updateScore(Score *score, int points) {
    score->points += points;
}

// Get the player's current score
int getScore(Score *score) {
    return score->points;
}

// Display the player's score
void displayScore(Score *score) {
    printf("Score: %d\n", score->points);
}

// Main function
int scoreGame() {
    // Create a Score object and initialize it
    Score myScore = initScore();

    // Display the initial score
    displayScore(&myScore);

    // Update the score
    updateScore(&myScore, 10);

    // Display the updated score
    displayScore(&myScore);
    
    return 0;
}

