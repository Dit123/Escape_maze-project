#ifndef TIMER_H
#define TIMER_H

struct Timer {
    int gameTime;
};
struct Timer initTimer();
void updateTimer(struct Timer *timer);
int getGameTime(struct Timer *timer);

#endif

