#include "physicsHelpers.h"
#include "point.h"
#include "border.h"
#include "properties.h"

namespace PhysicsHelpers {
    
    int towards(int target, int pos) {
        if (target > pos) return 1;
        if (target < pos) return -1;
		return 0;
    }

    void checkStationaryOverlaps(unique_ptr<Entity> &a, list<unique_ptr<Entity>> &entities) {
        for (auto &b : entities) {
            if (a == b) continue;
            if (b->isOverlapping(*a) && !b->isCollidable(*a)) {
                a->doPass(b.get());
            }
        }
    }

    void checkOverlaps(unique_ptr<Entity> &a, list<unique_ptr<Entity>> &entities) {
        for (auto &b : entities) {
            if (a == b) continue;
            if (b->isOverlapping(*a) && !b->isCollidable(*a)) {
                a->doPass(b.get());
                b->doPass(a.get());
            }
        }
    }

    bool checkEntityCollisionsX(unique_ptr<Entity> &a, list<unique_ptr<Entity>> &entities, int x) {
        for (auto &b : entities) {
            if (a == b) continue;
            if (b->isOverlapping(*a) && b->isCollidable(*a)) {
                a->setX(x);
                a->doCollideX(b.get());
                b->doCollideX(a.get());
                return true;
            }
        }
        return false;
    }

    bool checkBorderCollisionsX(unique_ptr<Entity> &a, int x) {
        if (a->isOverlapping(Point{0, 0}, Point{1, Properties::BORDER_HEIGHT})) {
            a->setX(x);
            a->doCollide(Border::LEFT);
            return true;
        }
        if (a->isOverlapping(Point{Properties::BORDER_WIDTH - 1, 0}, Point{1, Properties::BORDER_HEIGHT})) {
            a->setX(x);
            a->doCollide(Border::RIGHT);
            return true;
        }
        return false;
    }

    bool checkEntityCollisionsY(unique_ptr<Entity> &a, list<unique_ptr<Entity>> &entities, int y) {
        for (auto &b : entities) {
            if (a == b) continue;
            if (b->isOverlapping(*a) && b->isCollidable(*a)) {
                a->setY(y);
                a->doCollideY(b.get());
                b->doCollideY(a.get());
                return true;
            }
        }
        return false;
    }

    bool checkBorderCollisionsY(unique_ptr<Entity> &a, int y) {
        if (a->isOverlapping(Point{0, 0}, Point{Properties::BORDER_WIDTH, 1})) {
            a->setY(y);
            a->doCollide(Border::TOP);
            return true;
        }
        if (a->isOverlapping(Point{0, Properties::BORDER_HEIGHT - 1}, Point{Properties::BORDER_WIDTH, 1})) {
            a->setY(y);
            a->doCollide(Border::BOTTOM);
            return true;
        }
        return false;
    }
}
