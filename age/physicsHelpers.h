#ifndef PHYSICSHELPERS_H
#define PHYSICSHELPERS_H

#include <vector>
#include "body.h"

namespace PhysicsHelpers {

    int towards(int target, int pos);

    void checkOverlaps(Body* a, std::vector<Body*> bodies);

    bool checkBodyCollisionsX(Body* a, std::vector<Body*> bodies, int x);

    bool checkBorderCollisionsX(Body* a, int x);

    bool checkBodyCollisionsY(Body* a, std::vector<Body*> bodies, int y);

    bool checkBorderCollisionsY(Body* a, int y);
    
}

#endif
