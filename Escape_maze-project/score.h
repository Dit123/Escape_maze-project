#ifndef SCORE_H
#define SCORE_H

struct Score {
    int points;
};
struct Score initScore();
void updateScore(struct Score *score, int points);
int getScore(struct Score *score);
void displayScore(struct Score *score);

#endif /* SCORE_H */

