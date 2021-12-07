#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include <vector>
#include "border.h"
#include "game.h"
#include "point.h"

class Player : public Entity {

    static const std::vector<Point> bulletDirection;
    void shoot(size_t dir);
    int cooldown = 0;

    void initialize(Game &game) override;
    void process(Game &game) override;
    void collideX(Entity *other);
    void collideY(Entity *other) override;
    void collideB(Border b) override;
    void passEntity(Entity *other) override;
};

#endif
