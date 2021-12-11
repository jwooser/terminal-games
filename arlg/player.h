#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include "health.h"
#include <vector>
#include "border.h"
#include "game.h"
#include "point.h"

class Player : public Entity, public Health {

    static const std::vector<Point> bulletDirection;
    size_t cooldown = 0;
    void shoot(size_t dir);

    void initialize(Game &game) override;
    void process(Game &game) override;
    void collideX(Entity *other);
    void collideY(Entity *other) override;
    void collideB(Border b) override;
    void passEntity(Entity *other) override;
};

#endif
