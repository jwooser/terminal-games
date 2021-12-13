#include "tail.h"
#include <cstdlib>
#include "staticSprite.h"
#include "point.h"
#include "player.h"

void Tail::setHead(Snake *h) { head = h; }

void Tail::initialize(Game &game) {
    addSprite(std::make_unique<StaticSprite>(Bitmap{'z'}));
    setBounds(Point{1,1});
    setCollisionLayer(0b0000000000000100);
}

void Tail::hit() {
    head->toggleinvuln(false);
    head->damage();
    head->toggleinvuln(true);
}

void Tail::process(Game &game) { }

void Tail::collideX(Entity *other) { }

void Tail::collideY(Entity *other) { }

void Tail::collide(Border b) { 
    if (b == Border::TOP || b == Border::BOTTOM) {
        reflectVelocityY();
    } else reflectVelocityX();
}

void Tail::pass(Entity *other) {
    if (auto p = dynamic_cast<Player*>(other)) p->damage();
}
