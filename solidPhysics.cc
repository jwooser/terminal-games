#include "solidPhysics.h"
#include "physicsHelpers.h"
#include "point.h"

namespace {

    using namespace PhysicsHelpers;

    void moveX(int tx, unique_ptr<Entity> &a, list<unique_ptr<Entity>> &entities) {
        int x = a->getPosition().x;
		int dir = towards(tx, x);
        while (tx != x) {
            a->setX(x + dir);
            if (checkEntityCollisionsX(a, entities, x)) return;
            if (checkBorderCollisionsX(a, x)) return;
            checkOverlaps(a, entities);
            x += dir;
        }
    }

    void moveY(int ty, unique_ptr<Entity> &a, list<unique_ptr<Entity>> &entities) {
        int y = a->getPosition().y;
		int dir = towards(ty, y);
        while (ty != y) {
            a->setY(y + dir);
            if (checkEntityCollisionsY(a, entities, y)) return;
            if (checkBorderCollisionsY(a, y)) return;
            checkOverlaps(a, entities);
            y += dir;
        }
    }
    
    void stepHeight(list<unique_ptr<Entity>> &entities) {
        for (auto &a : entities) {
            Point target = a->getPosition() + a->getTotalVelocity();
            checkOverlaps(a, entities);
            moveX(target.x, a, entities);
            moveY(target.y, a, entities);
        }
    }
}

void SolidPhysics::step(map<int,list<unique_ptr<Entity>>> &entities) {
    for (auto &a : entities) {
        stepHeight(a.second);
    }
}

