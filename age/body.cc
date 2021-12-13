#include "body.h"
#include "properties.h"

void Body::doCollideX(Body *other) {
    if (seen.count(other) == 0) {
        collideX(static_cast<Entity*>other);
        seen.insert(other);
    }
}

void Body::doCollideY(Body *other) {
    if (seen.count(other) == 0) {
        collideY(static_cast<Entity*>other);
        seen.insert(other);
    }
}

void Body::doCollide(Border border) {
	collide(border);
}

void Body::doPass(Body *other) {
    if (seen.count(other) == 0) {
        passBody(static_cast<Entity*>other);
        seen.insert(other);
    }
}

void Body::queueDestroy() { destroy = true; }

bool Body::isFlaggedDestroy() { return destroy; }

// ********************************************************************************
// POSITION METHODS
// ********************************************************************************

void Body::setPosition(Point p) {
    position = p;
}

void Body::setPosition(int x, int y) {
    position.x = x;
    position.y = y;
}

void Body::setX(int x) {
    position.x = x;
}

void Body::setY(int y) {
    position.y = y;
}

Point Body::getPosition() const {
    return position;
}

bool Body::isOutsideBorder() const {
    if (position.x >= Properties::BORDER_WIDTH) return true;
    if (position.y >= Properties::BORDER_HEIGHT) return true;
    if (position.x + bounds.x <= 0) return true;
    if (position.y + bounds.y <= 0) return true;
    return false;
}

// ********************************************************************************
// BOUNDS/COLLISION METHODS
// ********************************************************************************

void Body::setBounds(Point b) { bounds = b; }

Point Body::getBounds() const { return bounds; }

bool Body::isOverlapping(const Body &other) const {
    if (destroy || other.destroy) return false;
    Point top1 = position;
    Point top2 = other.getPosition();
    Point bot1 = top1 + bounds;
    Point bot2 = top2 + other.getBounds();
    if (top1.x >= bot2.x || top2.x >= bot1.x) return false;
    if (bot1.y <= top2.y || bot2.y <= top1.y) return false;
    return true;
}

bool Body::isOverlapping(Point other_p, Point other_b) const {
    Point top1 = position;
    Point top2 = other_p;
    Point bot1 = top1 + bounds;
    Point bot2 = top2 + other_b;
    if (top1.x >= bot2.x || top2.x >= bot1.x) return false;
    if (bot1.y <= top2.y || bot2.y <= top1.y) return false;
    return true;
}

void Body::setCollisionLayer(unsigned int cl) { layer = cl; }

void Body::setCollisionMask(unsigned int cm) { mask = cm; }

bool Body::isCollidable(const Body &other) const {
    if (destroy || other.destroy) return false;
    unsigned int mask;
    mask = collisionMask & other.collisionLayer;
    if (mask != 0) return true;
    mask = other.collisionMask & collisionLayer;
    if (mask != 0) return true;
    return false;
}

// ********************************************************************************
// VELOCITY/MOVEMENT METHODS
// ********************************************************************************

void Body::setVelocity(Point v) { velocity = v; }

void Body::setVelocity(int vx, int vy) {
    velocity.x = vx;
    velocity.y = vy;
}

void Body::reflectVelocityX() { velocity.x *= -1; }

void Body::reflectVelocityY() { velocity.y *= -1; }

Point Body::getVelocity() const { return velocity; }

void Body::doPush(Point v) { push = v; }

void Body::doPush(int vx, int vy) { push = Point{vx, vy}; }

void Body::setAction(Action a, Point v) { controls[a] = v; }

bool Body::isPlayerControlled() const { return !controls.empty(); }

void Body::setGravitation(Border b) {
    if (b == Border::NONE) {
        gravity = Point{0, 0};
    } else if (b == Border::TOP) {
        gravity = Point{0, -1};
    } else if (b == Border::BOTTOM) {
        gravity = Point{0, 1};
    } else if (b == Border::LEFT) {
        gravity = Point{-1, 0};
    } else if (b == Border::RIGHT) {
        gravity = Point{1, 0};
    }
}

Point Body::getTotalVelocity() const { return totalV; }

Point Body::recalibrate(Action input) {
    seen.clear();
	auto a = controls.find(input);
	Point control {0, 0};
	if (a != actions.end()) {
		control = a->second;
	}
    totalV = velocity + control + gravity + push;
    push = {0, 0};
}
