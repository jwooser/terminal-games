#include "halfSecondClock.h"

HalfSecondClock::HalfSecondClock():
time {clock()}
{ }

bool HalfSecondClock::tick() {
    clock_t currtime = clock();
    clock_t duration = currtime - time;
    if (0.5 <= ((float)duration) / CLOCKS_PER_SEC) {
        time = currtime;
        return true;
    } else return false;
}
