#ifndef FIRE_H
#define FIRE_H

#include "entity.h"
#include "health.h"
#include "border.h"
#include "game.h"
#include "point.h"

class Fire : public Entity, public Health {

    void initialize(Game &game) override;
    void process(Game &game) override;
    void collideX(Entity *other);
    void collideY(Entity *other) override;
    void collide(Border b) override;
    void pass(Entity *other) override;

};

#endif
