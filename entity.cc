#include "entity.h"
#include <utility>
#include "game.h"
#include "properties.h"

const Bitmap Entity::noSprite = Bitmap{};

const map<Border,Point> Entity::gravity = {
    {Border::NONE, Point {0, 0}},
    {Border::TOP, Point {0, -1}},
    {Border::BOTTOM, Point {0, 1}},
    {Border::LEFT, Point {-1, 0}},
    {Border::RIGHT, Point {1, 0}}
};

void Entity::doInitialize(Game &game) {
    initialize(game);
}

void Entity::doProcess(Game &game) {
    input = game.getInput();
    seen.clear();
    process(game);
    if(isOutsideBorder()) ++ticksOutsideBorder;
    else ticksOutsideBorder = 0;
    if(ticksOutsideBorder >= 5) queueDestroy();
}

void Entity::doCollideX(Entity *other) {
    if (seen.count(other) == 0) {
        collideX(other);
        seen.insert(other);
    }
}

void Entity::doCollideY(Entity *other) {
    if (seen.count(other) == 0) {
        collideY(other);
        seen.insert(other);
    }
}

void Entity::doCollideB(Border border) {
	collideB(border);
}

void Entity::doPassEntity(Entity *other) {
    if (seen.count(other) == 0) {
        passEntity(other);
        seen.insert(other);
    }
}

// ********************************************************************************
// DESTROY/SPAWN METHODS
// ********************************************************************************

void Entity::queueDestroy() { destroy = true; }

bool Entity::isTaggedDestroy() const { return destroy; }

queue<unique_ptr<Entity>> &Entity::getSpawns() { return spawns; }

// ********************************************************************************
// POSITION METHODS
// ********************************************************************************

void Entity::setPosition(Point p) {
    position = p;
}

void Entity::setPosition(int x, int y) {
    position.x = x;
    position.y = y;
}

void Entity::setX(int x) {
    position.x = x;
}

void Entity::setY(int y) {
    position.y = y;
}

Point Entity::getPosition() const {
    return position;
}

bool Entity::isOutsideBorder() const {
    if (position.x >= Properties::BORDER_WIDTH) return true;
    if (position.y >= Properties::BORDER_HEIGHT) return true;
    if (position.x + bounds.x <= 0) return true;
    if (position.y + bounds.y <= 0) return true;
    return false;
}

// ********************************************************************************
// SPRITE/GRAPHICS METHODS
// ********************************************************************************

void Entity::nextForm() {
    ++currForm;
    if (currForm >= forms.size()) {
        currForm = 0;
    }
}

void Entity::setForm(size_t form) {
    if (form < forms.size()) currForm = form;
}

size_t Entity::addSprite(unique_ptr<Sprite> sprite) {
    size_t form = forms.size();
    forms.push_back(std::move(sprite));
    return form;
}

const Bitmap &Entity::getSpriteFrame() const {
    if (forms.size() == 0) return noSprite;
    return forms[currForm]->getFrame();
}

void Entity::setSpriteOffset(size_t form, Point o) {
    forms[form]->setOffset(o);
}

Point Entity::getSpriteOffset() const {
	return forms[currForm]->getOffset();
}

// ********************************************************************************
// BOUNDS/COLLISION METHODS
// ********************************************************************************

    void Entity::setBounds(Point b) {
        bounds = b;
    }

    Point Entity::getBounds() const {
        return bounds;
    }

    bool Entity::isOverlapping(const Entity &other) const {
        Point top1 = position;
        Point top2 = other.getPosition();
        Point bot1 = top1 + bounds;
        Point bot2 = top2 + other.getBounds();
        if (top1.x >= bot2.x || top2.x >= bot1.x) return false;
        if (bot1.y <= top2.y || bot2.y <= top1.y) return false;
        return true;
    }

    bool Entity::isOverlapping(Point other_p, Point other_b) const {
        Point top1 = position;
        Point top2 = other_p;
        Point bot1 = top1 + bounds;
        Point bot2 = top2 + other_b;
        if (top1.x >= bot2.x || top2.x >= bot1.x) return false;
        if (bot1.y <= top2.y || bot2.y <= top1.y) return false;
        return true;
    }

    void Entity::setCollisionLayer(unsigned int cl) {
        collisionLayer = cl;
    }

    void Entity::setCollisionMask(unsigned int cm) {
        collisionMask = cm;
    }

    bool Entity::isCollidable(const Entity &other) const {
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

void Entity::setVelocity(Point v) {
    velocity = v;
}

void Entity::setVelocity(int vx, int vy) {
    velocity.x = vx;
    velocity.y = vy;
}

void Entity::reflectVelocityX() {
    velocity.x *= -1;
}

void Entity::reflectVelocityY() {
    velocity.y *= -1;
}

Point Entity::getVelocity() const {
	auto a = actions.find(input);
	Point control {0, 0};
	if (a != actions.end()) {
		control = a->second;
	}
    return velocity + control + gravity.at(gravitation);
}

void Entity::setAction(Action a, Point v) {
    actions[a] = v;
}

bool Entity::isPlayerControlled() const {
    return !actions.empty();
}

void Entity::setGravitation(Border b) {
    gravitation = b;
}
