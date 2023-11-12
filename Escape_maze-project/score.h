#ifndef SCORE_H
#define SCORE_H

typedef struct {
    int points;
} Score;

Score initScore();
void displayScore(Score *score);
void updateScore(Score *score, int points);
int getScore(Score *score);

#endif /* SCORE_H */
