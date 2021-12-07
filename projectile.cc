#include "projectile.h"

void Projectile::initialize(Game &game) {
    addSprite(std::make_unique<StaticSprite>(Bitmap{'p'}));
    setBounds(Point{1,1});
    setCollisionLayer(0b0000000000000010);
}
void Projectile::process(Game &game) { }
void Projectile::collideX(Entity *other) {
    queue_destroy();
}
void Projectile::collideY(Entity *other) {
    queue_destroy();
}
void Projectile::collideB(Border b) {
    queue_destroy();
}
void Projectile::passEntity(Entity *other) {
    queue_destroy();
}
