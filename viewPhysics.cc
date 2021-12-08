#include "viewPhysics.h"
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
            if (a->isPlayerControlled() && checkBorderCollisionsX(a, x)) return;
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
            if (a->isPlayerControlled() && checkBorderCollisionsY(a, y)) return;
            checkOverlaps(a, entities);
            y += dir;
        }
    }
    
    void stepHeight(list<unique_ptr<Entity>> &entities) {
        for (auto &a : entities) {
            checkOverlaps(a, entities);
            Point target = a->getPosition() + a->getVelocity();
            moveX(target.x, a, entities);
            moveY(target.y, a, entities);
        }
    }
}

void ViewPhysics::step(map<int,list<unique_ptr<Entity>>> &entities) {
    for (auto &a : entities) {
        stepHeight(a.second);
    }
}
