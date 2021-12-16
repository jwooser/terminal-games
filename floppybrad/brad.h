#ifndef BRAD_H
#define BRAD_H

#include "entity.h"
#include <vector>
#include "border.h"
#include "game.h"
#include "point.h"

class Brad : public Entity {
	
	size_t score = 0;

    void initialize(Game &game) override;
    void process(Game &game) override;
    void collideX(Entity *other);
    void collideY(Entity *other) override;
    void collide(Border b) override;
    void pass(Entity *other) override;

  public:
	size_t getScore();
};

#endif
