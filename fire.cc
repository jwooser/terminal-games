#include "fire.h"

void Fire::initialize(Game &game) {
    addSprite(std::make_unique<AnimatedSprite>(vector<Bitmap>{
        Bitmap{'x'},
        Bitmap{'X'}
    }));
    setBounds(Point{1,1});
    setCollisionLayer(0b0000000000000010);
}
void Fire::process(Game &game) { }

void Fire::collideX(Entity *other) { }

void Fire::collideY(Entity *other) { }

void Fire::collideB(Border b) { }

void Fire::passEntity(Entity *other) {
    if (auto hp = dynamic_cast<Health*>(other)) hp->damage();
}
