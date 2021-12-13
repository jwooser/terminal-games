#include "viewPhysics.h"
#include "physicsHelpers.h"
#include "point.h"

namespace {

    using namespace PhysicsHelpers;

    void moveX(int tx, Body* a, std::vector<Body*> bodies) {
        int x = a->getPosition().x;
		int dir = towards(tx, x);
        while (tx != x) {
            a->setX(x + dir);
            if (checkBodyCollisionsX(a, bodies, x)) return;
            if (a->isPlayerControlled() && checkBorderCollisionsX(a, x)) return;
            checkOverlaps(a, bodies);
            x += dir;
        }
    }

    void moveY(int ty, Body* a, std::vector<Body*> bodies) {
        int y = a->getPosition().y;
		int dir = towards(ty, y);
        while (ty != y) {
            a->setY(y + dir);
            if (checkBodyCollisionsY(a, bodies, y)) return;
            if (a->isPlayerControlled() && checkBorderCollisionsY(a, y)) return;
            checkOverlaps(a, bodies);
            y += dir;
        }
    }
}

void ViewPhysics::step(std::vector<Body*> bodies) {
    for (auto &a : bodies) {
        Point target = a->getPosition() + a->getTotalVelocity();
        checkOverlaps(a, bodies);
        moveX(target.x, a, bodies);
        moveY(target.y, a, bodies);
    }
}
