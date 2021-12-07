#include "projectile.h"
#include "staticSprite.h"

void Projectile::initialize(Game &game) {
    addSprite(std::make_unique<StaticSprite>(Bitmap{'o'}));
    setBounds(Point{1,1});
    setCollisionLayer(0b0000000000000010);
}
void Projectile::process(Game &game) { }
void Projectile::collideX(Entity *other) {
    queueDestroy();
}
void Projectile::collideY(Entity *other) {
    queueDestroy();
}
void Projectile::collideB(Border b) {
    queueDestroy();
}
void Projectile::passEntity(Entity *other) {
    queueDestroy();
}
