#ifndef SNAKE_H
#define SNAKE_H

#include "entity.h"
#include <vector>
#include "health.h"
#include "border.h"
#include "game.h"
#include "point.h"

class Tail;

class Snake : public Entity, public Health {
    static const std::vector<Point> slitherDirection;
    vector<Tail*> tail;
    void makeTail();

    void initialize(Game &game) override;
    void process(Game &game) override;
    void collideX(Entity *other);
    void collideY(Entity *other) override;
    void collide(Border b) override;
    void pass(Entity *other) override;

};

#endif
