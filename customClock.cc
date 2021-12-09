#include "customClock.h"

CustomClock::CustomClock(float freq):
time {clock()},
freq {freq}
{ }

bool CustomClock::tick() {
    clock_t currtime = clock();
    clock_t duration = currtime - time;
    if (freq <= ((float)duration) / CLOCKS_PER_SEC) {
        time = currtime;
        return true;
    } else return false;
}

