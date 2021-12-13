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
    for (int i = -2; i <= 0; ++i) {
        Tail *t = queueSpawn(std::make_unique<Tail>());
        t->setPosition(getPosition() + i * getVelocity());
        t->setVelocity(getVelocity());
		t->setHead(this);
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
	makeTail();
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

void Snake::collide(Border b) { 
    if (b == Border::TOP || b == Border::BOTTOM) {
        reflectVelocityY();
    } else reflectVelocityX();
}

void Snake::pass(Entity *other) {
    if (auto p = dynamic_cast<Player*>(other)) p->damage();
}
