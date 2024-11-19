#include "timer.h"
#include <sys/time.h>
#include <stdio.h>

static struct timeval timer, now;
static int delay = -1;

void timerInit(int valueMilliSec) {
    delay = valueMilliSec;
    gettimeofday(&timer, NULL);
}

void timerDestroy() {
    delay = -1;
}

int timerTimeOver() {
    gettimeofday(&now, NULL);
    long diff = (((now.tv_sec - timer.tv_sec) * 1000000) + now.tv_usec - timer.tv_usec) / 1000;
    if (diff >= delay) {
        gettimeofday(&timer, NULL);
        return 1;
    }
    return 0;
}
