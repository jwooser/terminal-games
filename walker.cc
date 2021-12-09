#include "walker.h"
#include <cstdlib>
#include "staticSprite.h"
#include "point.h"
#include "player.h"

const std::vector<Point> Walker::walkDirection = {
    Point{0,-1},
    Point{0,1},
    Point{-1,0},
    Point{1,0}
};

void Walker::initialize(Game &game) {
    addSprite(std::make_unique<StaticSprite>(Bitmap{2,2,'a'}));
    setBounds(Point{2,2});
    setCollisionLayer(0b0000000000000100);
	heal(3);
}

void Walker::process(Game &game) {
	if (dead()) queueDestroy();
    else if (game.getTick() % walkTime == 0) {
        changeDirection();
    }
}

void Walker::changeDirection() {
    setVelocity(walkDirection[rand() % 4]);
    walkTime = rand() % 4 + 5;
}

void Walker::collideX(Entity *other) { }

void Walker::collideY(Entity *other) { }

void Walker::collideB(Border b) {
    changeDirection();
}

void Walker::passEntity(Entity *other) {
    if (auto p = dynamic_cast<Player*>(other)) p->damage();
}
