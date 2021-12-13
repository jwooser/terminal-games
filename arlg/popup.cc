#include "popup.h"
#include <cstdlib>
#include "staticSprite.h"
#include "point.h"
#include "player.h"
#include "enemyProj.h"

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
	setCollisionMask(0b0000000000000001);
	heal(4);
}

void Popup::shoot() {
    for (auto &d : bulletDirection) {
        EnemyProjectile *p = queueSpawn(std::make_unique<EnemyProjectile>());
        p->setPosition(getPosition() + d);
        p->setVelocity(d);
    }
	cooldown = 8;
}

void Popup::process(Game &game) {
	if (dead()) queueDestroy();
	if (!invulnState) {
        if (cooldown == 0) shoot();
    }
    if (cooldown > 0) --cooldown;
    if (game.getTick() % invulnTime == 0) {
        invulnState = !invulnState;
        toggleinvuln(invulnState);
        nextForm();
        invulnTime = rand() % 4 + 16;
    }
}

void Popup::collideX(Entity *other) { }

void Popup::collideY(Entity *other) { }

void Popup::collide(Border b) { }

void Popup::Entity(Entity *other) {
    if (auto p = dynamic_cast<Player*>(other)) p->damage();
}

