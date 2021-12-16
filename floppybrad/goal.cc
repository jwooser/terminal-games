#include "goal.h"
#include <memory>

void Goal::initialize(Game &game) {
    setBounds(Point{1, 7});
    setVelocity(-2, 0);
}

void Goal::process(Game &game) { }

void Goal::collideX(Entity *other) { }

void Goal::collideY(Entity *other) { }

void Goal::collide(Border b) { }

void Goal::pass(Entity *other) { }
