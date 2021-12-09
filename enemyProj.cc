#include "enemyProj.h"
#include "staticSprite.h"
#include "health.h"
#include "point.h"
#include "player.h"

void EnemyProjectile::initialize(Game &game) {
    addSprite(std::make_unique<StaticSprite>(Bitmap{'*'}));
    setBounds(Point{1,1});
    setCollisionLayer(0b0000000000000010);
    setCollisionMask(0b0000000000000001);
}

void EnemyProjectile::process(Game &game) { }

void EnemyProjectile::tryToHit(Entity *other) {
    if (auto hp = dynamic_cast<Player*>(other)) {
        hp->damage();
        queueDestroy();
    }
}

void EnemyProjectile::collideX(Entity *other) {
    tryToHit(other);
}

void EnemyProjectile::collideY(Entity *other) {
    tryToHit(other);
}

void EnemyProjectile::collideB(Border b) {
    queueDestroy();
}

void EnemyProjectile::passEntity(Entity *other) {
    tryToHit(other);
}
