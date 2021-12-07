#ifndef PHYSICSHELPERS_H
#define PHYSICSHELPERS_H

#include <map>
#include <list>
#include <memory>
#include "entity.h"

namespace PhysicsHelpers {
    using std::list;
    using std::unique_ptr;

    int towards(int target, int pos);

    void checkOverlaps(unique_ptr<Entity> &a, list<unique_ptr<Entity>> &entities);

    bool checkEntityCollisionsX(unique_ptr<Entity> &a, list<unique_ptr<Entity>> &entities, int x);

    bool checkBorderCollisionsX(unique_ptr<Entity> &a, int x);

    bool checkEntityCollisionsY(unique_ptr<Entity> &a, list<unique_ptr<Entity>> &entities, int y);

    bool checkBorderCollisionsY(unique_ptr<Entity> &a, int y);
    
}

#endif
