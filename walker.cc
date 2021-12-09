#include "walker.h"
#include <cstdlib>
#include "staticSprite.h"
#include "point.h"

const std::vector<Point> Walker::walkDirection = {
    Point{0,-1},
    Point{0,1},
    Point{-1,0},
    Point{1,0}
};

void Walker::initialize(Game &game) {
    addSprite(std::make_unique<StaticSprite>(Bitmap{2,2,'a'});
    setBounds(Point{2,2});
    setCollisionLayer(0b0000000000000100);
	heal(3);
}

void Fire::process(Game &game) {
	if (dead()) queueDestroy();
    else if (game.getTick() % walkTime == 0) {
        setVelocity(walkDirection[rand() % 4]);
        walkTime = rand() % 4 + 5
    }
}

void Fire::collideX(Entity *other) { }

void Fire::collideY(Entity *other) { }

void Fire::collideB(Border b) { }

void Fire::passEntity(Entity *other) {
    if (auto hp = dynamic_cast<Health*>(other)) hp->damage();
}
