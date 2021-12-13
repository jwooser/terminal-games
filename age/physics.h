#ifndef PHYSICS_H
#define PHYSICS_H

#include <vector>
#include "body.h"

class Physics {
  public:
    virtual ~Physics() = default;
    virtual void step(std::vector<Body*> bodies) = 0;
};

#endif
