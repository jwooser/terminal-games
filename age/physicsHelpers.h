#ifndef PHYSICSHELPERS_H
#define PHYSICSHELPERS_H

#include <vector>
#include "body.h"

namespace PhysicsHelpers {
    using std::list;
    using std::unique_ptr;

    int towards(int target, int pos);

    void checkOverlaps(Body* a, std::vector<Body*> bodies);

    bool checkEntityCollisionsX(Body* a, std::vector<Body*> bodies, int x);

    bool checkBorderCollisionsX(Body* a, int x);

    bool checkEntityCollisionsY(Body* a, std::vector<Body*> bodies, int y);

    bool checkBorderCollisionsY(Body* a, int y);
    
}

#endif
