#ifndef ENEMYPROJ_H
#define ENEMYPROJ_H

#include "entity.h"
#include <vector>
#include "border.h"
#include "game.h"

class EnemyProjectile : public Entity {

    void tryToHit(Entity *other);

    void initialize(Game &game) override;
    void process(Game &game) override;
    void collideX(Entity *other);
    void collideY(Entity *other) override;
    void collideB(Border b) override;
    void passEntity(Entity *other) override;

};

#endif