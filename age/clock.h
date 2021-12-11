#ifndef CLOCK_H
#define CLOCK_H

class Clock {
  public:
    virtual bool tick() = 0;
	virtual ~Clock() = default;
};

#endif
