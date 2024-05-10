#include "timer.h"

Timer::Timer() {
    time = 0;
    running = false;
}

void Timer::startTimer() {
    running = true;
    startTime = steady_clock::now();

    while(running) {
        sleep_for(seconds(1));
        ++time;
    }
}

void Timer::stopTimer() {
    running = false;
}

int Timer::getTime() const {
    return time;
}


/*what to do for main to create and timer

Timer timer;
thread timerThread(&Timer::startTimer, &timer);
timerThread.detach();

this starts the timer whenever the object is created, so when the game starts.

 */