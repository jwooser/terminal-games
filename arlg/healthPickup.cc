#include "healthPickup.h"
#include "staticSprite.h"
#include "player.h"

void HealthPickup::initialize(Game &game) {
    addSprite(std::make_unique<StaticSprite>(Bitmap{'h'}));
    setBounds(Point{1,1});
    setCollisionLayer(0b0000000000000000);
}
void HealthPickup::process(Game &game) { }

void HealthPickup::collideX(Entity *other) { }

void HealthPickup::collideY(Entity *other) { }

void HealthPickup::collide(Border b) { }

void HealthPickup::pass(Entity *other) {
    if (auto p = dynamic_cast<Health*>(other)) {
        p->heal();
        queueDestroy();
    }
}

