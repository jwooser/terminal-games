#ifndef HALFSECONDCLOCK_H
#define HALFSECONDCLOCK_H

#include <ctime>
#include "clock.h"

class HalfSecondClock : public Clock {
    clock_t time;

  public:
    HalfSecondClock();
    bool tick() override;
};

#endif
