#include "snake.h"
#include <cstdlib>
#include "staticSprite.h"
#include "point.h"
#include "player.h"
#include "tail.h"

const std::vector<Point> Snake::slitherDirection = {
    Point{0,-1},
    Point{0,1},
    Point{-1,0},
    Point{1,0}
};

void Snake::makeTail() {
    for (int i = -3; i < 0; ++i) {
        Tail *t = queueSpawn(make_unique<Tail>());
        t->setPosition(getPosition() + i * getVelocity());
        t->setVelocity(getVelocity());
        tail.push_back(t);
    }
}

void Snake::initialize(Game &game) {
    addSprite(std::make_unique<StaticSprite>(Bitmap{'Z'}));
    setBounds(Point{1,1});
    setCollisionLayer(0b0000000000000100);
	heal(4);
    setVelocity(slitherDirection[rand() % 4]);
    toggleinvuln(true);
}

void Snake::process(Game &game) { 
    if (dead()) {
        for (auto &i : tail) {
            i->queueDestroy();
        }
        queueDestroy();
    }
}

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
