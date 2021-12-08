#include "projectile.h"
#include "staticSprite.h"
#include "health.h"
#include "point.h"

void Projectile::initialize(Game &game) {
    addSprite(std::make_unique<StaticSprite>(Bitmap{'o'}));
    setBounds(Point{1,1});
    setCollisionLayer(0b0000000000000110);
}

void Projectile::process(Game &game) { }

void Projectile::collideX(Entity *other) {
    if (auto hp = dynamic_cast<Health*>(other)) hp->damage();
    queueDestroy();
}

void Projectile::collideY(Entity *other) {
    if (auto hp = dynamic_cast<Health*>(other)) hp->damage();
    queueDestroy();
}

void Projectile::collideB(Border b) {
    queueDestroy();
}

void Projectile::passEntity(Entity *other) {
    if (auto hp = dynamic_cast<Health*>(other)) hp->damage();
    queueDestroy();
}
