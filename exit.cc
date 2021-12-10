#include "healthPickup.h"
#include "staticSprite.h"
#include "player.h"

void Exit::initialize(Game &game) {
    addSprite(std::make_unique<StaticSprite>(Bitmap{'e'}));
    addSprite(std::make_unique<StaticSprite>(Bitmap{'E'}));
    setBounds(Point{1,1});
    setCollisionLayer(0b0000000000000000);
}
void Exit::process(Game &game) { }

void Exitp::collideX(Entity *other) { }

void Exit::collideY(Entity *other) { }

void Exit::collideB(Border b) { }

void Exit::openExit() {
    if (!open) {
        open = true;
        nextForm();
    }
}

void Exit::isExited() { return exited; }

void Exit::passEntity(Entity *other) {
    if ( open && auto p = dynamic_cast<Player*>(other)) {
        exited = true;
    }
}
