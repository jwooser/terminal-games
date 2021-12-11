#ifndef VIEWPHYSICS_H
#define VIEWPHYSICS_H

#include "physics.h"
#include <map>
#include <list>
#include <memory>
#include "entity.h"

class ViewPhysics : public Physics {
  public:
    void step(map<int,list<unique_ptr<Entity>>> &entities) override;
};

#endif
