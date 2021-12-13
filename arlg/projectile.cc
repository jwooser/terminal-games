#include "projectile.h"
#include "staticSprite.h"
#include "health.h"
#include "point.h"
#include "tail.h"

void Projectile::initialize(Game &game) {
    addSprite(std::make_unique<StaticSprite>(Bitmap{'o'}));
    setBounds(Point{1,1});
    setCollisionLayer(0b0000000000000010);
}

void Projectile::process(Game &game) { }

void Projectile::tryToHit(Entity *other) {
    if (auto hp = dynamic_cast<Health*>(other)) {
        hp->damage();
        queueDestroy();
    } else if (auto snaket = dynamic_cast<Tail*>(other)) {
        snaket->hit();
		queueDestroy();
    }
}

void Projectile::collideX(Entity *other) { }

void Projectile::collideY(Entity *other) { }

void Projectile::collide(Border b) {
    queueDestroy();
}

void Projectile::pass(Entity *other) {
    tryToHit(other);
}
