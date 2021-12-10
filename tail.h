#ifndef TAIL_H
#define TAIL_H

#include "entity.h"
#include "health.h"
#include "border.h"
#include "game.h"
#include "point.h"
#include "snake.h"

class Tail : public Entity {
    Snake *head;

    void initialize(Game &game) override;
    void process(Game &game) override;
    void collideX(Entity *other);
    void collideY(Entity *other) override;
    void collideB(Border b) override;
    void passEntity(Entity *other) override;

  public:
    void setHead(Snake *h);
    void hit();
};

#endif

