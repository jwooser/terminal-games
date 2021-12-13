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

    void checkOverlaps(Body* a, std::vector<Body*> bodies) {
        for (auto &b : bodies) {
            if (a == b) continue;
            if (b->isOverlapping(*a) && !b->isCollidable(*a)) {
                a->doPass(b);
                b->doPass(a);
            }
        }
    }

    bool checkBodyCollisionsX(Body* a, std::vector<Body*> bodies, int x) {
        for (auto &b : bodies) {
            if (a == b) continue;
            if (b->isOverlapping(*a) && b->isCollidable(*a)) {
                a->setX(x);
                a->doCollideX(b);
                b->doCollideX(a);
                return true;
            }
        }
        return false;
    }

    bool checkBorderCollisionsX(Body* a, int x) {
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

    bool checkBodyCollisionsY(Body* a, std::vector<Body*> bodies, int y) {
        for (auto &b : bodies) {
            if (a == b) continue;
            if (b->isOverlapping(*a) && b->isCollidable(*a)) {
                a->setY(y);
                a->doCollideY(b);
                b->doCollideY(a);
                return true;
            }
        }
        return false;
    }

    bool checkBorderCollisionsY(Body* a, int y) {
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
