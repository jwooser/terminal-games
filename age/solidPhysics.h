#ifndef SOLIDPHYSICS_H
#define SOLIDPHYSICS_H

#include "physics.h"
#include "body.h"

class SolidPhysics : public Physics {
  public:
    void step(std::vector<Body*> bodies) override;
};

#endif
