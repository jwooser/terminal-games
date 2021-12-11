#ifndef WALKER_H
#define WALKER_H

#include "entity.h"
#include <vector>
#include "health.h"
#include "border.h"
#include "game.h"
#include "point.h"

class Walker : public Entity, public Health {
    static const std::vector<Point> walkDirection;
    int walkTime = 7;
    void changeDirection();

    void initialize(Game &game) override;
    void process(Game &game) override;
    void collideX(Entity *other);
    void collideY(Entity *other) override;
    void collideB(Border b) override;
    void passEntity(Entity *other) override;

};

#endif

