#include "popup.h"
#include <cstdlib>
#include "staticSprite.h"
#include "point.h"

const std::vector<Point> Popup::bulletDirection = {
    Point{0,-1},
    Point{0,1},
    Point{-1,0},
    Point{1,0}
};

void Popup::initialize(Game &game) {
    addSprite(std::make_unique<StaticSprite>(Bitmap{'_'}));
    addSprite(std::make_unique<StaticSprite>(Bitmap{'T'}));
    setBounds(Point{1,1});
    setCollisionLayer(0b0000000000000100);
	heal(4);
}

void Popup::shoot() {
    for (auto &d : bulletDirection) {
        EnemyProjectile *p = queueSpawn(std::make_unique<EnemyProjectile>());
        p->setPosition(getPosition() + d);
        p->setVelocity(d * 2);
    }
	cooldown = 2;
}

void Popup::process(Game &game) {
	if (dead()) queueDestroy();
	if (!invulnState) {
        if (cooldown == 0) shoot();
    }
    if (cooldown > 0) --cooldown;
    if (getTick() % invulnTime == 0) {
        invulnState = !invulnState;
        toggleinvuln(invulnState);
        nextform();
        invulnTime = rand() % 4 + 4;
    }
}

void Popup::collideX(Entity *other) { }

void Popup::collideY(Entity *other) { }

void Popup::collideB(Border b) { }

void Popup::passEntity(Entity *other) {
    if (auto p = dynamic_cast<Player*>(other)) p->damage();
}

