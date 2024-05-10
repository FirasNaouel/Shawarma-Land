#include <iostream>
#include <chrono>
#include <thread>
#include <string>

using namespace std;
using namespace chrono;
using namespace this_thread;


class Timer {
private:
    int time;
    bool running;
    time_point<steady_clock> startTime;

public:
    Timer();

    void startTimer();


    void stopTimer();

    int getTime() const;
};