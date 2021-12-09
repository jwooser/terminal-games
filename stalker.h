#ifndef STALKER_H
#define STALKER_H

#include "entity.h"
#include <vector>
#include "health.h"
#include "border.h"
#include "game.h"
#include "point.h"
#include "player.h"

class Stalker : public Entity, public Health {
    static const std::vector<Point> walkDirection;
    Player *player = nullptr;
    void moveTowardsPlayer();

    void initialize(Game &game) override;
    void process(Game &game) override;
    void collideX(Entity *other);
    void collideY(Entity *other) override;
    void collideB(Border b) override;
    void passEntity(Entity *other) override;

  public:
    void trackPlayer(Player *p);
};

#endif
