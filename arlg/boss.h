#ifndef BOSS_H
#define BOSS_H

#include "entity.h"
#include <vector>
#include "health.h"
#include "border.h"
#include "game.h"
#include "point.h"

class Boss : public Entity, public Health {
	
	bool rage = false;

    void initialize(Game &game) override;
    void process(Game &game) override;
    void collideX(Entity *other);
    void collideY(Entity *other) override;
    void collide(Border b) override;
    void pass(Entity *other) override;

};

#endif
