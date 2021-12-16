#ifndef GOAL_H
#define GOAL_H

#include "entity.h"
#include "border.h"
#include "game.h"
#include "point.h"

class Goal : public Entity {

    void initialize(Game &game) override;
    void process(Game &game) override;
    void collideX(Entity *other);
    void collideY(Entity *other) override;
    void collide(Border b) override;
    void pass(Entity *other) override;

};

#endif
