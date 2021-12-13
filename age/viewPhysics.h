#ifndef VIEWPHYSICS_H
#define VIEWPHYSICS_H

#include "physics.h"
#include "body.h"

class ViewPhysics : public Physics {
  public:
    void step(std::vector<Body*> bodies) override;
};

#endif
