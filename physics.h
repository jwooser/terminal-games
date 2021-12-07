#ifndef PHYSICS_H
#define PHYSICS_H

#include <map>
#include <list>
#include <memory>
#include "entity.h"

using std::map;
using std::list;
using std::unique_ptr;

class Physics {
  public:
    virtual ~Physics() = default;
    virtual void step(map<int,list<unique_ptr<Entity>>> &entities) = 0;
};

#endif
