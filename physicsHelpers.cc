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

    void checkOverlaps(unique_ptr<Entity> &a, list<unique_ptr<Entity>> &entities) {
        for (auto &b : entities) {
            if (a == b) continue;
            if (b->isOverlapping(*a) && !b->isCollidable(*a)) {
                a->doPassEntity(*b);
                b->doPassEntity(*a);
            }
        }
    }

    bool checkEntityCollisionsX(unique_ptr<Entity> &a, list<unique_ptr<Entity>> &entities, int x) {
        for (auto &b : entities) {
            if (a == b) continue;
            if (b->isOverlapping(*a) && b->isCollidable(*a)) {
                a->setX(x);
                a->doCollideX(*b);
                b->doCollideX(*a);
                return true;
            }
        }
        return false;
    }

    bool checkBorderCollisionsX(unique_ptr<Entity> &a, int x) {
        if (a->isOverlapping(Point{0, 0}, Point{1, Properties::BORDER_HEIGHT})) {
            a->setX(x);
            a->doCollideB(Border::LEFT);
            return true;
        }
        if (a->isOverlapping(Point{Properties::BORDER_WIDTH - 1, 0}, Point{1, Properties::BORDER_HEIGHT})) {
            a->setX(x);
            a->doCollideB(Border::RIGHT);
            return true;
        }
        return false;
    }

    bool checkEntityCollisionsY(unique_ptr<Entity> &a, list<unique_ptr<Entity>> &entities, int y) {
        for (auto &b : entities) {
            if (a == b) continue;
            if (b->isOverlapping(*a) && b->isCollidable(*a)) {
                a->setY(y);
                a->doCollideY(*b);
                b->doCollideY(*a);
                return true;
            }
        }
        return false;
    }

    bool checkBorderCollisionsY(unique_ptr<Entity> &a, int y) {
        if (a->isOverlapping(Point{0, 0}, Point{Properties::BORDER_WIDTH, 1})) {
            a->setY(y);
            a->doCollideB(Border::TOP);
            return true;
        }
        if (a->isOverlapping(Point{0, Properties::BORDER_HEIGHT - 1}, Point{Properties::BORDER_WIDTH, 1})) {
            a->setY(y);
            a->doCollideB(Border::BOTTOM);
            return true;
        }
        return false;
    }
}
