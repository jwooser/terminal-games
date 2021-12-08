#ifndef HEALTHPICKUP_H
#define HEALTHPICKUP_H

#include "entity.h"
#include "border.h"
#include "game.h"
#include "point.h"

class HealthPickup : public Entity {

    void initialize(Game &game) override;
    void process(Game &game) override;
    void collideX(Entity *other);
    void collideY(Entity *other) override;
    void collideB(Border b) override;
    void passEntity(Entity *other) override;

};

#endif
