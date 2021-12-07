#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "entity.h"
#include <vector>
#include "border.h"
#include "game.h"

class Projectile : public Entity {

    void initialize(Game &game) override;
    void process(Game &game) override;
    void collideX(Entity *other);
    void collideY(Entity *other) override;
    void collideB(Border b) override;
    void passEntity(Entity *other) override;

};

#endif
