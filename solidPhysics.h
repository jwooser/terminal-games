#ifndef SOLIDPHYSICS_H
#define SOLIDPHYSICS_H

#include "physics.h"
#include <map>
#include <list>
#include <memory>
#include "entity.h"

class SolidPhysics : public Physics {
  public:
    void step(map<int,list<unique_ptr<Entity>>> &entities) override;
};

#endif
