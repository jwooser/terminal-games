#ifndef POPUP_H
#define POPUP_H

#include "entity.h"
#include <vector>
#include "health.h"
#include "border.h"
#include "game.h"
#include "point.h"

class Popup : public Entity, public Health {

    static const std::vector<Point> bulletDirection;
    bool invulState = true;
    size_t invulnTime = 6;
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
