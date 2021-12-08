#include "fire.h"
#include <vector>
#include <cstdlib>
#include "animatedSprite.h"
#include "healthPickup.h"

void Fire::initialize(Game &game) {
    addSprite(std::make_unique<AnimatedSprite>(vector<Bitmap>{
        Bitmap{'x'},
        Bitmap{'X'}
    }));
    setBounds(Point{1,1});
    setCollisionLayer(0b0000000000000010);
	heal(5);
}
void Fire::process(Game &game) {
	if (dead()) {
        if (rand()%5 == 0) {
            queueSpawn(std::make_unique<HealthPickup>())->setPosition(getPosition());
        }
        queueDestroy();
    }
}

void Fire::collideX(Entity *other) { }

void Fire::collideY(Entity *other) { }

void Fire::collideB(Border b) { }

void Fire::passEntity(Entity *other) {
    if (auto hp = dynamic_cast<Health*>(other)) hp->damage();
}
