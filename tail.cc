#include "tail.h"
#include <cstdlib>
#include "staticSprite.h"
#include "point.h"

void Snake::setHead(Snake *h) { head = h; }

void Snake::initialize(Game &game) {
    addSprite(std::make_unique<StaticSprite>(Bitmap{'Z'}));
    setBounds(Point{1,1});
    setCollisionLayer(0b0000000000000100);
}

void Snake::hit() {
    head->toggleinvuln(false);
    head->hit();
    head->toggleinvuln(true);
}

void Snake::process(Game &game) { }

void Snake::collideX(Entity *other) { }

void Snake::collideY(Entity *other) { }

void Snake::collideB(Border b) { 
    if (b == Border::TOP || b == Border::BOTTOM) {
        reflectVelocityY();
    } else reflectVelocityX();
}

void Snake::passEntity(Entity *other) {
    if (auto p = dynamic_cast<Player*>(other)) p->damage();
}
