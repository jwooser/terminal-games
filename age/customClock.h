#ifndef CUSTOMCLOCK_H
#define CUSTOMCLOCK_H

#include <ctime>
#include "clock.h"

class CustomClock : public Clock {
    clock_t time;
    float freq;

  public:
    CustomClock(float freq);
    bool tick() override;
};

#endif

